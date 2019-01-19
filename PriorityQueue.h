
#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include "State.h"
#include <vector>

using namespace std;

template<class T>
class PriorityQueue {
private:
    vector<State<T> *> states;

public:
    unsigned long long int size() { return states.size(); }

    bool contains(State<T> *desiredState);

    void push(State<T> *state);

    State<T> *pop(bool isHeuristic);

    void AdjustPriorityIfNeeded(State<T> *newState, bool isHeuristic);
};

template<class T>
bool PriorityQueue<T>::contains(State<T> *desiredState) {
    for (auto &state: states) {
        if (*state == *desiredState) {
            return true;
        }
    }
    return false;
}

template<class T>
void PriorityQueue<T>::push(State<T> *state) {
    states.push_back(state);
}

template<class T>
State<T> *PriorityQueue<T>::pop(bool isHeuristic) {
    if (states.size() == 0) {
        throw "No elements in queue";
    }
    State<T> *minimalState = states[0];
    int minimalStateIndex, index;
    minimalStateIndex = index = 0;
    if (!isHeuristic) {
        for (auto &state: states) {
            if (state->getCost() < minimalState->getCost()) {
                minimalState = state;
                minimalStateIndex = index;
            }
            ++index;
        }
    }
    else {
        for (auto &state: states) {
            if (state->getHeuristicCost() < minimalState->getHeuristicCost()) {
                minimalState = state;
                minimalStateIndex = index;
            }
            ++index;
        }
    }
    states.erase(states.begin() + minimalStateIndex);
    return minimalState;
}

template<class T>
void
PriorityQueue<T>::AdjustPriorityIfNeeded(State<T> *newState, bool isHeuristic) {
    for (auto &state: states) {
        if (*state == *newState) {
            if (newState->getCost() < state->getCost()) {
                if (!isHeuristic) {
                    state = newState;
                } else {
                    if (newState->getHeuristicCost() <
                        state->getHeuristicCost()) {
                        state = newState;
                    }
                }
            }
            return;
        }
    }
}

#endif //MILESTONE2_PRIORITYQUEUE_H
