//Fernanda Osorio Arroyo - A01026502
//16 de Octubre del 2023
//Este archivo implementa hash strings
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "hash_functions.h"

using namespace std;

string calculateHash(const string& filename, int n) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return "";
    }

    vector<int> a(n, 0);
    char ch;
    int columnIndex = 0;

    while (file.get(ch)) {
        a[columnIndex] += static_cast<int>(ch);
        columnIndex = (columnIndex + 1) % n;
    }

    ostringstream hashStream;
    for (int i = 0; i < n; i++) {
        a[i] %= 256;
        hashStream << hex << setw(2) << setfill('0') << a[i];
    }

    return hashStream.str();
}


int main(int argc, char *argv[]) {
    string filename;
    int n;

    cout << "Ingrese el nombre del archivo de texto: ";
    cin >> filename;

    cout << "Ingrese el valor de n (un entero múltiplo de 4, 16 <= n <= 64): ";
    cin >> n;

    if (n % 4 != 0 || n < 16 || n > 64) {
        cerr << "El valor de n no cumple con los requisitos." << endl;
        return 1;
    }

    string hash = calculateHash(filename, n);
    cout << "Resultado del hash: " << hash << endl;

    return 0;
}
