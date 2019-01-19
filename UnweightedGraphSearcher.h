
#ifndef MILESTONE2_UNWEIGHTEDGRAPHSEARCHER_H
#define MILESTONE2_UNWEIGHTEDGRAPHSEARCHER_H
#include "CommonSearcher.h"

template<class T>
class UnweightedGraphSearcher : public CommonSearcher<T> {
protected:

    virtual State<T> *popOpenList()=0;
    virtual void pushToOpenList(State<T>* state)=0;
    virtual bool doesOpenContainState(State<T>* state)=0;
    virtual unsigned long long int openListSize()=0;


public:
    virtual string search(ISearchable<T> &searchable) {
        pushToOpenList(searchable.getInitialState());
        while (openListSize()>0) {
            State<T> *n = popOpenList();
            CommonSearcher<T>::closed.insert(n);
            if (searchable.isGoalState(n)) {
                return CommonSearcher<T>::backtracePath(n);
            }
            set<State<T> *> successors = searchable.getAllPossibleStates(n);
            for (auto &state : successors) {
                bool isInClosed = CommonSearcher<T>::doesClosedContainState(state);
                if (isInClosed) {
                    continue;
                }
                if (!doesOpenContainState(state)) {
                    pushToOpenList(state);
                }
            }
        }
        return "-1";
    }

    virtual ~UnweightedGraphSearcher() {

    }

};
#endif //MILESTONE2_UNWEIGHTEDGRAPHSEARCHER_H
