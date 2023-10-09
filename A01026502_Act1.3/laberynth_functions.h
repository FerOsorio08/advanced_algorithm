// Fernanda Osorio Arroyo - A01026502
// 9 de Octubre del 2023
// Este archivo contiene las funciones para resolver el problema "Laberinto"
// utilizando el algoritmo de Backtracking y Branch and Bound
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
void ReadFile(string x, vector<vector<int> > &v);
void PrintMatrix(vector<vector<int> > v);
vector< vector <int > > Backtracking(vector<vector<int> > &v);
void Backtracking(vector<vector<int> > &v, vector<vector<int> > &solution, vector<vector<int> > &visited, int i, int j, bool &found, int di[], int dj[]);
void BranchBound();

// función para leer el archivo y guardar los datos en un vector de vectores
void ReadFile(string x, vector<vector<int> >& v) {
    string myText;
    ifstream MyReadFile(x);
    if (MyReadFile.is_open()) {
        // Leer primera línea del archivo
        if (getline(MyReadFile, myText)) {
            // Guardar el número de filas y columnas
            int spacePos = myText.find(" ");
            int rows = stoi(myText.substr(0, spacePos));
            int cols = stoi(myText.substr(spacePos + 1));

            // Inicializar la matriz con el número de filas y columnas especificado
            v.resize(rows, vector<int>(cols));

            // Leer el resto del archivo
            for (int i = 0; i < rows; i++) {
                if (getline(MyReadFile, myText)) {
                    for (int j = 0; j < cols; j++) {
                        v[i][j] = myText[j] - '0';
                    }
                } else {
                    cout << "Error: Not enough rows in the file." << endl;
                    break;
                }
            }
        } else {
            cout << "Error: Unable to read the dimensions of the matrix." << endl;
        }
        MyReadFile.close();
    } else {
        cout << "Error: Unable to open file" << endl;
    }
}


//función para imprimir el laberinto que recibe un vector de vectores
void PrintMatrix(vector<vector<int> > v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

//función que resuelve el laberinto usando el algoritmo de Backtracking
vector< vector <int > > Backtracking(vector<vector<int> > &v)
{
    vector<vector<int> > solution;
    vector<vector<int> > visited(v.size(), vector<int>(v[0].size(), 0));
    int di[] = { 1, 0, 0,-1 };
    int dj[] = { 0,-1, 1, 0 };
    int i = 0, j = 0;
    bool found = false;
    if (v[0][0]==1){
        Backtracking(v, solution, visited, i, j, found, di, dj);
    }
    return solution;

}

//función auxiliar para resolver el laberinto usando el algoritmo de Backtracking
void Backtracking(vector<vector<int> > &v, vector<vector<int> > &solution, vector<vector<int> > &visited, int i, int j, bool &found, int di[], int dj[]){
    // if (i == v.size() - 1 && j == v[0].size() - 1) {
    //     solution[i][j] = 1;
    //     found = true;
    //     return;
    // }
    // for (int k = 0; k < 4; k++){
    //     int nexti = i + di[k];
    //     int nextj = j + dj[k];
    //     if (nexti >= 0 && nexti < v.size() && nextj >= 0 && nextj < v[0].size() && v[nexti][nextj] == 1 && visited[nexti][nextj] == 0){
    //         visited[i][j] = 1;
    //         solution[i][j] = 1;
    //         Backtracking(v, solution, visited, nexti, nextj, found, di, dj);
    //         if (!found){
    //             solution[i][j] = 0;
    //             cout << solution[i][j] << endl;
    //         }
    //     }

    // }
    // if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] == 0 || visited[i][j] == 1) {
    //     return;
    // }
    // visited[i][j] = 1;
    // solution[i][j] = 1;
    // for (int k = 0; k < 4; k++) {
    //     if (!found) {
    //         Backtracking(v, solution, visited, i + di[k], j + dj[k], found, di, dj);
    //     }
    // }
    // if (!found) {
    //     solution[i][j] = 0;
    // }
    // return;
}

#endif