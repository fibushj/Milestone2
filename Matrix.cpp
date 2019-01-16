//
// Created by Jonathan on 14/01/2019.
//

#include "Matrix.h"

Matrix::Matrix(int matrixWidth, int matrixHeight, int **matrix,
               MatrixEntry startEntry, MatrixEntry goalEntry)
        : matrixWidth(matrixWidth), matrixHeight(matrixHeight), matrix(matrix),
          startEntry(startEntry), goalEntry(goalEntry) {}


State<MatrixEntry> *Matrix::generateStateFromEntry(MatrixEntry entry,
                                                   State<MatrixEntry> *predecessor) {
    if (predecessor == nullptr) {
        return new State<MatrixEntry>(entry, matrix[entry.getX()][entry.getY()],
                                      predecessor);
    }
    return new State<MatrixEntry>(entry, predecessor->getCost() +
                                         matrix[entry.getX()][entry.getY()],
                                  predecessor);
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
    if (xCoordinate > 0 && matrix[xCoordinate - 1][yCoordinate] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate - 1, yCoordinate), state));
    }
    if (xCoordinate < matrixWidth - 1 &&
        matrix[xCoordinate + 1][yCoordinate] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate + 1, yCoordinate), state));
    }
    if (yCoordinate > 0 && matrix[xCoordinate][yCoordinate - 1] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate, yCoordinate - 1), state));
    }
    if (yCoordinate < matrixHeight - 1 &&
        matrix[xCoordinate][yCoordinate + 1] != -1) {
        possibleStates.insert(
                generateStateFromEntry(
                        MatrixEntry(xCoordinate, yCoordinate + 1), state));
    }
    return possibleStates;
}


Matrix::~Matrix() {

}