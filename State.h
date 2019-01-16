

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H


template<class T>
class State {
private:
    T state;
    double cost;
    State<T> *cameFrom;
public:
    State(T state, double cost, State<T> *cameFrom);

    ~State() { } //TODO

    T getStateDescriptor() { return state; }

    double getCost() { return cost; }

    void setCost(double cost) { this->cost = cost; }

    State<T> *getPrecedingState() { return cameFrom; }

    void setPrecedingState(State<T> *cameFrom) { this->cameFrom = cameFrom; }

    bool operator==(State<T> &otherState);
};

template<class T>
//for each state, we have the cost and when we are cameFrom. for the initial state, we came from null.
State<T>::State(T state, double cost, State<T> *cameFrom) : state(state), cost(cost), cameFrom(cameFrom) {
}

template<class T>
//compare into 2 states
bool State<T>::operator==(State<T> &otherState) {
    return this->state == otherState.getStateDescriptor();
}





#endif //MILESTONE2_STATE_H
