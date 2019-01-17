

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <vector>


class MyTestClientHandler : public ClientHandler {
private:
    //TODO: try to remove <string, string>
    CacheManager<string, string> *cm;
    Solver<string, string> *solver;
public:
    MyTestClientHandler(CacheManager<string, string> *cm,
                        Solver<string, string> *solver);

    virtual string handleClient(string input);

};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
