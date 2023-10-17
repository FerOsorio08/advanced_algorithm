//Fernanda Osorio Arroyo -A01026502
//16 de octubre del 2023
//Este archivo implementa el algoritmo de suffix array
#include <iostream>
#include <cstring>
#include <algorithm>
#include "suffix_array.h"
using namespace std;


int main(int argc, char *argv[]){
	// char txt[] = "banana";
	char txt[100];
	cout << "String" << endl;
	cin >> txt;
	int n = strlen(txt);
	int *suffixArr = SuffixArray(txt, n);
	cout << "Following is suffix array for " << txt << endl;
	imprimirArreglo(suffixArr, n);
	return 0;
}
