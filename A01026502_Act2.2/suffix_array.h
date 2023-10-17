//Fernanda Osorio Arroyo - A01026502
//16 de Octubre del 2023
//Este archivo implementa el algoritmo de suffix array 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#ifndef suffix_array_H
#define suffix_array_H

using namespace std;


//Declaraciones de funciones
void imprimirArreglo(int arr[], int n);
int *SuffixArray(char *txt, int n);


//función para imprimir el suffix array
//recibe un apuntador a un entero que es el suffix array y su tamaño
//complehidad O(n)
void imprimirArreglo(int arr[], int n){
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//inicializar la estructura suffix
//Complejidad O(1)
struct suffix{
	int index;
	char *suff;
};


//función para construir el suffix array
//recibe un string y su tamaño
//regresa un apuntador a un entero que es el suffix array

//complejidad O(n)
int *SuffixArray(char *txt, int n){
	//estructura para almacenar los sufijos y sus índices
	struct suffix sufijos[n];

	//iterar sobre el string y almacenar los sufijos y sus índices en la estructura
	//mientras se itera, se incrementa el apuntador al string
	for (int i = 0; i < n; i++)
	{
		sufijos[i].index = i;
		sufijos[i].suff = (txt+i);
	}

	//contar la frecuencia de cada caracter en el string
	int count[256] = {0};
	for (int i = 0; i < n; i++)
		count[static_cast<int>(txt[i])]++;

	//calcular la posición de inicio de cada caracter en el suffix array
	for (int i = 1; i < 256; i++)
		count[i] += count[i-1];

	//ordenar los sufijos usando counting sort
	int *suffixArr = new int[n];
	for (int i = n-1; i >= 0; i--)
	{
		int index = count[static_cast<int>(sufijos[i].suff[0])] - 1;
		suffixArr[index] = sufijos[i].index;
		count[static_cast<int>(sufijos[i].suff[0])]--;
	}

	//regresar el suffix array
	return suffixArr;
}



#endif
