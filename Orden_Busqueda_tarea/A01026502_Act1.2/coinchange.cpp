//Fernanda Osorio Arroyo - A01026502
// 28 de septiembre del 2023
//Este archivo sirve para resolver el problema "cambio de monedas" utilizando el algoritmo Greedy y programación Dinámica
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "coinchange_funciones.h"
using namespace std;

// Declaraciones de funciones
vector<int> monedas;
void minNumMonGR(int n);
void minNumMonPD(int n);

int main(int argc, char *argv[])
{

    // Declaración de variables
    vector<int> v; // vector para guardar los datos del archivo
    vector<int> v2;
    int n = 0; // número de monedas
    int j = 0; // costo
    int k = 0; // pago

    // readFile("ejemplo01coins.txt", v); // leer el archivo y guardar los datos en el vector v
    cout << "\x1B[1;32m"
         << "Cuantas monedas hay:"
         << "\x1B[0m" << endl;
    cin >> n;
    cout << "\x1B[1;32m"
         << "Posibles denomicaciones:"
         << "\x1B[0m" << endl;
    recibeDatos(n, monedas); // leer el archivo y guardar los datos en el vector v
    cout << "\x1B[1;34m"
         << "Cual es el costo:"
         << "\x1B[0m" << endl;
    cin >> j;
    cout << "\x1B[1m"
         << "Cual es el pago:"
         << "\x1B[0m" << endl;
    cin >> k;
    cout << "\x1B[1;35m"
         << "Usando Greedy Algorithm:"
         << "\x1B[0m" << endl;
    minNumMonGR(getChange(j, k));

    return 0;
}

void minNumMonGR(int n){
    minNumMonGR(n, monedas);
}

void minNumMonPD(int n){
    minNumMonPD(n, monedas);
}