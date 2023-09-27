#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "coinchange_funciones.h"
using namespace std;

int main(int argc, char *argv[])
{

    // Declaración de variables
    vector<int> v; // vector para guardar los datos del archivo
    vector<int> v2;

    readFile("ejemplo01coins.txt", v); // leer el archivo y guardar los datos en el vector v
    cout << "Posibles denomicaciones:" << endl;
    printVector(v); // imprimir el vector v
    readFile("cost.txt", v2);
    cout << "\x1B[1m"
         << "Usando Greedy Algorithm:"
         << "\x1B[0m" << endl;
    minNumMonGR(getChange(v2), v);

    return 0;
}