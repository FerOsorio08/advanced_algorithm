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
vector<vector<int> > FloydWarshall(const vector<vector<int> >& adjacencyMatrix);

//Funciones para Floyd-Warshall
//recibe la matriz de adyacencia
//regresa la matriz de adyacencia con los caminos mas cortos
//Complejidad = O(V^3), donde V es el numero de vertices
vector<vector<int> > FloydWarshall(const vector<vector<int> >& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    vector<vector<int> > A = adjacencyMatrix;

    // Inicializar la matriz con valor de infinito
    //numeric_limits<int>::max() es el valor maximo que puede tener un int
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == -1) {
                A[i][j] = numeric_limits<int>::max();
            }
        }
    }
    // Floyd-Warshall algorithm
    //para cada nodo k en el grafo se checa si el camino de i a j es mas corto pasando por k 
    //y si es asi se actualiza el valor de la matriz
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //si el camino de i a k y de k a j es menor que el camino de i a j
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