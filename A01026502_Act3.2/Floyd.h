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

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //Ak[i, j] = min (Ak-1[i, j], Ak-1[i, k] + Ak-1[k, j])
                if (A[i][k] != -1 && A[k][j] != -1) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }

    return A;
}

#endif