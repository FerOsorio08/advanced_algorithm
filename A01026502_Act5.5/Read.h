//Fernanda Osorio
//A01026502
//20 de noviembre del 2023
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

//Declaraciones de funciones
vector< vector < int > > crearLaberinto(int N);



//Función para recibir los datos del usuario y crear el laberinto
vector< vector < int > > crearLaberinto(int N){
    vector< vector < int > > maze(N, vector<int>(N, 0));
    cout << "Ingrese los elementos del laberinto (0 o 1):" << endl;
    cout << "Ingresa enter despues de cada elemento" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Fila " << i + 1 << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
        }
    }
    return maze;
}

//Función para imprimir el laberinto
void imprimirLaberinto(const vector< vector < int > >& maze){
    cout << "Laberinto:" << endl;
    for (const auto &row : maze){
        for (int element : row){
            cout << element << " ";
        }
        cout << endl;
    }
}

#endif
