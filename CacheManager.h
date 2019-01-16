//
// Created by Jonathan on 13/01/2019.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H

template<class Problem, class Solution>
class CacheManager {
public:
    virtual bool doesSolutionExist(Problem problem)=0;

    virtual Solution getSolution(Problem problem)=0;

    virtual void saveSolution(Problem problem, Solution solution)=0;

    virtual ~CacheManager() {};
};


#endif //MILESTONE2_CACHEMANAGER_H
