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
int ManhattanDistance(const Node& current, const Node& destination){
    return abs(current.x - destination.x) + abs(current.y - destination.y);
}

//Función para encontrar el camino más corto para llegar al destino
string findPath(vector<vector<int> > &maze, int N) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    Node start(0, 0, 0, 0, ""); // Updated to include the path
    Node destination(N-1, N-1, 0, 0, "");

    vector<vector<bool> > visited(N, vector<bool>(N, false));

    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(start);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        visited[x][y] = true;

        if (x == destination.x && y == destination.y) {
            return current.path;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, N) && maze[newX][newY] == 1 && !visited[newX][newY]) {
                int newDistance = current.distance + 1;
                int newCost = newDistance + abs(newX - destination.x) + abs(newY - destination.y);

                // Updated to include the direction in the path
                string newPath = current.path;
                switch (i) {
                    case 0: newPath += "U"; break;
                    case 1: newPath += "D"; break;
                    case 2: newPath += "L"; break;
                    case 3: newPath += "R"; break;
                }

                pq.push(Node(newX, newY, newDistance, newCost, newPath));
            }
        }
    }

    return "No se encontró un camino";
}






#endif