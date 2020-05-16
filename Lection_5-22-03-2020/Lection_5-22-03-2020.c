// Lection_5-22-03-2020.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include <iostream>
//using std::cout;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

int* GetArray(int size);
int* GetArray1(int N);
char* Concat(char* p1, char* p2);
int* sum();

int main()
{
	int* A = (int*)malloc(8 * sizeof(int));

	int* B = (int*)calloc(8 , sizeof(int));

	char** C = (char**)calloc(8, sizeof(char));
	C[0] = (char*)malloc(15 * sizeof(char));
	C[1] = (char*)malloc(15 * sizeof(char));
	C[2] = (char*)malloc(15 * sizeof(char));
	C[3] = (char*)malloc(15 * sizeof(char));
	C[4] = (char*)malloc(15 * sizeof(char));
	C[5] = (char*)malloc(15 * sizeof(char));
	C[6] = (char*)malloc(15 * sizeof(char));
	C[7] = (char*)malloc(15 * sizeof(char));

	int* D = (int*)malloc(8 * sizeof(int));
	D[0] = 5;
	//D + 1 = 6;

	int* E = sum();
	E = NULL;
	free(E);
	
	for (int* ptr = A; ptr<=&A[7]; ptr++) 
	{
		printf("%d %d\n\n", ptr, *ptr);
	}

	for (int* ptr = B; ptr <= &B[7]; ptr++) 
	{
		printf("%d %d\n\n", ptr, *ptr);
	}

	A = NULL; // нужно для того чтобы очистка памяти прошла правильно
	B = NULL;
	C = NULL;
	D = NULL;
	free(A);
	free(B);
	free(C);
	free(D);

	char* text = (char*)malloc(0 * sizeof(char));// Лучьше так не делать

	char* text = (char*)malloc(5 * sizeof(char));

	text = "abcdef";



	int* pd;
	pd = malloc(sizeof(int));
	if (pd != NULL)
	{
		*pd = 5;
		free(pd);
	}
	getchar();
	return 0;
}

int* sum() 
{
	int* AinFunc = (int*)malloc(10 * sizeof(int));
	return AinFunc;
}

int* GetArray(int size)
{
	int* p;
	if (p = malloc(size * sizeof(int)) == NULL)
	{
		printf("Lack of memory");
		return p;
	}
	for (int i = 0; i < size; ++i)
		*(p + i) = rand() % 10;
	return p;
}

//int* GetArray1(int N)
//{
//	int i, * p;
//
//	p = malloc(N * sizeof(int));
//	for (i = 0; i < N; ++i)
//		*(p + i) = rand() % 10;
//
//	if ((i + 1) == N)
//	{
//		int* q = malloc((i + 1 + N) * sizeof(int));
//		for (i = 0; i < N; ++i)
//			*q[i] = *p[i];
//		free(p);
//		p = q;
//		return p;
//	}
//}
//
//char* Concat(char* p1, char* p2)
//{
//	char* out;
//	int n1, n2;
//	for (n1 = 0; p1[n1] = '\0'; ++n1);
//	for (n2 = 0; p2[n2] = '\0'; ++n2);
//	if (out = calloc(n1 + n2, sizeof(int)) == NULL)
//		return NULL;
//
//	for (n1 = 0; p1[n1] != '\0'; out[n1++] = p1[n2++]);
//	for (n2 = 0; p2[n2] != '\0'; out[n1++] = p2[n2++]);
//	out[n1] = '\0';
//	return out;
//}


