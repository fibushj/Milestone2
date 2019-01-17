
#include "CommonServer.h"
#include <vector>
#include <thread>

using namespace std;

void CommonServer::open(int port, ClientHandler cl) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv, client;
    bzero((char *) &serv, sizeof(serv));
    bzero((char *) &client, sizeof(client));
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr * ) & serv, sizeof(serv)) < 0) {
        cerr << "Bad!" << endl;
    }

    listen(s, SOMAXCONN);
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    vector<thread> allThreads;
    bool stop = false;
    bool firstClient=true;
    while (!stop) {
        new_sock = accept(s, client, clilen);
        if (firstClient) {
            timeout.tv_sec = 1;
            setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
            firstClient=false;
        }
        if (new_sock < 0) {
            if (errno == EWOULDBLOCK) {
                stop = true;
            } else {
                perror("other error");
                exit(3);
            }
        } else {
            thread handleClientThread;
            allThreads.push_back(handleClientThread);
            handleClientThread = thread(cl.handleClient, new_sock);
        }
    }
    //TODO: join threads (delete?)
    stop();
}

void CommonServer::stop() {
    close(this->socket);

}
