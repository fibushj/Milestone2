
#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H

#include "CommonSearcher.h"
#include "PriorityQueue.h"
#include <iostream>
template<class T>
class AStar : public CommonSearcher<T> {
private:

    PriorityQueue<T> open;


public:

    virtual string search(ISearchable<T> &searchable) {
        State<T> *initialState = searchable.getInitialState();
        initialState->setHeuristicCost(calculateHeuristicOfState(initialState,
                                                                 searchable.getGoalEntry()));
        open.push(initialState);
        while (open.size() > 0) {
            State<T> *n = popOpenList();
//            std::cout << n->getStateDescriptor().getX() << ","
//                      << n->getStateDescriptor().getY() << " " << n->getHeuristicCost()
//                      << endl;
            CommonSearcher<T>::closed.insert(n);
            if (searchable.isGoalState(n)) {
                return CommonSearcher<T>::backtracePath(n);
            }
            set<State<T> *> successors = searchable.getAllPossibleStates(n);
            for (auto &state : successors) {
                bool isInClosed =  CommonSearcher<T>::doesClosedContainState(state);
                if (isInClosed) {
                    continue;
                }
                double heuristicCost = calculateHeuristicOfState(state,
                                                                 searchable.getGoalEntry());
                state->setHeuristicCost(heuristicCost);
                if (!open.contains(state)) {
                    open.push(state);
                } else {
                    open.AdjustPriorityIfNeeded(state, true);
                }
            }
        }
        return "-1";

    }

    virtual unsigned long long int openListSize() {
        return open.size();
    }


    virtual ~AStar() {
    }

private:
    State<T> *popOpenList() {
        CommonSearcher<T>::evaluatedNodes++;
        return open.pop(true);
    }

private:
    double calculateHeuristicOfState(State<T> *state, T goalEntry) {
        int deltaX = goalEntry.getX() - state->getStateDescriptor().getX();
        int deltaY = goalEntry.getY() - state->getStateDescriptor().getY();
        if (deltaX < 0) {
            deltaX = -deltaX;
        }
        if (deltaY < 0) {
            deltaY = -deltaY;
        }
        /*in case it's the start state - ignoring its cost since we're already
         * there */
        if (state->getPrecedingState() == nullptr) {
            return deltaX + deltaY;
            // in any other case, taking into account the state's cost
        } else {
            return state->getCost() + deltaX + deltaY;
        }

    }
};

#endif //MILESTONE2_ASTAR_H
