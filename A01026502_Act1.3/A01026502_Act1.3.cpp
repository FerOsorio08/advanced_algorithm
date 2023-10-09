//Fernanda Osorio Arroyo - A01026502
//9 de Octubre del 2023
//Este archivo sirve para resolver el problema "Laberinto" utilizando el algoritmo de Backtracking y Branch and Bound
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "laberynth_functions.h"
using namespace std;

int rows, cols; // variables para guardar el número de filas y columnas del laberinto
vector<vector<int>> laberynth; // vector para guardar el laberinto
vector<vector<int>> solution; // vector para guardar la solución del laberinto

void ReadFile(string x);
void Backtracking();
void BranchBound();

int main(int argc, char *argv[]){

}

void ReadFile(string x){
    ReadFile(x, laberynth);
}