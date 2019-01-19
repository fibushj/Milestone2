
#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include "UnweightedGraphSearcher.h"
#include <stack>

template<class T>
class DFS : public UnweightedGraphSearcher<T> {
private:
    stack<State<T> *> open;

protected:
    State<T> *popOpenList() {
        CommonSearcher<T>::evaluatedNodes++;
        State<T> *state = open.top();
        open.pop();
        return state;
    }

public:
    virtual unsigned long long int openListSize() {
        return open.size();
    }

protected:
    virtual void pushToOpenList(State<T> *state) {
        open.push(state);
    }

    virtual bool doesOpenContainState(State<T> *state) {
        bool doesContain = false;
        stack<State<T> *> auxiliaryStack;
        while (!open.empty()) {
            if (*open.top() == *state) {
                doesContain = true;
            }
            auxiliaryStack.push(open.top());
            open.pop();
        }
        while (!auxiliaryStack.empty()) {
            open.push(auxiliaryStack.top());
            auxiliaryStack.pop();
        }
        return doesContain;
    }
};

#endif //MILESTONE2_DFS_H
