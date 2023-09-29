// Fernanda Osorio Arroyo - A01026502
// 28 de septiembre del 2023
// Este header contiene las funciones necesarias para utilizar el algoritmo de cambio de monedas

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#ifndef coinchange_H
#define coinchange_H

using namespace std;

// Declaraciones de funciones
void recibeDatos(int n, vector<int> &v);
void printVector(vector<int> v);
int readFile(string x, vector<int> &v);
int getChange(int n, int j);
vector<int> minNumMonGR(int n, vector<int> &v);
vector<int> minNumMonPD(int n, vector<int> &v);
void escribeRespuesta(int n, const vector<int> &v);

// función para imprimir el vector, recibe un vector de enteros
// regresa un 0 si se pudo imprimir el vector
// Complejidad O(n)
void recibeDatos(int n, vector<int> &v){
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingresa la denominacion de la moneda " << i + 1 << ": ";
        cin >> x;
        v.push_back(x);
    }
    return;
}

// función para imprimir el vector, recibe un vector de enteros
// regresa nulo y solo imprime el vector
// Complejidad O(n)
void printVector(vector<int> v){
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return;
}

// función para leer el archivo, recibe el nombre del archivo y un vector de enteros
// regresa un 0 si se pudo leer el archivo
// Complejidad O(n)
int readFile(string x, vector<int> &v){
    string myText;
    ifstream MyReadFile(x);
    if (MyReadFile.is_open())
    {
        // Leer primera linea del archivo
        if (getline(MyReadFile, myText))
        {
            int numLines = stoi(myText);

            // Leer el número de lineas indicado en la primera linea
            for (int i = 0; i < numLines; i++)
            {
                if (getline(MyReadFile, myText))
                {
                    v.push_back(stoi(myText));
                }
                else
                {
                    cout << "Error: Not enough lines in the file." << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Error: Unable to read the number of lines from the file." << endl;
        }

        MyReadFile.close();
    }
    else
        cout << "No se pudo abrir el archivo." << endl;

    // Close the file
    MyReadFile.close();
    return 0;
}

// función para calcular el cambio, recibe el pago y el costo
// regresa el cambio
// Complejidad O(1)
int getChange(int n, int j){
    int c;
    // cout << "\nEl cambio es: " << endl;
    c = n - j;
    return c;
}

// función para calcular el número mínimo de monedas con greedy, recibe el cambio y el vector de monedas
// regresa el vector de monedas
// Complejidad O(n)
vector<int> minNumMonGR(int n, vector<int> &v){
    sort(v.begin(), v.end()); // ordenar el vector de menor a mayor
    vector<int> monedas;      // vector para guardar las monedas
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (n >= v[i]) // mientras el cambio sea mayor o igual a la moneda
        {
            n = n - v[i];
            monedas.push_back(v[i]);
        }
    }
    // imprimir el vector de monedas
    cout << "\nEl numero minimo de monedas con greedy es: " << monedas.size() << endl;
    return monedas;
}

// función para calcular el número mínimo de monedas con programación dinámica, recibe el cambio y el vector de monedas
// regresa el vector de monedas
// Complejidad O(n^2)
vector<int> minNumMonPD(int n, vector<int> &v){
    sort(v.begin(), v.end());       // ordenar el vector de menor a mayor
    vector<int> monedas;            // vector para guardar las monedas
    vector<int> dp(n + 1, INT_MAX); // INT_MAX para que cualquier valor sea menor
    dp[0] = 0;                      // caso base
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size() && v[j] <= i; j++)
        {

            int sub_res = dp[i - v[j]]; // sub_res es el resultado de la subproblema
            if (sub_res != INT_MAX && sub_res + 1 < dp[i])
            {                        // si hay solución y es menor a la que ya se tiene
                dp[i] = sub_res + 1; // actualizar el valor de la solución
            }
        }
    }
    int remaining = n; // variable para guardar el cambio restante
    while (remaining > 0)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (dp[remaining] == dp[remaining - v[i]] + 1) // si es igual al valor de un moneda
            {
                monedas.push_back(v[i]); // agregar la moneda al vector
                remaining = remaining - v[i];
                break;
            }
        }
    }
    cout << "\nEl numero minimo de monedas con programación dinámica es: " << monedas.size() << endl;
    return monedas;
}

// función para imprimir el vector de monedas, recibe el vector de monedas
// regresa nulo y solo imprime el vector
// Complejidad O(n)
void escribeRespuesta(int n, const vector<int> &v){
    map<int, int> cuantasMon; // mapa para guardar las monedas
    for (int coin : v)
    { // por cada moneda en el vector
        cuantasMon[coin]++;
    }
    cout << "\nLas monedas son: " << endl;
    for (const auto &pair : cuantasMon)
    {                            // por cada par en el mapa
        int count = pair.second; // guardar el valor del par
        if (count == 1)
        {
            cout << "1 moneda de: " << pair.first << endl; // imprimir el valor de la moneda
        }
        else
        {
            cout << count << " monedas de: " << pair.first << endl; // imprimir el valor de la moneda
        }
    }
    cout << endl;
}

#endif