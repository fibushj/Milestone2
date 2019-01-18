
#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H

#include "Server.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>

class MyParallelServer : public server_side::Server {


public:


    virtual void open(int port, ClientHandler *cl);

    virtual void stop(int socket);

    static void handleClientInThread(int socket, ClientHandler *cl);
};


#endif //MILESTONE2_MYPARALLELSERVER_H
