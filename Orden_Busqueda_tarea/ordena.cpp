//Fernanda Osorio Arroyo (A01026502)
//7 de septiembre del 2023
//Este programa ordena los datos de un archivo de texto utilizando los algoritmos de ordenamiento Merge Sort y Quick Sort
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ordena_funciones.h"
using namespace std;

int main(int argc, char *argv[]){
    vector<int> v; // vector para guardar los datos del archivo
    vector<int> v2;

    cout << "\x1B[1m"
         << "Merge sort:"
         << "\x1B[0m" << endl;
    readFile("ejemplo01.text", v);
    cout << "Datos desordenados: ";
    printVector(v);
    cout << endl;

    cout << "Datos ordenados: ";
    mergeSort(v, 0, v.size() - 1);
    printVector(v);
    cout << endl;

    cout << "\x1B[1m"
         << "Quick sort:"
         << "\x1B[0m" << endl;

    readFile("ejemplo02.text", v2);
    cout << "Datos desordenados: ";
    printVector(v2);
    cout << endl;

    int n = v2.size() / v2[0]; // tamaño del vector, se divide entre el número de columnas para obtener el número de filas
    cout << "Datos ordenados: ";
    quickSort(v2, 0, n - 1);
    printVector(v2);
    cout << endl;

    return 0;
}

