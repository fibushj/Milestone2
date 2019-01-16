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

    virtual State<T> *search(ISearchable<T> &searchable) {
        open.push(searchable.getInitialState());
        while (open.size() > 0) {
            State<T> *n = popOpenList();
            CommonSearcher<T>::closed.insert(n);
            if (searchable.isGoalState(n)) {
                std::cout<<"Matrix " << numberMatrix++ <<": "<<CommonSearcher<T>::evaluatedNodes<< "nodes evaluated\n" <<endl;
                return n;
            }
            set<State<T> *> successors = searchable.getAllPossibleStates(n);
            for (auto &state : successors) {
                bool isInClosed = doesClosedContainsState(state);
                if (!isInClosed && !open.contains(state)) {
                    open.push(state);
                } else {
                    if (!isInClosed) {
                        open.AdjustPriorityIfNeeded(state);
                    }
                }
            }
        }
    }

    bool doesClosedContainsState(State<T> *desiredState) {
        for (auto &state: CommonSearcher<T>::closed) {
            if (*desiredState == *state) {
                return true;
            }
        }
        return false;

    }

    virtual void resetData() {
        for (auto &state : CommonSearcher<T>::allStatesCreated) {
            delete state;
        }
        CommonSearcher<T>::allStatesCreated.clear();
        CommonSearcher<T>::closed.clear();
        CommonSearcher<T>::evaluatedNodes = 0;
        
    }

    static int numberMatrix;
};

#endif //MILESTONE2_BESTFIRSTSEARCH_H
