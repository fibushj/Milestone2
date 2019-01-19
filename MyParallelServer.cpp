
#include "MyParallelServer.h"
#include <vector>
#include <thread>
#include <strings.h>

using namespace std;

void MyParallelServer::open(int port, ClientHandler *cl) {
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
    bool stopLoop = false;
    bool firstClient = true;
    while (!stopLoop) {
        int new_sock = accept(s, (struct sockaddr *) &client, &clilen);
        if (firstClient) {
            timeout.tv_sec = 1;
            setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout,
                       sizeof(timeout));
            firstClient = false;
        }
        if (new_sock < 0) {

            if (errno == EWOULDBLOCK) {
                stopLoop = true;
            } else {
                perror("other error");
                exit(3);
            }
        } else {
            // cl.handleClient(new_sock);
            thread handleClientThread(MyParallelServer::handleClientInThread,
                                      new_sock, cl);
            allThreads.push_back(move(handleClientThread));

        }
    }

    int ab = 1; //TODO delete
    for (auto &t : allThreads) {
        cout << "joined thread " << ab << endl;
        ab++;
        t.join();
    }

    stop(s);
}

void MyParallelServer::stop(int socket) {
    close(socket);

}

void MyParallelServer::handleClientInThread(int socket, ClientHandler *cl) {
    cout << "thread1" << endl;
    cl->handleClient(socket);
}
