//
// Created by Jonathan on 15/01/2019.
//

#include "MatrixFactory.h"

ISearchable<MatrixEntry> *MatrixFactory::GenerateMatrix(string str) {
    int columns = 0;
    int i = 0;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == NEW_LINE) {
            break;
        }
        if (str[i] == COMMA) {
            columns++;
        }
    }
    columns++;
    int rows = 0;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == NEW_LINE) {
            rows++;
        }
    }
    rows-=3;
    int **matrix = new int *[rows];
    int k = 0;
    string currValue;
    for (i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
        int j = 0;
        for (k; k < str.length(); k++) {
            if (str[k] == SPACE) {
                continue;
            }
            if (str[k] == NEW_LINE) {
                k++;
                break;
            }
            if (str[k] == COMMA) {
                matrix[i][j] = stoi(currValue);
                j++;
                currValue = "";
            } else {
                currValue += str[k];
            }
        }
        //treat last element
        matrix[i][j] = stoi(currValue);
        currValue = "";
    }
    int row1, col1, row2, col2;
    for (k; k < str.length(); k++) {
        if (str[k] == SPACE) {
            continue;
        }
        if (str[k] == NEW_LINE) {
            k++;
            break;
        }
        if (str[k] == COMMA) {
            row1 = stoi(currValue);
            currValue = "";
        } else {
            currValue += str[k];
        }
    }
    col1 = stoi(currValue);
    currValue = "";

    for (k; k < str.length(); k++) {
        if (str[k] == SPACE) {
            continue;
        }
        if (str[k] == NEW_LINE) {
            k++;
            break;
        }
        if (str[k] == COMMA) {
            row2 = stoi(currValue);
            currValue = "";
        } else {
            currValue += str[k];
        }
    }
    col2 = stoi(currValue);
    currValue = "";
    return new Matrix(columns, rows, matrix, MatrixEntry(row1, col1),
                      MatrixEntry(row2, col2));
    //TODO: free memory when needed
}
