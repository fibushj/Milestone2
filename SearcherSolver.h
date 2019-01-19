/* This is an object adapter */

#ifndef MILESTONE2_SEARCHERSOLVER_H
#define MILESTONE2_SEARCHERSOLVER_H

#include "Solver.h"
#include "ISearcher.h"

class SearcherSolver : public Solver<string, string> {
    virtual string solve(string problem);

public:
    virtual ~SearcherSolver(){};
};


#endif //MILESTONE2_SEARCHERSOLVER_H
