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

struct suffix
{
	int index;
	char *suff;
};

// A comparison function to compare two suffixes
int cmp(struct suffix a, struct suffix b)
{
	return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
int *buildSuffixArray(char *txt, int n)
{
	// A structure to store suffixes and their indexes
	struct suffix suffixes[n];

	// Store suffixes and their indexes in an array of structures.
	// The structure is needed to sort the suffixes alphabetically
	// and maintain their old indexes while sorting
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].suff = (txt+i);
	}

	// Sort the suffixes using the comparison function
	// defined above.
	sort(suffixes, suffixes+n, cmp);

	// Store indexes of all sorted suffixes in the suffix array
	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;

	// Return the suffix array
	return suffixArr;
}

// A utility function to print an array of given size
void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


#endif
