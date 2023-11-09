//Fernanda Osorio
//A01026502
//09 de noviembre del 2023
//Este archivo header contiene las funciones necesarias para leer los archivos de texto y crear la lista de adyacencia
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Declaraciones de funciones
void readFile(string x, vector<vector<int>> &v, int &n, int &m);