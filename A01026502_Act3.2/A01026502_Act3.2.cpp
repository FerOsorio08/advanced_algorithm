//Fernanda Osorio
//A01026502
//09 de noviembre del 2023
//Este archivo cpp sirve para correr los algoritmos de floid y dijkstra para encontrar el camino mas corto entre dos nodos
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Read.h"

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

    return 0;
}