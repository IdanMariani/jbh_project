#include "general.h"
#include "read_csv.h"
#include "validate.h"
#include "select_operator.h"
#include "option_menu.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

Customer *list;
char buffer_send[MAX_BUFFER];
int new_list_length;
int n;
int new_sock;

void *conn_handler(void *args)
{
    new_sock = (int)args;
    enum Compiler comp = COMP_SERVER;
    n = recv(new_sock, buffer_send, MAX_BUFFER, 0);
    if (n < 0)
    {
        perror("Server error receiving data");
        goto exit;
    }
    buffer_send[n] = '\0';

    char new_buffer[MAX_BUFFER] = {0};
    char temp_buffer[MAX_BUFFER] = {0};

    char *select_menu[] = {"select first name", "select last name", "select id", "select phone", "select debt", "select date"};
    char *operator_menu[] = {"!=", "=", "<", ">"};
    char select_dilimiter[] = "=<>";
    char operator_delimiter[] = "-abcdefghijklmnopqrstuvwxyz0123456789";

    bool set_flag = false;

    strcpy(new_buffer, buffer_send);
    strcpy(temp_buffer, buffer_send);
    switch_to_lower(new_buffer);

    // if user enter "set" on input we go for diffrent section with diffrent validation tests
    if (strstr(new_buffer, "set"))
    {
        set_flag = true;
        goto set_option;
    }

    if (strcmp(new_buffer, "quit") == 0)
    {
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            goto exit;
        }
        free(list);
        goto exit;
    }

    if (strcmp(new_buffer, "print") == 0)
    {
        print_list(list, new_list_length, comp);
        goto exit;
    }

    // we start checking first catgory
    char *portion1 = strtok(new_buffer, select_dilimiter);

    if (portion1 == NULL)
    {
        strcpy(buffer_send, "Error first args");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            goto exit;
        }
        goto exit;
    }

    char *portion3 = strtok(NULL, "\0");
    char *remove_char = strtok(portion1, "!");

    bool select_check_counter = false;
    int select_args = 0;
    for (int i = 0; i < ARR_SIZE(select_menu); i++)
    {
        if (strcmp(portion1, select_menu[i]) == 0)
        {
            select_check_counter = true;
            select_args = i;
            bool error_spaces = spaces_count(portion1, select_args);
            if (error_spaces)
            {
                strcpy(buffer_send, "Error first args");
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    goto exit;
                }
                goto exit;
            }
        }
    }

    if (select_check_counter == false)
    {
        strcpy(buffer_send, "Error first args");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            goto exit;
        }
        goto exit;
    }

    // we start checking second catgory (operator)
    bool select_portion2_counter = false;
    char *check_portion2_cut = NULL;
    char portion2 = '\0';
    bool compere_valid = false;
    for (int i = 0; i < ARR_SIZE(operator_menu); i++)
    {
        if ((check_portion2_cut = strstr(temp_buffer, operator_menu[i])))
        {
            select_portion2_counter = true;
            check_portion2_cut = strtok(check_portion2_cut, operator_delimiter);
            for (int i = 0; i < ARR_SIZE(operator_menu); i++)
            {
                if (strcmp(check_portion2_cut, operator_menu[i]) == 0)
                {
                    compere_valid = fill_portion2_operator(i, &portion2);
                    if (compere_valid)
                    {
                        break;
                    }
                }
            }

            if (compere_valid == true)
            {
                break;
            }
        }
    }

    // we checking last catgory
    if (select_portion2_counter == true && portion3 == NULL)
    {
        strcpy(buffer_send, "Error third args");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            goto exit;
        }
        goto exit;
    }

    if (select_portion2_counter == false || compere_valid == false)
    {
        strcpy(buffer_send, "Error second args");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            goto exit;
        }
        goto exit;
    }

    if (!check_all_validation_select(portion3, select_args))
    {
        strcpy(buffer_send, "Error at validation");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            goto exit;
        }
        goto exit;
    }

    // if we pass all 3 catgory valid input we reach select option menu
    select_option_menu(list, &new_list_length, new_buffer, portion2, portion3, comp);

set_option:
    if (set_flag == true)
    {
        bool error_file_open = false;
        list = set_option_menu(list, &new_list_length, new_buffer, &error_file_open,comp);
        if (error_file_open)
        {
            goto exit;
        }
        set_flag = false;
    }

exit:
    close(new_sock);
    return NULL;
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    if (argc < 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    Customer *customers;
    FILE *file;

    new_list_length = 0;
    file = fopen("customers.TXT", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int max_lines = 1;
    find_max_lines(file, &max_lines);
    customers = malloc(sizeof(Customer) * max_lines);

    // 0 mean we have an error reading the csv file /so we return 1 to stop
    if (read_from_csv_file(file, customers) == 0)
    {
        return 1;
    }

    // create new list array from csv

    list = count_debt_and_init_array(customers, max_lines, &new_list_length);
    if (list == NULL)
    {
        return 1;
    }

    // free old list from csv
    free(customers);
    sort_list(list, new_list_length);
      
    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    /* Bind the socket to a specific port */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error binding socket");
        return 1;
    }

    if (listen(sockfd, 5) < 0)
    {
        perror("Error listenning");
        return 1;
    }

    /* Receive data from clients */
    while (1)
    {
        pthread_t tid;
        int new_sock = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
        if (new_sock < 0)
        {
            perror("accept failed");
            return 1;
        }

        pthread_create(&tid, NULL, conn_handler, (void *)new_sock);
        pthread_join(tid, NULL);
    }

    return 0;
}