//
// Created by Jonathan on 14/01/2019.
//

#ifndef MILESTONE2_MATRIXENTRY_H
#define MILESTONE2_MATRIXENTRY_H


class MatrixEntry {
private:
    int x;
    int y;
public:
    MatrixEntry(int x, int y);

    int getX()const { return x; }

    int getY()const { return y; }

    bool operator==(const MatrixEntry &anotherEntry);
};


#endif //MILESTONE2_MATRIXENTRY_H
