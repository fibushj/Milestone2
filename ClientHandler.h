

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H
#include <string>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int socket)=0;
};

#endif //MILESTONE2_CLIENTHANDLER_H
