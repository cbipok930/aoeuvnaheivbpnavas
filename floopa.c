#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAXSIZE 30
int cmpH(const int* a,const int* b)
{
	return(*a - *b);
}
int cmpD(const int* a,const int* b)
{
	return((*a - *b) *(-1));
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void shuffle(int* arr, int n)
{
	for (int i = n - 1; i >= 1; --i)
	{
		int k = rand() % i;
		swap(&arr[i], &arr[k]);
	}	
}
int* func(int n, int max)
{
	int sizes_s = max + 1;
	int *sizes = malloc(sizes_s * sizeof(int)); // sizes of arrays
	for (int i = 0; i < sizes_s; ++i)
	{
		sizes[i] = 1 + i;
	}
	shuffle(sizes, sizes_s);
	shuffle(sizes, sizes_s);
	int** arr = malloc(n * sizeof(int*));// array of arrays
	for (int i = 0; i < n; ++i)
	{
		arr[i] = malloc(sizes[i]* sizeof(int));
		for (int j = 0; j < sizes[i]; ++j)
		{
			arr[i][j] = rand() - rand();
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(!(i % 2))
		qsort(arr[i], sizes[i], sizeof(int), cmpH);
		else
		qsort(arr[i], sizes[i], sizeof(int), cmpD);
	}
	return arr;
}
int main()
{
	int N;
	int maxsize = MAXSIZE;
	scanf("%d", &N); // arrays
	if (maxsize < N)
		maxsize = N;
	int** array = func(N, maxsize);
	return 0;
}