

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include <set>

#include "State.h"

using namespace std;

template<class T>
class ISearchable {
public:
    virtual State<T> *getInitialState() = 0;

    virtual bool isGoalState(State<T> *state) = 0;

    virtual set<State<T> *> getAllPossibleStates(State<T> *state) = 0;

    virtual T getGoalEntry()=0;

    virtual ~ISearchable() {};

};


#endif //MILESTONE2_SEARCHABLE_H
