// Fernanda Osorio
// A01026502
// 09 de noviembre del 2023
// Este archivo cpp sirve para correr los algoritmos de floid y dijkstra para encontrar el camino mas corto entre dos nodos
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Read.h"
#include "Dijkstra.h"
#include "Floyd.h"

using namespace std;

//Complejidad = O(n^3), combinando las complejidad de los algoritmos de dijkstra y floyd
int main(int argc, char *argv[])
{
    // Leer el archivo de entrada
    vector<Edge> edges = ReadFile("try.txt");
    int n = 0;
    for (const auto &edge : edges){
        n = max(n, max(edge.start, edge.end) + 1);
    }
    int m = edges.size();
    cout << "\x1B[1;31m"
         << "Número de nodos: " << n << "\x1B[0m" << endl;

    // Construir la matriz de adyacencia
    vector<vector<int>> matrizAdyacencia = construirMatrizAdyacencia(n, edges);

    // Algoritmo de Dijkstra
    cout << "\x1B[1;32m"
         << "Dijkstra :"
         << "\x1B[0m" << endl;
    for (int i = 0; i < n; ++i){
        cout << "Shortest distances from node " << i + 1 << ":" << endl;
        cout << "node " << i + 1 << " to node " << i + 1 << " : 0" << endl; // Distance from a node to itself is 0
        auto result = dijkstra(matrizAdyacencia, i);
        vector<int> distances = result.first;
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                cout << "node " << i + 1 << " to node " << j + 1 << " : " << distances[j] << endl;
            }
        }
    }

    // Algoritmo de Floyd-Warshall
    cout << "\x1B[1;34m"
         << "Floyd-Warshall :"
         << "\x1B[0m" << endl;
    vector<vector<int>> floydMatrix = FloydWarshall(matrizAdyacencia);
    cout << "Matriz resultado con el algoritmo de Floyd-Warshall" << endl;
    // recorrer la matriz de adyacencia y mostrarla
    for (const auto &row : floydMatrix){
        // para cada distancia en la fila
        for (int distance : row)
        {
            // si la distancia es infinito mostrar inf
            if (distance == numeric_limits<int>::max())
            {
                cout << "inf ";
            }
            else
            {
                cout << distance << " ";
            }
        }
        cout << endl;
    }

    return 0;
}