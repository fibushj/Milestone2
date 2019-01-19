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
        int main(int port) {
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
            return 0;

        }
    };
}

int main(int argc, char *argv[]) {

//    FileCacheManager fileCacheManager("cache.txt");
//    bool b=fileCacheManager.doesSolutionExist("hi\n");
//    fileCacheManager.saveSolution("hi\n", "bye");
//    string s=fileCacheManager.getSolution("hi\n");
    string str =
            "1, 2, 3\n3, 1, 89\n4, 3,4\n0,0\n 2,2\nend\n";
    ISearchable<MatrixEntry> *a = MatrixFactory::GenerateMatrix(str);
    AStar<MatrixEntry> best;
    cout << best.search(*a) << endl;
//    best.clearData();
//    best.search(*a);

    boot::Main m;
    return m.main(stoi(argv[1]));
}
