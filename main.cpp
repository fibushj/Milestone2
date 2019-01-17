#include <iostream>
#include "PriorityQueue.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include "MatrixFactory.h"

template<class T>
int BestFirstSearch<T>::numberMatrix = 0;




int main() {
    string str =
            "5, 8, 1, 98, 4, 3, 9, 2, 4\n "
                    "45, 19, 1, 3, 14, 13, 7, 2, 84 \n "
                    "6, 5, 8, 2, 4, 9, -1, 2, 6  \n "
                    "1, 0\n"
                    "2 , 8\n";
    ISearchable<MatrixEntry> *a = MatrixFactory::GenerateMatrix(str, 3);
    BestFirstSearch<MatrixEntry> best;
    cout << best.search(*a) << endl;
    best.clearData();
    best.search(*a);
    int x;
}
