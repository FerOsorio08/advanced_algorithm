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
    int x, y;

    Node(int _x, int _y) : x(_x), y(_y) {}
};

//Declaraciones de funciones
int ManhattanDistance(const Node& current, const Node& destination);
bool isValid(int x, int y, int N, const vector<vector<int> >& maze, vector<vector<bool> >& visited);
void printPath(const vector<Node>& path);
vector<Node> AStar(const Node& start, const Node& destination, const vector<vector<int> >& maze);


//Funciones para el algoritmo de A*

//Función para calcular la distancia de Manhattan entre dos nodos
//Heruística utilizada para el algoritmo de A*
int ManhattanDistance(const Node& current, const Node& destination){
    return abs(current.x - destination.x) + abs(current.y - destination.y);
}

//Función para verificar si un movimiento es válido
// Function to check if a node is valid for A*
bool isValid(int x, int y, const vector<vector<int> >& maze, const set<Node>& closedSet) {
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1 && closedSet.find(Node(x, y)) == closedSet.end());
}

//Función para imprimir la ruta encontrada
void printPath(const vector<Node>& path) {
    for (const auto& node : path) {
        cout << "(" << node.x << "," << node.y << ") ";
    }
    cout << endl;
}

//Función principal para encontrar el camino utilizando A*
// vector<Node> AStar(const Node& start, const Node& destination, const vector<vector<int> >& maze, int N) {
//     //Inicialización de la cola de prioridad para almacenar los nodos a explorar
//     priority_queue<Node, vector<Node>, greater<Node> > pq;

//     //Inicialización del laberinto visitado
//     vector<vector<bool> > visited(N, vector<bool>(N, false));

//     //Inicialización del vector de dirección
//     vector<pair<int, int> > directions;
//     directions.push_back(make_pair(-1, 0));
//     directions.push_back(make_pair(0, -1));
//     directions.push_back(make_pair(1, 0));
//     directions.push_back(make_pair(0, 1));
        
//     //Insertar el nodo de inicio en la cola de prioridad
//     pq.push(start);

//     while (!pq.empty()) {
//         //Extraer el nodo de menor coste de la cola de prioridad
//         Node current = pq.top();
//         pq.pop();

//         //Marcar el nodo actual como visitado
//         visited[current.x][current.y] = true;

//         //Si el nodo actual es el nodo destino, se ha encontrado el camino
//         if (current.x == destination.x && current.y == destination.y) {
//             return current;
//         }

//         //Explorar los nodos vecinos
//         for (const auto& direction : directions) {
//             int nextX = current.x + direction.first;
//             int nextY = current.y + direction.second;

//             //Si el movimiento es válido, se agrega el nodo a la cola de prioridad
//             if (isValid(nextX, nextY, N, maze, visited)) {
//                 //Inicialización del nodo vecino
//                 Node next(nextX, nextY);

//                 //Calcular la distancia y la heurística del nodo vecino
//                 next.distance = current.distance + 1;
//                 next.heuristic = ManhattanDistance(next, destination);

//                 //Insertar el nodo vecino en la cola de prioridad
//                 pq.push(next);
//             }
//         }
//     }

//     //Si no se encuentra el camino, se regresa un vector vacío
//     return vector<Node>();
// }

vector <Node> AStar(const Node& start, const Node& destination, const vector<vector<int> >& maze){
    set <Node> openSet;
    //where the parent of node is the node immediately preceding it on the cheapest path from start to node currently known.
    unordered_map <Node, Node> parent;
    //where gScore[node] is the cost of the cheapest path from start to node currently known.
    unordered_map <Node, int> gScore;
    gScore[start] = 0;
    //how cheap the path could be from start to n
    unordered_map <Node, int> fScore;
    fScore[start] = ManhattanDistance(start, destination);

    //insert start into openSet
    openSet.insert(start);

    while(!openSet.empty()){
        Node current = *min_element(openSet.begin(), openSet.end(), [&](const Node& a, const Node& b) {
            return fScore[a] < fScore[b];
        });
        //if the current node is the destination node
        if (current.x == destination.x && current.y == destination.y){
            vector <Node> path;
            while (parent.find(current) != parent.end()){
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }
        openSet.erase(current);
        vector <Node> neighbors;
        neighbors.push_back(Node(current.x - 1, current.y));
        neighbors.push_back(Node(current.x, current.y - 1));
        neighbors.push_back(Node(current.x + 1, current.y));
        neighbors.push_back(Node(current.x, current.y + 1));
        for (const auto& neighbor : neighbors){
            int tentative_gScore = gScore[current] + 1;
            int NextX = neighbor.x + current.x;
            int NextY = neighbor.y + current.y;
            if (NextX >= 0 && NextX < maze.size() && NextY >= 0 && NextY < maze.size() && maze[NextX][NextY] == 1){
                Node neighbor(NextX, NextY);
                int tentative_gScore = gScore[current] + 1;
                if (tentative_gScore < gScore[neighbor]){
                    parent[neighbor] = current;
                    gScore[neighbor] = tentative_gScore;
                    fScore[neighbor] = gScore[neighbor] + ManhattanDistance(neighbor, destination);
                    if (openSet.find(neighbor) == openSet.end()) {
                        openSet.insert(neighbor);
                    }
                }
            // if (isValid(neighbor.x, neighbor.y, maze, openSet) && tentative_gScore < gScore[neighbor]){
            //     parent[neighbor] = current;
            //     gScore[neighbor] = tentative_gScore;
            //     fScore[neighbor] = gScore[neighbor] + ManhattanDistance(neighbor, destination);
            //     if (openSet.find(neighbor) == openSet.end()) {
            //             openSet.insert(neighbor);
            //     }
            }
        }
    }
    return vector<Node>();

}





#endif