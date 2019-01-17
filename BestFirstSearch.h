//
// Created by Jonathan on 15/01/2019.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "CommonSearcher.h"
#include "PriorityQueue.h"
#include <iostream>

template<class T>
class BestFirstSearch : public CommonSearcher<T> {
private:

    PriorityQueue<T> open;

protected:
    State<T> *popOpenList() {
        CommonSearcher<T>::evaluatedNodes++;
        return open.pop();
    }

public:
    BestFirstSearch() : CommonSearcher<T>() {
    }

    virtual int openListSize() {
        return open.size();
    }

    virtual string search(ISearchable<T> &searchable) {
        open.push(searchable.getInitialState());
        while (open.size() > 0) {
            State<T> *n = popOpenList();
            std::cout<<n->getStateDescriptor().getX() << "," <<n->getStateDescriptor().getY()<< " " <<n->getCost()<<endl;
            CommonSearcher<T>::closed.insert(n);
            if (searchable.isGoalState(n)) {
                std::cout<<"Matrix " << numberMatrix++ <<": "<<CommonSearcher<T>::evaluatedNodes<< "nodes evaluated\n" <<endl;
                return CommonSearcher<T>::backtracePath(n);
            }
            set<State<T> *> successors = searchable.getAllPossibleStates(n);
            for (auto &state : successors) {
                bool isInClosed = doesClosedcontainsState(state);
                if (!isInClosed && !open.contains(state)) {
                    open.push(state);
                } else {
                    if (!isInClosed) {
                        open.AdjustPriorityIfNeeded(state);
                    }
                }
            }
        }
        return "-1";
    }

    bool doesClosedcontainsState(State<T> *desiredState) {
        for (auto &state: CommonSearcher<T>::closed) {
            if (*desiredState == *state) {
                return true;
            }
        }
        return false;

    }

    virtual void clearData() {
        for (auto &state : CommonSearcher<T>::allStatesCreated) {
            delete state;
        }
        CommonSearcher<T>::allStatesCreated.clear();
        CommonSearcher<T>::closed.clear();
        CommonSearcher<T>::evaluatedNodes = 0;
    }

    virtual ~BestFirstSearch() {
        clearData();
    }

    static int numberMatrix;
};

#endif //MILESTONE2_BESTFIRSTSEARCH_H
