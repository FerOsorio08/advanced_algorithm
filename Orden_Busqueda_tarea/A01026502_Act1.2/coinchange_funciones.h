// Fernanda Osorio Arroyo - A01026502
// 28 de septiembre del 2023
// Este header contiene las funciones necesarias para utilizar el algoritmo de cambio de monedas

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
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
void escribeRespuesta(int n, const vector<int>& v);

// función para imprimir el vector, recibe un vector de enteros
// regresa un 0 si se pudo imprimir el vector
// Complejidad O(n)
void recibeDatos(int n, vector<int> &v)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingresa la denominacion de la moneda " << i + 1 << ": ";
        cin >> x;
        v.push_back(x);
    }
    return;
}

void printVector(vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return;
}

// función para leer el archivo, recibe el nombre del archivo y un vector de enteros
// regresa un 0 si se pudo leer el archivo
// Complejidad O(n)
int readFile(string x, vector<int> &v)
{
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

int getChange(int n, int j)
{
    int c;
    // cout << "\nEl cambio es: " << endl;
    c = n - j;
    return c;
}

vector<int> minNumMonGR(int n, vector<int> &v)
{
    sort(v.begin(), v.end()); // ordenar el vector de menor a mayor
    vector<int> monedas;      // vector para guardar las monedas
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (n >= v[i])
        {
            n = n - v[i];
            monedas.push_back(v[i]);
        }
    }
    // imprimir el vector de monedas
    cout << "\nEl numero minimo de monedas con greedy es: " << monedas.size() << endl;
    return monedas;
}

vector<int> minNumMonPD(int n, vector<int> &v)
{
    sort(v.begin(), v.end()); // ordenar el vector de menor a mayor
    vector<int> monedas;      // vector para guardar las monedas
    vector <int> dp(n+1, INT_MAX); //INT_MAX para indicar que no hay solución
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < v.size();j++){
            if (v[j] <= i){
                int sub_res = dp[i - v[j]]; //sub_res es el resultado de la subproblema
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]){ //si hay solución y es menor a la que ya se tiene
                    dp[i] = sub_res + 1; //actualizar el valor de la solución
                }
            }
        }
    }
    int remaining = n;
    while (remaining > 0){
        for (int i = 0; i < v.size();i++){
            if (dp[remaining] == dp[remaining - v[i]] + 1){
                monedas.push_back(v[i]);
                remaining = remaining - v[i];
                break;
            }
        }
    }
    cout << "\nEl numero minimo de monedas con programación dinámica es: " << monedas.size() << endl;
    return monedas;

}

void escribeRespuesta(int n, const vector<int>& v){
    cout << "\nLas monedas son: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

#endif