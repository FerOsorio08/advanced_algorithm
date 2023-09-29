// Fernanda Osorio Arroyo - A01026502
//  28 de septiembre del 2023
// Este archivo sirve para resolver el problema "cambio de monedas" utilizando el algoritmo Greedy y programación Dinámica
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "coinchange_funciones.h"
using namespace std;

// Declaraciones de funciones
vector<int> monedas;
vector<int> moneditas;
vector<int> minNumMonGR(int n); // función para calcular el cambio en monedas con el algoritmo Greedy
vector<int> minNumMonPD(int n); // función para calcular el cambio en monedas con programación dinámica
void escribeRespuesta(int n);   // función para imprimir el cambio en monedas

int main(int argc, char *argv[]){

     // Declaración de variables
     vector<int> v; // vector para guardar los datos del archivo
     int n = 0;     // número de monedas
     int j = 0;     // costo
     int k = 0;     // pago
     int x = 0;     // variable para guardar el resultado de la función getChange

     cout << "\x1B[1;32m"
          << "Cuantas monedas hay:"
          << "\x1B[0m" << endl;
     cin >> n; // recibe el número de monedas
     cout << "\x1B[1;32m"
          << "Posibles denomicaciones:"
          << "\x1B[0m" << endl;
     recibeDatos(n, monedas); // leer el archivo y guardar las denominaciones en el vector v
     cout << "\x1B[1;34m"
          << "Cual es el costo:"
          << "\x1B[0m" << endl;
     cin >> j; // recibe el costo
     cout << "\x1B[1m"
          << "Cual es el pago:"
          << "\x1B[0m" << endl;
     cin >> k;            // recibe el pago
     x = getChange(k, j); // calcuka el cambio con función getChange
     cout << "\x1B[1;35m"
          << "Usando Greedy Algorithm:"
          << "\x1B[0m" << endl;
     cout << "\x1B[1m"
          << "El cambio es:  " << x
          << "\x1B[0m" << endl;
     moneditas = minNumMonGR(x); // guarda el resultado de la función minNumMonGR en el vector moneditas
     escribeRespuesta(x);
     cout << "\x1B[1;36m"
          << "Usando Dynamic Programming:"
          << "\x1B[0m" << endl;
     moneditas = minNumMonPD(x); // guarda el resultado de la función minNumMonPD en el vector moneditas
     escribeRespuesta(x);

     return 0;
}

vector<int> minNumMonGR(int n){
     return minNumMonGR(n, monedas);
}

vector<int> minNumMonPD(int n){
     return minNumMonPD(n, monedas);
}

void escribeRespuesta(int n){
     escribeRespuesta(n, moneditas);
}