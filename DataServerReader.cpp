#include "DataServerReader.h"
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <string>
#include <strings.h>

using namespace std;
#define PORT 5400
#define MAXPACKETSIZE 256

void openserver(int port, int hz) {





    int main() {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (-1 == sock) {
            printf("Error creating socket\n");
            return 1;
        }
        struct sockaddr_in my_addr = {0};
        my_addr.sin_family = AF_INET;
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        my_addr.sin_port = htons(PORT);
        int result = bind(sock, (struct sockaddr *) &my_addr, sizeof(my_addr));
        if (-1 == result) {
            printf("Bind error\n");
            return 2;
        }
        result = listen(sock, 5);
        if (-1 == result) {
            printf("listen error");
            return 3;
        }
        struct sockaddr_in clientAddress = {0};

        printf("waiting for connection...\n");
        socklen_t sosize = sizeof(clientAddress);
        int newsockfd = accept(sock, (struct sockaddr *) &clientAddress, &sosize);
        string str = inet_ntoa(clientAddress.sin_addr);

        /*
        char msg[MAXPACKETSIZE] = {0};
        result = recv(newsockfd, msg, MAXPACKETSIZE, 0);
        if (-1 == result) {
            printf("error receiveing\n");
            close(newsockfd);
            close(sock);
            return 4;
        }
        msg[MAXPACKETSIZE - 1] = '\0';
        printf("msg: %s\n", msg);
        printf("Great Success\n");
*/
        /* If connection is established then start communicating */
        while(true) {
            char buffer[256];
            int n;
            bzero(buffer, 256);
            n = read(newsockfd, buffer, 255);

            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("Here is the message: %s\n", buffer);

            /* Write a response to the client */
            n = write(newsockfd, "I got your message", 18);

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
        return 0;
    }
}
