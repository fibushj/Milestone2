
#include "Matrix.h"

Matrix::Matrix(int matrixWidth, int matrixHeight, int **matrix,
               MatrixEntry startEntry, MatrixEntry goalEntry)
        : matrixWidth(matrixWidth), matrixHeight(matrixHeight), matrix(matrix),
          startEntry(startEntry), goalEntry(goalEntry) {}


State<MatrixEntry> *Matrix::generateStateFromEntry
        (MatrixEntry entry,
         State<MatrixEntry> *predecessor) {
    State<MatrixEntry> *state;
    if (predecessor == nullptr) {
        /* Note to myself - I corrected from the cost being the matrix entry to
         * 0 since we're already there */
        state = new State<MatrixEntry>(entry, 0, predecessor);
    } else {
        state = new State<MatrixEntry>(entry, predecessor->getCost() +
                                              matrix[entry.getX()][entry.getY()],
                                       predecessor);
    }
    allStatesCreated.insert(state);
}

State<MatrixEntry> *Matrix::getInitialState() {
    return generateStateFromEntry(startEntry, nullptr);
}

bool Matrix::isGoalState(State<MatrixEntry> *state) {
    return goalEntry == state->getStateDescriptor();
}

set<State<MatrixEntry> *>
Matrix::getAllPossibleStates(State<MatrixEntry> *state) {
    set<State<MatrixEntry> *> possibleStates;
    int xCoordinate = state->getStateDescriptor().getX();
    int yCoordinate = state->getStateDescriptor().getY();
    //if the entry isn't in the first row
    if (xCoordinate > 0 && matrix[xCoordinate - 1][yCoordinate] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate - 1, yCoordinate), state));
    }
    //if the entry isn't in the last row
    if (xCoordinate < matrixHeight - 1 &&
        matrix[xCoordinate + 1][yCoordinate] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate + 1, yCoordinate), state));
    }
    //if the entry isn't in the first column
    if (yCoordinate > 0 && matrix[xCoordinate][yCoordinate - 1] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate, yCoordinate - 1), state));
    }
    //if the entry isn't in the last column
    if (yCoordinate < matrixWidth - 1 &&
        matrix[xCoordinate][yCoordinate + 1] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate, yCoordinate + 1), state));
    }
    return possibleStates;
}


Matrix::~Matrix() {
    for (auto &state : allStatesCreated) {
        delete state;
    }
    for (int i = 0; i < matrixHeight; i++) {
        delete matrix[i];
    }
    delete matrix;
}
