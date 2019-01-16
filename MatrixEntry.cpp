//
// Created by Jonathan on 14/01/2019.
//

#include "MatrixEntry.h"

MatrixEntry::MatrixEntry(int x, int y) {
    this->x = x;
    this->y = y;
}

bool MatrixEntry::operator==(const MatrixEntry &anotherEntry) {
    return this->x == anotherEntry.getX() && this->y == anotherEntry.getY();
}
