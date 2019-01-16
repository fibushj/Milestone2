//
// Created by Jonathan on 15/01/2019.
//

#ifndef MILESTONE2_ISEARCHER_H
#define MILESTONE2_ISEARCHER_H

#include "State.h"
#include "ISearchable.h"

template<class T>
class ISearcher {
public:

    virtual State<T> *search(ISearchable<T> &searchable)=0;

    virtual int getNumberOfNodesEvaluated()=0;

};

#endif //MILESTONE2_ISEARCHER_H
