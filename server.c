#include "general.h"
#include "read_csv.h"
#include "validate.h"
#include "select_operator.h"
#include "option_menu.h"
#include "user_input.h"
#include "server.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

Customer *list;
int new_list_length;
int n;
int new_sock;

void *conn_handler(void *args)
{
    new_sock = (int)args;
    enum Compiler comp = COMP_SERVER;
    char buffer_send[MAX_BUFFER];

    n = recv(new_sock, buffer_send, MAX_BUFFER, 0);
    if (n < 0)
    {
        perror("Server error receiving data");
        goto exit;
    }
    buffer_send[n] = '\0';

    char new_buffer[MAX_BUFFER] = {0};
    char portion2;
    char portion3[MAX_BUFFER];
    bool set_flag = false;
    bool error_input = false;

    strcpy(new_buffer, buffer_send);
    switch_to_lower(new_buffer);

    if (strstr(new_buffer, "set"))
    {
        set_flag = true;
        goto set_option;
    }

    if (strcmp(new_buffer, "print") == 0)
    {
        print_list(list, new_list_length, cb_print_server);
        goto exit;
    }

    error_handle(new_buffer, &portion2, portion3, &error_input, comp);
    if (error_input == true)
    {
        goto exit;
    }

    select_option_menu(list, &new_list_length, new_buffer, portion2, portion3, comp);

set_option:
    if (set_flag == true)
    {
        bool error_file_open = false;
        list = set_option_menu(list, &new_list_length, new_buffer, &error_file_open, comp);
        if (error_file_open)
        {
            goto exit;
        }
        set_flag = false;
    }

exit:
    error_input = false;
    close(new_sock);
    return NULL;
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    if (argc < 3)
    {
        printf("<enter this command to run server.>\n");
        printf("./server 1212 customers.txt\n");
        return 1;
    }

    Customer *customers;
    FILE *file;

    new_list_length = 0;
    file = fopen(argv[2], "r");

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
    print_list(list, new_list_length, cb_print_local);

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
