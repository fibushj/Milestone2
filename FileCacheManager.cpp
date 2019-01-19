
#include "FileCacheManager.h"
#include <fstream>
#include "StaticCollection.h"

FileCacheManager::FileCacheManager(string fileName) {
    this->fileName = fileName;
    loadCacheFromFile();
}

FileCacheManager::~FileCacheManager() {
    saveCacheToFile();
}


bool FileCacheManager::doesSolutionExist(string problem) {
    StaticCollection::swapEndlineWithDollar(problem);
    StaticCollection::m.lock();
    bool result = cache.count(problem) == 1;
    StaticCollection::m.unlock();
    return result;
}

string FileCacheManager::getSolution(string problem) {
    StaticCollection::swapEndlineWithDollar(problem);
    StaticCollection::m.lock();
    string &solution = cache.at(problem);
    StaticCollection::m.unlock();
    return solution;
}

void FileCacheManager::saveSolution(string problem, string solution) {
    StaticCollection::swapEndlineWithDollar(problem);
    StaticCollection::m.lock();
    cache[problem] = solution;
    StaticCollection::m.unlock();
}


void FileCacheManager::saveCacheToFile() {
    ofstream ofs;
    ofs.open(this->fileName);
    if (ofs.good()) {
        for (auto &it : cache) {
            //writing the problem and the corresponding solution to the file
            ofs << it.first << endl;
            ofs << it.second << endl;
        }
    }
    ofs.close();
}

void FileCacheManager::loadCacheFromFile() {
    ofstream ofs;
    // if the file exists, just opening it. If it doesn't exist, creating it */
    ofs.open(this->fileName, ios::app);
    /* the mere use of the above operation was to create the file in case it's
     * the first time */
    ofs.close();

    ifstream ifs;
    ifs.open(this->fileName, ios::app);
    string problem, solution;
    if (ifs.good()) {
        while (getline(ifs, problem)) {
            getline(ifs, solution);
            StaticCollection::swapEndlineWithDollar(problem);
            cache[problem] = solution;
        }
    }
    ifs.close();
}
