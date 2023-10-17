// Fernanda Osorio Arroyo - A01026502
// 16 de Octubre del 2023
// Este archivo implementa hash strings
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "hash_functions.h"

using namespace std;

int main(int argc, char *argv[]){
    string filename;
    int n;

    cout << "Ingrese el nombre del archivo de texto: ";
    cin >> filename;

    cout << "Ingrese el valor de n (un entero múltiplo de 4, 16 <= n <= 64): ";
    cin >> n;

    if (n % 4 != 0 || n < 16 || n > 64)
    {
        cerr << "El valor de n no cumple con los requisitos." << endl;
        return 1;
    }

    string hash = calculateHash(filename, n);
    cout << "\x1B[1;32m"
         << "Texto con Hash: " << hash << "\x1B[0m" << endl;

    return 0;
}
