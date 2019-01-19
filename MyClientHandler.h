

#ifndef MILESTONE2_MyClientHandler_H
#define MILESTONE2_MyClientHandler_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <vector>


class MyClientHandler : public ClientHandler {
private:
    CacheManager<string, string> *cm;
    Solver<string, string> *solver;
public:
    MyClientHandler(CacheManager<string, string> *cm,
                    Solver<string, string> *solver) : cm(cm), solver(solver) {};

    virtual void handleClient(int socket);

};


#endif //MILESTONE2_MyClientHandler_H
