// QWA_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;
#include <iostream>

double F10(int a1, ...);
void F1(char* p, ...);
int F8(int a1, ...);
char* F7(char* p, ...);
int F4(int p[], int a1, ...);
int F13(char* p, ...);
void F2(int* p, ...);

double F9(int p, ...);

union xx { int* pi; long* pl; double* pd; };


int main()
{
	//char test[] = "Hello ";
	//int test2[] = { 1,2,3,4,5 };
	//char t = 3;

	//char* _t = &t;
	cout << "Res = " << F9(3, 2.2, 0) << endl;

 //   cout << "Res = " << F10(4, 2.1, 1.1, 2.3)<< endl;
	//cout << "Res = " << F8(3, 2, 5, 2, 0) << endl;


	//for (int i = 0; i < 5; i++) {
	//	printf("Arr - %d\n", test2[i]);
	//}
	////cout << "Res F4 = " << F4(test2, 7, 6, 0) << endl;
	////F2(test2, 7, 6, NULL);
	//for (int i = 0; i < 5; i++) {
	//	printf("Arr - %d\n", test2[i]);
	//}
	//F1(test, "test ", "work " , NULL );
	//cout << "Res = " << F7(test, "tes000000", "tes00000011111",  NULL) << endl;
	//cout << "Res F13 = " << F13(_t, '5', '2') << endl;
	getchar();
}


#pragma region F1
//--------------------------------------------------------1
// присоединяет переданные слова к строке
void F1(char* p, ...)
{
	char** q;
	for (q = &p; *q != NULL; q++) 
		cout << *q;
}
#pragma endregion


//--------------------------------------------------------2
// 
void F2(int* p, ...)
{
	int** q, i, d;

	for (i = 1, q = &p, d = *p; q[i] != NULL; i++)
		*q[i - 1] = *q[i];

	*q[i - 1] = d;
}


//--------------------------------------------------------3
int* F3(int* p, ...)
{
	int** q, i, * s;
	for (i = 1, q = &p, s = p; q[i] != NULL; i++)
		if (*q[i] > * s) s = q[i];
	return s;
}

#pragma region F4
//--------------------------------------------------------4
// записывае в массив р переданные агруметы зав 0
int F4(int p[], int a1, ...)
{
	int* q, i;
	for (i = 0, q = &a1; q[i] > 0; i++)
		p[i] = q[i];
	return i;
}

#pragma endregion


#pragma region F5
//--------------------------------------------------------5
// int p маркер типа для считывания и вывода данных
union x { int* pi; long* pl; double* pd; };
void F5(int p, ...)
{
	union x ptr;
	for (ptr.pi = &p; *ptr.pi != 0; )
	{
		switch (*ptr.pi++)
		{
		case 1: cout << *ptr.pi++; break;
		case 2: cout << *ptr.pl++; break;
		case 3: cout << *ptr.pd++; break;
		}
	}
}
#pragma endregion



//--------------------------------------------------------6
char** F6(char* p, ...)
{
	char** q, ** s;
	int i, n;
	for (n = 0, q = &p; q[n] != NULL; n++);
	s = new char* [n + 1];
	for (i = 0, q = &p; q[i] != NULL; i++) s[i] = q[i];
	s[n] = NULL;
	return s;
}

#pragma region F7
//--------------------------------------------------------7
// сравнивает длинну строки переданной первым параметром с остальн перед
// и возвр указатель на самую длинную
char* F7(char* p, ...)
{
	char** q; int i, n;
	for (i = 0, n = 0, q = &p; q[i] != NULL; i++)
		if (strlen(q[i]) > strlen(q[n])) n = i;
	return q[n];
}
#pragma endregion

#pragma region F8
//--------------------------------------------------------8
// считает сумму аргументов целого типа
int F8(int a1, ...)
{
	int* q, i, s;
	for (s = 0, i = 0, q = &a1; *q > 0; q++)
		s += *q;
	return s;
}
#pragma endregion

#pragma region F9
//--------------------------------------------------------9
// p - это маркер типа передав аргументов посл арг = 0
//union xx { int* pi; long* pl; double* pd; };
double F9(int p, ...)
{
	union xx ptr;
	double dd = 0;
	for (ptr.pi = &p; *ptr.pi != 0; )
	{
		switch (*ptr.pi++)
		{
		case 1: dd += *ptr.pi++; break;
		case 2: dd += *ptr.pl++; break;
		case 3: dd += *ptr.pd++; break;
		}
	}
	return dd;
}
#pragma endregion


#pragma region F10
//------------------------------------------------------10
// считает сумму аргументов типа double
// F10(4, 2.1, 1.1, 2.3)
double F10(int a1, ...)
{
	double s, * q; int i, n;
	for (s = 0, n = a1, q = (double*)(&a1 + 1); n != 0; n--)
		s += *q++;
	return s;
}
#pragma endregion

#pragma region F11
//-------------------------------------------------------11
// сумма вещественных аргументов последн = 0
//double F11(int a1, ...)
//{
//	double s = 0;
//	int* p = &a1;
//	while (*p != 0)
//	{
//		if (*p > 0) s += *p++;
//		else
//		{
//			p++; s += *((double*)p)++;
//		}
//	}
//	return s;
//}
#pragma endregion

#pragma region F12
////--------------------------------------------------------12
// первый параметр задает тип аргументов далее подсчёт суммы
// последний аргумент 0
//double F12(char* p, ...)
//{
//	double s;
//	int* q = (int*)(&p + 1);
//	for (; *p != 0; p++)
//		switch (*p)
//		{
//		case 'd': s += *q++; break;
//		case 'f': s += *((double*)q)++; break;
//		case 'l': s += *((long*)q)++; break;
//		}
//	return s;
//}
#pragma endregion

////--------------------------------------------------------13
//
int F13(char* p, ...)
{
	int s = 0;
	int* q = (int*)(&p + 1);
	for (; *p != 0; p++)
		if (*p >= '0' && *p <= '9') s += q[*p - '0'];
	return s;
}

#pragma region F14
//--------------------------------------------------------14
// p - это маркер типа передав аргументов посл арг = 0
//double F14(int p, ...)
//{
//	double dd = 0;
//	int* q = &p;
//	for (; *q != 0; )
//	{
//		switch (*q++)
//		{
//		case 1: dd += *q++; break;
//		case 2: dd += *((long*)q)++; break;
//		case 3: dd += *((double*)q)++; break;
//		}
//	}
//	return dd;
//}
#pragma endregion


