
#include "DataServerReader.h"

using namespace std;

struct Thread_data {
    int port;
    int hz;
};

void *DataServerReader::openServer(void *arg) {

    struct Thread_data* thread_data;
    thread_data = (Thread_data*) arg;

    int hz= thread_data->hz;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock) {
        printf("Error creating socket\n");
        exit(1);
    }
    struct sockaddr_in my_addr = {0};
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(thread_data->port);
    int result = bind(sock, (struct sockaddr *) &my_addr, sizeof(my_addr));
    if (-1 == result) {
        printf("Bind error\n");
        exit(1);
    }
    result = listen(sock, 5);
    if (-1 == result) {
        printf("listen error");
        exit(1);
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
        splitMessageByComma(v,buffer);

        //call datamanager fot updating the map with the v message
        //....

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        //sleep(100);
    }

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

void DataServerReader::createServerAndThread(int port, int hz) {

    //the thread
    pthread_t t1;

    //struct of information to be sent to the function

    //An instance of the thread data
    struct Thread_data *thread_data;
    thread_data = new Thread_data();
    thread_data->port=port;
    thread_data->hz =hz;

    pthread_create(&t1, nullptr, &openServer,thread_data);
    pthread_join(t1, nullptr);
}



