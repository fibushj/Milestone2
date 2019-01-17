

#ifndef MILESTONE2_MyClientHandler_H
#define MILESTONE2_MyClientHandler_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <vector>


class MyClientHandler : public ClientHandler {
private:
    //TODO: try to remove <string, string>
    CacheManager<string, string> *cm;
    Solver<string, string> *solver;
public:
    MyClientHandler(CacheManager<string, string> *cm,
                        Solver<string, string> *solver);

    virtual string handleClient(int socket);

};


#endif //MILESTONE2_MyClientHandler_H
