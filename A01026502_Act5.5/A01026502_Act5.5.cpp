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


int main(int argc, char *argv[]) {
    int N;
    cout << "Ingrese el tamaño del laberinto (N): ";
    cin >> N;

    vector<vector<int> > maze(N, vector<int>(N, 0));

    cout << "Ingrese el laberinto (0 para bloqueado, 1 para libre):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    imprimirLaberinto(maze);

    string path = findPath(maze, N);

    if (path != "No se encontró un camino") {
        cout << "El camino más corto es: " << path << endl;
    } else {
        cout << "No se encontró un camino" << endl;
    }

    return 0;
}