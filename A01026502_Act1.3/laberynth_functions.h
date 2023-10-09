//Fernanda Osorio Arroyo - A01026502
//9 de Octubre del 2023
//Este archivo contiene las funciones para resolver el problema "Laberinto" 
//utilizando el algoritmo de Backtracking y Branch and Bound
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#ifndef laberynth_H
#define laberynth_H

using namespace std;

// Declaraciones de funciones
void ReadFile(string x, vector<vector<int>> &v);
void Backtracking();
void BranchBound();



//función para leer el archivo y guardar los datos en un vector de vectores
void ReadFile(string x, vector<vector<int>> &v){
    string myText;
    ifstream MyReadFile(x);
    if (MyReadFile.is_open())
    {
        // Leer primera linea del archivo
        if (getline(MyReadFile, myText))
        {
            // Guardar el número de filas y columnas
            rows = stoi(myText.substr(0, myText.find(" ")));
            cols = stoi(myText.substr(myText.find(" ") + 1, myText.length()));
        }
        // Leer el resto del archivo
        while (getline(MyReadFile, myText))
        {
            vector<int> temp;
            for (int i = 0; i < myText.length(); i++)
            {
                temp.push_back(myText[i] - '0');
            }
            v.push_back(temp);
        }
        MyReadFile.close();
    }
    else
        cout << "Unable to open file";
    return;
}

#endif