
#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H

#include "UnweightedGraphSearcher.h"
#include <queue>

template<class T>
class BFS : public UnweightedGraphSearcher<T> {
private:
    queue<State<T> *> open;

protected:
    State<T> *popOpenList() {
        CommonSearcher<T>::evaluatedNodes++;
        State<T> *state = open.front();
        open.pop();
        return state;
    }
    bool doesOpenContainState(State<T> *state) {
        bool doesContain = false;
        for (unsigned long long int i = 0; i < open.size(); i++) {
            if (*open.front() == *state) {
                doesContain = true;
            }
            open.push(open.front());
            open.pop();
        }
        return doesContain;
    }

    virtual void pushToOpenList(State<T> *state) {
        open.push(state);
    }

    virtual unsigned long long int openListSize() {
        return open.size();
    }
};
#endif //MILESTONE2_BFS_H
