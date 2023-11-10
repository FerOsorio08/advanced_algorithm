//Fernanda Osorio
//A01026502
//09 de noviembre del 2023
//Este archivo header contiene las funciones necesarias para leer los archivos de texto y crear la matriz de adyacencia
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#ifndef Read_H
#define Read_H

using namespace std;

//Declaraciones de clases
class Edge {
public:
    int start, end, weight;

    // Constructor para inicializar los miembros de la clase
    Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};


// Declaraciones de funciones
vector<Edge> ReadFile(const string& x);
void printVector(vector<Edge> v);
vector<vector<int> > construirMatrizAdyacencia(int n, const vector<Edge>& edges);


// función para leer el archivo, recibe el nombre del archivo
// regresa nada
vector<Edge> ReadFile(const string& x){
    // Abrir el archivo de entrada
    ifstream inputFile(x);

    if (!inputFile) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return vector<Edge>();
    }

    // Leer el número de nodos y aristas
    int n, m;
    inputFile >> n >> m;

    // Leer las aristas y almacenarlas en un vector
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        inputFile >> a >> b >> c;
        edges.push_back(Edge(a, b, c));
    }

    // Mostrar la información leída
    // cout << "Número de nodos: " << n << endl;
    // cout << "Número de aristas: " << m << endl;

    // cout << "Aristas:" << endl;
    // for (const auto& edge : edges) {
    //     cout << edge.start << " -> " << edge.end << " (Peso: " << edge.weight << ")" << endl;
    // }

    // Cerrar el archivo
    inputFile.close();
    return edges;
}


//función para construir la matriz de adyacencia, recibe el número de nodos y el vector de aristas
//regresa la matriz de adyacencia
vector<vector<int> > construirMatrizAdyacencia(int n, const vector<Edge>& edges){

    vector<vector<int> > adjacencyMatrix(n, vector<int>(n, -1));

    // Set diagonal elements to zero
    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[i][i] = 0;
    }

    // Fill in the adjacency matrix based on the directed edges
    for (const Edge& edge : edges) {
        adjacencyMatrix[edge.start][edge.end] = edge.weight;
    }


    // Mostrar la matriz de adyacencia
    cout << "Matriz de adyacencia:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return adjacencyMatrix;
}

#endif