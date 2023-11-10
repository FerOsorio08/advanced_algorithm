//Fernanda Osorio
//A01026502
//09 de noviembre del 2023
//Este archivo header contiene las funciones necesarias para el algoritmo de Floyd-Warshall 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#ifndef Floyd_H
#define Floyd_H

using namespace std;


//Declaraciones de funciones

//Funciones para Floyd-Warshall
vector<vector<int> > FloydWarshall(const vector<vector<int> >& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    vector<vector<int> > A = adjacencyMatrix;

    // Replace -1 with infinity
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == -1) {
                A[i][j] = numeric_limits<int>::max();
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][k] != numeric_limits<int>::max() && A[k][j] != numeric_limits<int>::max()) {
                    if (A[i][k] + A[k][j] < A[i][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
    }

    return A;
}

#endif