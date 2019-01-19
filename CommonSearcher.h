
#ifndef MILESTONE2_COMMONSEARCHER_H
#define MILESTONE2_COMMONSEARCHER_H

#include "ISearcher.h"
#include <stack>
#include "MatrixEntry.h"
#include <iostream>
template<class T>
class CommonSearcher : public ISearcher<T> {

protected:
    set<State<T> *> closed;
    int evaluatedNodes;

public:
    CommonSearcher() {
        evaluatedNodes = 0;
    }

    virtual ~CommonSearcher() {
    }

    virtual unsigned long long int openListSize()=0;

    virtual int getNumberOfNodesEvaluated() final { return evaluatedNodes; }

    virtual string search(ISearchable<T> &searchable)=0;

    virtual string getRelationInDirection(State<T> *state1, State<T> *state2) {
        T t1 = state1->getStateDescriptor();
        T t2 = state2->getStateDescriptor();
        if (t1.getY() == t2.getY()) {
            if (t1.getX() < t2.getX()) {
                return "Down";
            }
            return "Up";
        } else {
            if (t1.getY() < t2.getY()) {
                return "Right";
            }
            return "Left";
        }
    }
    bool doesClosedContainState(State<T> *desiredState) {
        for (auto &state: closed) {
            if (*desiredState == *state) {
                return true;
            }
        }
        return false;
    }
    virtual string backtracePath(State<T> *state) {
        int i=0;
        cout<<"sum: "<<state->getCost()<<endl;
        stack<string> reversedOrder;
        while (state->getPrecedingState() != nullptr) {
            i++;
            string currDirection = getRelationInDirection(
                    state->getPrecedingState(), state);
            reversedOrder.push(currDirection);
            state = state->getPrecedingState();
        }
        cout<<"length: " <<i<<endl;
        string directions;
        while (reversedOrder.size() > 1) {
            directions += reversedOrder.top() + ", ";
            reversedOrder.pop();
        }
        if (reversedOrder.size() == 1) {
            directions += reversedOrder.top();
            reversedOrder.pop();
        }
        return directions;
    }

protected:
    virtual State<T> *popOpenList()=0;

};

#endif //MILESTONE2_COMMONSEARCHER_H
