//Fernanda Osorio 
//A01026502
//20 de noviembre del 2023
//Este archivo cpp sirve para resolver un laberito con el algoritmo de A* y mostrar el camino mas corto
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Read.h"
#include "A_star.h"

using namespace std;

//vector de vectores para laberinto
vector< vector < int > > maze;
// Define the Node structure
// struct Node {
//     int x, y;

//     Node(int _x, int _y) : x(_x), y(_y) {}
// };

int main(int argc, char *argv[]){

    //Input para el tamaño del laberinto
    int N;
    cout << "Ingresa el tamaño del laberinto: ";
    cin >> N;
    maze = crearLaberinto(N);
    imprimirLaberinto(maze);
    pair<int, int> coordinates = make_pair(0, 0);
    Node start(coordinates);
    pair<int, int> coordinates2 = make_pair(N - 1, N - 1);
    cout << "Inicio: " << start.x << " " << start.y << endl;
    Node goal(coordinates2);
    cout << "Meta: " << goal.x << " " << goal.y << endl;
    // Node start = {0, 0};
    // cout << "Inicio: " << start.x << " " << start.y << endl;
    // Node goal = {N - 1, N - 1};

    vector<Node> path = AStar(start, goal, maze);
    cout << "Camino: " << endl;
    printPath(path);

}