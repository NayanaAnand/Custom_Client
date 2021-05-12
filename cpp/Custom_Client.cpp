#include "Custom_Client.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr


PREPARE_LOGGING(Custom_Client_i)

Custom_Client_i::Custom_Client_i(const char *uuid, const char *label) :
    Custom_Client_base(uuid, label)
{
    // Avoid placing constructor code here. Instead, use the "constructor" function.

}

Custom_Client_i::~Custom_Client_i()
{
}

void Custom_Client_i::constructor()
{
    /***********************************************************************************
     This is the RH constructor. All properties are properly initialized before this function is called 
    ***********************************************************************************/
}

int Custom_Client_i::serviceFunction()
{
    char buff[MAX], *buf;
    int n;

	int sockfd, connfd;
        struct sockaddr_in servaddr, cli;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
                printf("socket creation failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully created..\n");
        bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
                printf("connection with the server failed...\n");
                exit(0);
        }
        else
                printf("connected to the server..\n");


    for (;;) {
            bzero(buff, sizeof(buff));
            //printf("Enter the string : ");
            n = 0;
	    buf = "I am Client component";
            //while ((buff[n++] = getchar()) != '\n');
            write(sockfd, buf, sizeof(buf));
            bzero(buff, sizeof(buff));
            read(sockfd, buff, sizeof(buff));
            LOG_INFO(Custom_Client_i, "Data Recieved");
            printf("From Server : %s", buff);
            if ((strncmp(buff, "exit", 4)) == 0) {
                    printf("Client Exit...\n");
                    break;
            }
    }

	close(sockfd);
	
	return 0;
}

