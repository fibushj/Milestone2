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
    /*removing from the count the last three messages from the client, which all
    contain \n */
    rows-=3;
    int **matrix = new int *[rows];
    int k = 0;
    string currValue;
    //performing parsing
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
        //treating last element
        matrix[i][j] = stoi(currValue);
        currValue = "";
    }
    int row1, col1, row2, col2;
    /* treating the two messages from the client that indicate the start and end
     * enries in the matrix */
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
    //treating the end entry
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
}
