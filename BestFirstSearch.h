
#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "CommonSearcher.h"
#include "PriorityQueue.h"
#include <iostream>

template<class T>
class BestFirstSearch : public CommonSearcher<T> {
private:

    PriorityQueue<T> open;

    State<T> *popOpenList() {
        CommonSearcher<T>::evaluatedNodes++;
        /*the false values indicates that the states in the priority queue are
         * sorted by the heuristic cost */
        return open.pop(false);
    }

public:

    virtual string search(ISearchable<T> &searchable) {
        open.push(searchable.getInitialState());
        while (open.size() > 0) {
            State<T> *n = popOpenList();
            CommonSearcher<T>::closed.insert(n);
            if (searchable.isGoalState(n)) {
                return CommonSearcher<T>::backtracePath(n);
            }
            set<State<T> *> successors = searchable.getAllPossibleStates(n);
            for (auto &state : successors) {
                bool isInClosed = CommonSearcher<T>::doesClosedContainState(
                        state);
                if (!isInClosed && !open.contains(state)) {
                    open.push(state);
                } else {
                    if (!isInClosed) {
                        open.AdjustPriorityIfNeeded(state, false);
                    }
                }
            }
        }
        return "-1";
    }

    virtual unsigned long long int openListSize() {
        return open.size();
    }



    virtual ~BestFirstSearch() {
    }

};

#endif //MILESTONE2_BESTFIRSTSEARCH_H
