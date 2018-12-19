
#include "DataServerReader.h"

using namespace std;
#define MAXPACKETSIZE 256

int DataServerReader::openServer(int port, int hz) {


    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock) {
        printf("Error creating socket\n");
        return 1;
    }
    struct sockaddr_in my_addr = {0};
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(port);
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


    while (true) {
        char buffer[256];
        int n;
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);

        //Split the message by comma
        vector <string> v;
        this->splitMessageByComma(v,buffer);

        //call datamanager fot updating the map with the v message
        //....



        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
    return 0;
}
/**
 * Splits a string line by the delimeter ','
 * @param elems A vector of the seperated line to be updated
 * @param line the line to be seperated
 */
void DataServerReader::splitMessageByComma(std::vector<std::string> &elems, char line []) {

    char delim = ',';
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item));
    }

}
