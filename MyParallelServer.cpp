/*

#include "MySerialServer.h"
#define BUFFER_SIZE 4096
using namespace std;

virtual void MySerialServer::start(struct sockaddr *client, socklen_t *clilen) {
    int new_sock;
    char buffer[BUFFER_SIZE];
    while (true) {
        new_sock = accept(this->socket, client, clilen);
        if (new_sock < 0) {
            if (errno == EWOULDBLOCK) {
                break;
            } else {
                perror("other error");
                exit(3);
            }
        } else {
            this->cl.handleClient();
            close(new_sock);
        }
    }
    stop();
}
*/