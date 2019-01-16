

#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {

        virtual void open(int port, ClientHandler cl)=0;

        virtual void stop()=0;
    };
}
#endif //MILESTONE2_SERVER_H
