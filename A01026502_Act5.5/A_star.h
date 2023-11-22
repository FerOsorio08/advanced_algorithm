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

    Node(std::pair<int, int> coordinates) : x(coordinates.first), y(coordinates.second) {}

    bool operator<(const Node& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
};

// Provide a hash function for Node
template <>
struct hash<Node> {
    size_t operator()(const Node& n) const {
        // Use a simple hash function for pairs of integers
        return hash<int>()(n.x) ^ hash<int>()(n.y);
    }
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
// bool isValid(int x, int y, const vector<vector<int> >& maze, const set<Node>& closedSet) {
//     return (x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1 && closedSet.find(Node(x, y)) == closedSet.end());
// }

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

vector<Node> AStar(const Node& start, const Node& destination, const vector<vector<int> >& maze) {
    set<Node> openSet;
    unordered_map<Node, Node> parent;
    cout << "Start X" << start.x << " " << "Start Y" << start.y << endl;
    unordered_map<Node, int> gScore;
    //gscore from start to start is 0
    //start node is {0,0}
    gScore[start] = 0;
    unordered_map<Node, int> fScore;
    fScore[start] = ManhattanDistance(start, destination);
    cout << "Manhattan Distance: " << fScore[start] << endl;

    openSet.insert(start);

    while (!openSet.empty()) {
        // Find the minimum element in openSet
        //current node is the node with the smallest fScore
        Node current = *openSet.begin();
        cout << "Current X" << current.x << " " << "Current Y" << current.y << endl;
        //for each node in openSet find the node with the smallest fScore
        for (const auto& node : openSet) {
            if (fScore[node] < fScore[current]) {
                current = node;
            }
        }

        //if the current node is the destination node
        if (current.x == destination.x && current.y == destination.y) {
            //return reconstruct_path(cameFrom, current);
            vector<Node> path;
            //reconstruct the path going backwards from the destination node
            // while (parent.find(current) != parent.end()) {
            //     path.push_back(current);
            //     current = parent[current];
            // }
            // //add the start node to the path
            // path.push_back(start);
            // //reverse the path
            // reverse(path.begin(), path.end());
            // //return the path
            return path;
        }

        //remove the current node from openSet
        openSet.erase(current);

        //add the current node to closedSet
        //create a vector of neighbors
        vector<Node> neighbors;
        //add the neighbors to the vector

        
        // neighbors.push_back(Node(make_pair(current.x - 1, current.y)));
        // neighbors.push_back(Node(make_pair(current.x, current.y - 1)));
        // neighbors.push_back(Node(make_pair(current.x + 1, current.y)));
        // neighbors.push_back(Node(make_pair(current.x, current.y + 1)));
        // neighbors.push_back(Node(current.x, current.y - 1));
        // neighbors.push_back(Node(current.x + 1, current.y));
        // neighbors.push_back(Node(current.x, current.y + 1));

        //for each neighbor
        for (const auto& neighbor : neighbors) {
            //integer variables to store the coordinates of the neighbor
            int NextX = neighbor.x;
            int NextY = neighbor.y;
            cout << "Next X" << NextX << " " << "Next Y" << NextY << endl;
            //if the neighbor is a valid node 
            //condition 1: the neighbor is within the maze
            //condition 2: the neighbor is not an obstacle
            //condition 3: the neighbor is not in closedSet

            // if (NextX >= 0 && NextX < maze.size() && NextY >= 0 && NextY < maze.size() && maze[NextX][NextY] == 1) {
            //     //integer variable to store the distance from start to a neighbor
            //     int tentative_gScore = gScore[current] + 1;

            //     //if the tentative_gScore is less than the gScore of the neighbor
            //     if (tentative_gScore < gScore[neighbor]) {
            //         //update the parent of the neighbor
            //         //parent of the neighbor is the current node
            //         parent[neighbor] = current;
            //         //update the gScore of the neighbor
            //         gScore[neighbor] = tentative_gScore;
            //         //update the fScore of the neighbor
            //         fScore[neighbor] = gScore[neighbor] + ManhattanDistance(neighbor, destination);
            //         //if the neighbor is not in openSet, add it to openSet
            //         if (openSet.find(neighbor) == openSet.end()) {
            //             openSet.insert(neighbor);
            //         }
            //     }
            // }
        }
    }
    return vector<Node>();
}






#endif