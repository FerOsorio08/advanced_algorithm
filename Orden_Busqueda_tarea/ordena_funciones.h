//Fernanda Osorio Arroyo (A01026502)
//7 de septiembre del 2023
//Este header contiene las funciones para ordenar los datos de un archivo de texto utilizando los algoritmos de ordenamiento Merge Sort y Quick Sort
#include <iostream>
#include <fstream>
#include <string>
#ifndef ordena_H
#define ordena_H


using namespace std;
// Declaraciones de funciones

int printVector(vector<int> v);
int readFile (string x, vector<int>& v);
void merge(vector<int>& v, int low, int mid, int high);
void mergeSort(vector<int>& v, int low, int high);
void quickSort(vector<int>& v, int low, int high);
void swap(int *a, int *b);
int partition(vector<int> &v, int low, int high);
void quickSort(vector<int> &v, int low, int high);


//función para imprimir el vector, recibe un vector de enteros
//regresa un 0 si se pudo imprimir el vector
//Complejidad O(n)
int printVector(vector<int> v){
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return 0;
}

//función para leer el archivo, recibe el nombre del archivo y un vector de enteros
//regresa un 0 si se pudo leer el archivo
//Complejidad O(n)
int readFile (string x, vector<int>& v){
    string myText;
    ifstream MyReadFile(x);
    if (MyReadFile.is_open())
    {
        // Leer primera linea del archivo
        if (getline(MyReadFile, myText)) {
            int numLines = stoi(myText);
            
            // Leer el número de lineas indicado en la primera linea
            for (int i = 0; i < numLines; i++) {
                if (getline(MyReadFile, myText)) {
                    v.push_back(stoi(myText));
                }
                else {
                    cout << "Error: Not enough lines in the file." << endl;
                    break;
                }
            }
        }
        else {
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

//merge sort
//recibe un vector de enteros, el índice más bajo y el más alto
//regresa un 0 si se pudo ordenar el vector
//Complejidad O(n log n)
void mergeSort(vector<int>& v, int low, int high){
    // si high es menor o igual que low, no hay nada que ordenar
    if (high <= low) 
        return;
    
    int mid = low + (high - low) / 2;
    // cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
    mergeSort(v, low, mid); // ordernar la mitad izquierda
    mergeSort(v, mid + 1, high); // ordenar la mitad derecha
    merge(v, low, mid, high); // unir las dos mitades
}

//función para unir las dos mitades
//recibe un vector de enteros, el índice más bajo, el índice medio y el más alto
//no regresa nada
// Complejidad O(n)
void merge( vector<int>& v, int low, int mid, int high){
    int n1 = mid - low + 1; // tamaño de la mitad izquierda
    int n2 = high - mid; // tamaño de la mitad derecha

    vector<int> L(n1); // se usan vectores auxiliares para guardar los datos de cada mitad
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = v[low + i]; // guardar los datos de la mitad izquierda en el vector auxiliar
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j]; // guardar los datos de la mitad derecha en el vector auxiliar
    
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        // si el elemento de la mitad izquierda es menor o igual que el de la derecha, se guarda en el vector original
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        // si quedan elementos en la mitad izquierda, se guardan en el vector original
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        // si quedan elementos en la mitad derecha, se guardan en el vector original
        v[k] = R[j];
        j++;
        k++;
    }

    return;
   
}

//quick sort
//recibe un vector de enteros, el índice más bajo y el más alto
//no regresa nada
// Complejidad O(n log n)
void quickSort(vector<int> &v, int low, int high){
    // si low es menor que high, se ordena el vector, si no, no hay nada que ordenar
    if (low < high)
    {
        int p = partition(v, low, high); // se obtiene el pivote
        quickSort(v, low, p - 1); // se ordena la mitad izquierda
        quickSort(v, p + 1, high); // se ordena la mitad derecha
    }
}

//función para obtener el pivote
//recibe un vector de enteros, el índice más bajo y el más alto
//regresa el índice del pivote
//Complejidad O(n)
int partition(vector<int> &v, int low, int high){
    int pivot = v[high]; // se toma el último elemento como pivote
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] < pivot) // si el elemento es menor que el pivote, se intercambian
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]); // se intercambia el pivote con el elemento siguiente

    return (i + 1);
}

//función para intercambiar dos elementos
//recibe dos apuntadores a enteros
//no regresa nada
//Complejidad O(1)
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}



#endif