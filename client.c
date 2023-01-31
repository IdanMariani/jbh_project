#include "general.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd[5];
    struct sockaddr_in servaddr;
    char buffer[5][MAX_BUFFER];
    int n;
    int i;
    int r;

    if (argc < 3)
    {
        printf("<enter this command to run client.>\n");
        printf("./client 1212 127.0.0.1\n");
        return 1;
    }

    /* Connect to the server */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[2]);
    servaddr.sin_port = htons(atoi(argv[1]));

    /* Send data to the server */
    while (1)
    {
        bool has_quit = false;
        int j = 5;

        puts("Enter up to 5 messages:");
        for (i = 0; i < j; i++)
        {
            fgets(buffer[i], MAX_BUFFER, stdin);

            if (strcmp(buffer[i], "quit\n") == 0)
            {
                has_quit = true;
                j = i;
                break;
            }

            if (strcmp(buffer[i], "\n") == 0)
            {
                printf("null query\n");
                i--;
            }

            if (strcmp(buffer[i], "send\n") == 0)
            {
                j = i;
                break;
            }
        }

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

        if (i == 5)
        {
            while (true)
            {
                printf("plz enter send or quit\n");
                fgets(buffer[i], MAX_BUFFER, stdin);
                if (strcmp(buffer[i], "send\n") == 0)
                {
                    break;
                }
                if (strcmp(buffer[i], "quit\n") == 0)
                {
                    has_quit = true;
                    j = i;
                    break;
                }
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

        for (int i = 0; i < j; i++)
        {
            r = 0;
            do
            {
                n = recv(sockfd[i], buffer[i] + r, MAX_LEN - r, 0);
                r += n;
            } while (n > 0);
            if (n < 0)
            {
                perror("Client error receiving data");
                break;
            }
            buffer[i][r] = '\0';
            printf("Client %d received:\n", i + 1);
            printf("%s\n", buffer[i]);

            close(sockfd[i]);
        }

        if (has_quit == true)
        {
            break;
        }
    }

    return 0;
}