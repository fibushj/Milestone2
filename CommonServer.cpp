/*
#include "CommonServer.h"


using namespace std;

void CommonServer::open(int port, ClientHandler cl) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr * ) & serv, sizeof(serv)) < 0) {
        cerr << "Bad!" << endl;
    }

    int new_sock;
    listen(s, SOMAXCONN);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));


    this->socket = s;
    this->cl = cl;

    start((struct sockaddr *) &client, &clilen);
}

void CommonServer::stop() {
    close(this->socket);

}
*/