
#ifndef MILESTONE2_COMMONSERVER_H
#define MILESTONE2_COMMONSERVER_H
#include "Server.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>

class CommonServer : public server_side::Server{
protected:
    int socket;
    ClientHandler cl;
public:


    virtual void open(int port, ClientHandler cl);

    virtual void stop();
};


#endif //MILESTONE2_COMMONSERVER_H
