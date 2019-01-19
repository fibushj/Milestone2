
#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H

#include "ISearchable.h"
#include "MatrixEntry.h"

class Matrix : public ISearchable<MatrixEntry> {
private:
    int matrixWidth;
    int matrixHeight;
    int **matrix; //TODO - espically in constructor assignment
    MatrixEntry startEntry;
    MatrixEntry goalEntry;
    set<State<MatrixEntry> *> allStatesCreated;

public:
    Matrix(int matrixWidth, int matrixHeight, int **matrix,
           MatrixEntry startEntry, MatrixEntry goalEntry);

    virtual State<MatrixEntry> *getInitialState();

    virtual bool isGoalState(State<MatrixEntry> *state);

    virtual set<State<MatrixEntry> *>
    getAllPossibleStates(State<MatrixEntry> *state);

    MatrixEntry getGoalEntry() { return goalEntry; }

    State<MatrixEntry> *
    generateStateFromEntry(MatrixEntry entry, State<MatrixEntry> *predecessor);

    virtual ~Matrix();

};


#endif //MILESTONE2_MATRIX_H
