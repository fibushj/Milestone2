

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H


template<class T>
class State {
private:
    T state;
    double cost;
    double heuristicCost;
    State<T> *cameFrom;
public:
    State(T state, double cost, State<T> *cameFrom) : state(state),
                                                      cost(cost),
                                                      cameFrom(cameFrom) {
        heuristicCost = 0;
    }

    T getStateDescriptor() { return state; }

    double getCost() { return cost; }

    double getHeuristicCost() { return heuristicCost; }

    void setHeuristicCost(
            double heuristicCost) { this->heuristicCost = heuristicCost; }

    State<T> *getPrecedingState() { return cameFrom; }

    void setPrecedingState(State<T> *cameFrom) { this->cameFrom = cameFrom; }

    bool operator==(State<T> &otherState);

    ~State() {}

};


template<class T>
bool State<T>::operator==(State<T> &otherState) {
    return this->state == otherState.getStateDescriptor();
}


#endif //MILESTONE2_STATE_H
