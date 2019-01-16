//
// Created by Jonathan on 13/01/2019.
//

#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <unordered_map>

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
private:
    string fileName;
    unordered_map<string, string> cache;

public:
    FileCacheManager(string fileName);

    ~FileCacheManager();

    virtual bool doesSolutionExist(string problem);

    virtual string getSolution(string problem);

    virtual void saveSolution(string problem, string solution);

    void saveCacheToFile();

    void loadCacheFromFile();
};


#endif //MILESTONE2_FILECACHEMANAGER_H
