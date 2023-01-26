#include "general.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LEN 1024

int main(int argc, char **argv)
{
    int sockfd[5];
    struct sockaddr_in servaddr;
    char buffer[5][MAX_LEN];
    int n;
    int i;

    if (argc < 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    /* Connect to the server */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(atoi(argv[1]));

    /* Send data to the server */
    while (1)
    {
        bool has_quit = false;
        int j = 5;

        /* Create a sockets */
        for (i = 0; i < j; i++)
        {
            sockfd[i] = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd[i] < 0)
            {
                perror("Error creating socket");
                return 1;
            }
            if (connect(sockfd[i], (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
            {
                perror("Error connecting");
                return 1;
            }
        }

        puts("Enter a 5 messages:");
        for (i = 0; i < j; i++)
        {
            fgets(buffer[i], MAX_LEN, stdin);
            if (strcmp(buffer[i], "quit\n") == 0)
            {
                has_quit = true;
                j = i + 1;
                break;
            }
        }

        for (i = 0; i < j; i++)
        {
            n = send(sockfd[i], buffer[i], strlen(buffer[i]) - 1, 0);
            if (n < 0)
            {
                perror("Client error sending data");
                return 1;
            }
        }

        for (i = 0; i < j; i++)
        {
            n = recv(sockfd[i], buffer[i], MAX_LEN, 0);
            if (n < 0)
            {
                perror("Client error receiving data");
                return 1;
            }
            buffer[i][n] = '\0';
            printf("Client %d received: %s\n", i, buffer[i]);

            close(sockfd[i]);
        }

        if (has_quit == true)
        {
            break;
        }
    }

    return 0;
}