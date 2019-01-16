
#ifndef MILESTONE2_COMMONSEARCHER_H
#define MILESTONE2_COMMONSEARCHER_H

#include "ISearcher.h"

template<class T>
class CommonSearcher : public ISearcher<T> {

protected:
    set<State<T> *> closed;
    set<State<T>*> allStatesCreated;
    int evaluatedNodes;

public:
    CommonSearcher() {
        evaluatedNodes = 0;
    }

    virtual int openListSize()=0;

    virtual int getNumberOfNodesEvaluated() final { return evaluatedNodes; }

    virtual State<T> *search(ISearchable<T> &searchable)=0;

    virtual void resetData()=0; //TODO


protected:
    virtual State<T> *popOpenList()=0;

};

#endif //MILESTONE2_COMMONSEARCHER_H
