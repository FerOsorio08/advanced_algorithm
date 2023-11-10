//Fernanda Osorio
//A01026502
//09 de noviembre del 2023
//Este archivo cpp sirve para correr los algoritmos de floid y dijkstra para encontrar el camino mas corto entre dos nodos
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Read.h"
#include "Dijkstra.h"

using namespace std;

int main(int argc, char *argv[]){
    // Leer el archivo de entrada
    // ReadFile("try.txt");
    vector<Edge> edges = ReadFile("try.txt");
    int n = 0;
    for (const auto& edge : edges) {
        n = max(n, max(edge.start, edge.end) + 1);
    }
    int m = edges.size();
    cout << "Número de nodos: " << n << endl;
    vector<vector<int> > matrizAdyacencia = construirMatrizAdyacencia(n, edges);

    // Run Dijkstra's algorithm for every node as the source node
    for (int i = 0; i < n; ++i) {
        cout << "Running Dijkstra's algorithm for source node " << i << endl;
        auto result = dijkstra(matrizAdyacencia, i);

        // Display the results
        vector<int> distances = result.first;
        // vector<int> previousNodes = result.second;

        cout << "Shortest distances from node " << i << ":" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "To node " << i << ": " << distances[i] << endl;
        }

        // cout << "Previous nodes in the shortest path:" << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << "Node " << i << ": " << previousNodes[i] << endl;
        // }
    }

    return 0;
}