#include "general.h"
#include "read_csv.h"
#include "validate.h"
#include "select_operator.h"
#include "option_menu.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_LEN 1024

Customer *list;
char buffer_send[MAX_LEN];
int new_list_length = 0;

void *conn_handler(void *args)
{
    int n;
    int new_sock = (int)args;

    n = recv(new_sock, buffer_send, MAX_LEN, 0);
    if (n < 0)
    {
        perror("Server error receiving data");
        goto exit;
    }
    buffer_send[n] = '\0';

    n = send(new_sock, buffer_send, strlen(buffer_send), 0);
    if (n < 0)
    {
        perror("Server error sending data");
        goto exit;
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
    print_list(list,new_list_length);


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