#include <iostream>
#include "PriorityQueue.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include "MatrixFactory.h"

template <class T>
int BestFirstSearch<T>::numberMatrix = 0;

int main() {
    string str="4,2,-1,33,1\n "
            "2 , 1231, 3, 4, 2 \n "
            "-1, 9, 2, 3,4\n "
            "0,2\n"
            "1 , 2\n";
    ISearchable<MatrixEntry>* a=MatrixFactory::GenerateMatrix(str, 3);
    BestFirstSearch<MatrixEntry> best;
    best.search(*a);
    best.resetData();
    best.search(*a);
    int x;
//    int **arr = new int *[3];
////    for (int i=0; i<3; i++) {
////        for (int j=0; j<5; j++) {
////            cout<<a[i][j]<<endl;
////        }
////
////    }
//    arr[0] = new int[3];
//    arr[1] = new int[3];
//    arr[2] = new int[3];
//    arr[0][0] = 1;
//    arr[0][1] = 2;
//    arr[0][2] = 3;
//
//    arr[1][0] = 4;
//    arr[1][1] = 1;
//    arr[1][2] = 2;
//
//    arr[2][0] = 3;
//    arr[2][1] = 4;
//    arr[2][2] = 3;
//
//    MatrixEntry start(0,0);
//    MatrixEntry end(2, 2);
//    Matrix matrix(3, 3, arr, start, end);
//    BestFirstSearch<MatrixEntry> bfs;
//    bfs.search(matrix);
//    bfs.resetData();
//    arr[0][1] = -1;
//    bfs.search(matrix);
//    int x=5;
}