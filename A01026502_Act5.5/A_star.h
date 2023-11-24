//Fernanda Osorio
//A01026502
//20 de noviembre del 2023
//Este archivo header contiene las funciones necesarias para implementar el algoritmo de A*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <limits>
#include <set>
#ifndef A_star_H
#define A_star_H

using namespace std;

//Struct para los nodos
//Complejidad: O(1)
struct Node {
    int x, y, distance, cost;
    string path; // Added to store the path

    Node(int x, int y, int distance, int cost, string path)
        : x(x), y(y), distance(distance), cost(cost), path(path) {}

    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}


//Declaraciones de funciones
int ManhattanDistance(const Node& current, const Node& destination);
bool isValid(int x, int y, int N, const vector<vector<int> >& maze, vector<vector<bool> >& visited);
void printPath(const vector<Node>& path);
vector<Node> AStar(const Node& start, const Node& destination, const vector<vector<int> >& maze);
string findPath(vector<vector<int> > &maze, int N);

//Funciones para el algoritmo de A*

//Función para calcular la distancia de Manhattan entre dos nodos
//Heruística utilizada para el algoritmo de A*
//Complejidad: O(1)
//No esta en uso en esta solución
int ManhattanDistance(const Node& current, const Node& destination){
    return abs(current.x - destination.x) + abs(current.y - destination.y);
}

//Función para encontrar el camino más corto para llegar al destino
//Complejidad: O(N^2*log(N^2)) = O(N^2*log(N)
string findPath(vector<vector<int> > &maze, int N) {

    //Arreglos para moverse en el laberinto
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    //Nodo inicial y nodo destino
    Node start(0, 0, 0, 0, ""); // incluye el path
    Node destination(N-1, N-1, 0, 0, "");

    //Matriz para saber si ya se visitó un nodo
    //matriz de N*N con valores de false
    vector<vector<bool> > visited(N, vector<bool>(N, false));

    //Priority queue para almacenar los nodos
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(start);

    //Mientras la priority queue no esté vacía
    while (!pq.empty()) {
        //Se obtiene el nodo con menor costo y ese se visita
        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        //Se marca como visitado (TRUE)
        visited[x][y] = true;

        //Si se llegó al destino, se regresa el camino
        if (x == destination.x && y == destination.y) {
            return current.path;
        }

        //Se revisan los vecinos del nodo actual
        for (int i = 0; i < 4; i++) {
            //Se obtienen las coordenadas del vecino
            int newX = x + dx[i];
            int newY = y + dy[i];

            //Si el vecino es válido, no está bloqueado, no se ha visitado y no está en la priority queue
            if (isValid(newX, newY, N) && maze[newX][newY] == 1 && !visited[newX][newY]) {
                //Se crea un nueva nueva distancia y costo para el vecino
                int newDistance = current.distance + 1;
                int newCost = newDistance + abs(newX - destination.x) + abs(newY - destination.y);

                //Se crea un nuevo path para el vecino
                string newPath = current.path;
                switch (i) {
                    case 0: newPath += "U"; break;
                    case 1: newPath += "D"; break;
                    case 2: newPath += "L"; break;
                    case 3: newPath += "R"; break;
                }
                //Se agrega el vecino a la priority queue con su nuevo costo, distancia y path
                pq.push(Node(newX, newY, newDistance, newCost, newPath));
            }
        }
    }
    //Si la priority queue está vacía, no se encontró un camino
    return "No se encontró un camino";
}






#endif