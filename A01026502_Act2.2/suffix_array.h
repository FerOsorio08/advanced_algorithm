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

//inicializar la estructura suffix
struct suffix
{
	int index;
	char *suff;
};

//función para comparar los sufijos de acuerdo al orden alfabético y regresar 1 si el primer sufijo es menor que el segundo
//recibe dos estructuras suffix
int cmp(struct suffix a, struct suffix b)
{
	return strcmp(a.suff, b.suff) < 0? 1 : 0;
}


//función para construir el suffix array
//recibe un string y su tamaño
//regresa un apuntador a un entero que es el suffix array
int *buildSuffixArray(char *txt, int n)
{
	//estructura para almacenar los sufijos y sus índices
	struct suffix suffixes[n];

    //iterar sobre el string y almacenar los sufijos y sus índices en la estructura
    //mientras se itera, se incrementa el apuntador al string
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].suff = (txt+i);
	}

	//ordenar los sufijos usando la función cmp
	sort(suffixes, suffixes+n, cmp);

	//guardar los índices de los sufijos ordenados en un arreglo
    //inicializar el arreglo con el tamaño del string
	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;

	//regresar el suffix array
	return suffixArr;
}

//función para imprimir el suffix array
//recibe un apuntador a un entero que es el suffix array y su tamaño
void imprimirArreglo(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


#endif
