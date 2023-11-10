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
#include <queue>
#include <limits>
#ifndef Read_H
#define Read_H

using namespace std;

//Declaraciones de clases
// Clase para representar una arista
class Edge {
public:
    // Nodos que conecta la arista
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
//Complejidad = O(E), donde E es el numero de aristas
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

    //EN CASO DE QUERER MOSTRAR LA INFORMACION LEIDA
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
//Complejidad = O(n^2), donde n es el numero de nodos
vector<vector<int> > construirMatrizAdyacencia(int n, const vector<Edge>& edges){

    vector<vector<int> > adjacencyMatrix(n, vector<int>(n, -1));

    // La diagnonal de la matriz de adyacencia es 0
    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[i][i] = 0;
    }

    //LLenar la matriz de adyacencia con los pesos de las aristas dependiendo de los nodos que conectan
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