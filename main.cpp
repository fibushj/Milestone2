#include <iostream>
#include "AStar.h"
#include "MatrixFactory.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"
#include "SearcherSolver.h"
#include "MyParallelServer.h"


namespace boot {
    class Main {
    public:
        void main(int port) {
            FileCacheManager *fileCacheManager = new FileCacheManager(
                    "cache.txt");
            SearcherSolver *solver = new SearcherSolver();
            MyClientHandler *clientHandler = new MyClientHandler(
                    fileCacheManager, solver);
            MyParallelServer myParallelServer;
            myParallelServer.open(port, clientHandler);
            delete fileCacheManager;
            delete solver;
            delete clientHandler;
        }
    };
}

int main(int argc, char *argv[]) {
    boot::Main m;
    m.main(stoi(argv[1]));
    return 0;
}
