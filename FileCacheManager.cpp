//
// Created by Jonathan on 13/01/2019.
//

#include "FileCacheManager.h"
#include <fstream>


FileCacheManager::FileCacheManager(string fileName) {
    this->fileName = fileName;
    loadCacheFromFile();
}

FileCacheManager::~FileCacheManager() {
    saveCacheToFile();
}


bool FileCacheManager::doesSolutionExist(string problem) {
    return cache.count(problem) == 1;
}

string FileCacheManager::getSolution(string problem) {
    return cache.at(problem);
}

void FileCacheManager::saveSolution(string problem, string solution) {
    cache[problem] = solution;
}


void FileCacheManager::saveCacheToFile() {
    ofstream ofs;
    ofs.open(this->fileName);
    if (ofs.good()) {
        for (auto &it : cache) {
            //writing both the problem and the corresponding solution to the file
            ofs << it.first;
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
            problem+="\n";
            cache[problem] = solution;
        }
    }
    ifs.close();
}
