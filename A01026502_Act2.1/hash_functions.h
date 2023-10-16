//Fernanda Osorio Arroyo - A01026502
//16 de Octubre del 2023
//Este archivo implementa las funciones necesarias para hacer hash strings
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <sstream>
#ifndef hash_functions_H
#define hash_functions_H

using namespace std;

string calculateHash(const string& filename, int n);

string calculateHash(const string& filename, int n) {

    //abrir el archivo
    ifstream file(filename);
    if (!file) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    //inicializar el vector de enteros, columnas y el caracter
    vector<int> a(n, 0);
    char ch;
    int columnIndex = 0;

    //leer cada caracter del archivo
    //sumar el valor del caracter a la columna correspondiente
    //usar static_cast para convertir el caracter a entero
    //si la columna es la última, regresar a la primera
    while (file.get(ch)) {
        a[columnIndex] += static_cast<int>(ch);
        columnIndex = (columnIndex + 1) % n;
    }

    //ostringstream para convertir los enteros a hexadecimal
    ostringstream hashStream;
    //iterar sobre el vector de enteros
    for (int i = 0; i < n; i++) {
        //asegurarse de que el valor del entero esté entre 0 y 255
        a[i] %= 256;
        //convertir el entero a hexadecimal
        //hex para indicar que se usará hexadecimal
        // setw(2) para que el ancho del campo sea de 2 caracteres
        //setfill('0') para que se rellenen los espacios con 0
        //ejemplo: 15 -> 0f
        //a[i] para indicar el entero a convertir
        hashStream << hex << setw(2) << setfill('0') << a[i];
    }

    return hashStream.str();
}

#endif