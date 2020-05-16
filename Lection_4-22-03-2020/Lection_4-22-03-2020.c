// Lection_4-22-03-2020.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//char* f(int a); // указатель на строку (символ)
//int** f1(int a); // указатель на указатель на целое
//struct man* f2(int n) {}; // указатель на структуру
//void* f3(int n) {}; // указатель на область памяти (без конкретизации типа данных)
//char* f4(int a, int b, int c = 3, int d = 4); // спараметрами по умолчанию 
//double foo(double ...); // функция с переменным кол параметров
//double foo1(...); // функция с переменным кол параметров
//double foo2(int k...); // функция с переменным кол параметров

int sum(int n, ...);
int sum1(int n, ...);
int sum2(int n, ...);
int marc_sum(int n, ...);

char* conCat(int n, char* str, ...);
char* marc_sum_char(int n, char* str, ...);

//struct Man {
//    char name[10];
//    int day;
//    int month;
//    int year;
//    char* address;
//};

int main()
{
    char* str;
    printf("Summ args of func %d \n", sum(1, 2, 3, 4, 0));
    printf("Summ args of func %d \n", sum1(4, 1, 2, 3, 4));
    printf("Summ args of func %d \n", sum1(5, 1, 2, 3, 4, 5));
    //printf("Concat of func %s \n", conCat(3, str, "abc"," def"," ghij", "\0"));
    printf("Summ args of func macros %d \n", marc_sum(5, 1, 2, 3, 10, NULL));
    //printf("Concat of func %s \n", marc_sum_char(4, "abc"," def", "dfg", NULL));
    getchar();
    return 0;
}

int sum(int n, ...)
{
    int result = 0;
    for (int* ptrArg = &n; *ptrArg > 0; ptrArg++) // *ptrArg значение аргумента
    {
        result += (*ptrArg);
    }
    return result;
}

int sum1(int n, ...)
{
    int result = 0;
    for (int* ptrArg = &n; n > 0; n--) // *ptrArg значение аргумента
    {
        result += (*ptrArg);
    }
    return result;
}

int sum2(int n, ...)
{
    int result = 0;
    int* ptrArg = &n;
    // ..................
    (char)ptrArg++;
    // ..................
    (int)ptrArg++;
    // ..................
    for (int* ptrArg = &n; n > 0; n--) // *ptrArg значение аргумента
    {
        result += (*ptrArg);
    }
    return result;
}

//char* conCat(int n, char* str, ...)
//{
//    char result[200];
//    int* N = &n;
//    for (char* ptrArg = &str; *N > 0; *N--)
//    {
//        strcat(result, (*ptrArg));
//        ptrArg++; // !!! переходим на след строку(аргумент)
//    }
//    return result;
//}

int marc_sum(int n, ...) 
{
    int result = 0;
    va_list sumArgs;
    va_start(sumArgs, n);
    for (int i = 0; i < n; i++)
    {
        result += va_arg(sumArgs, int);
    }
    va_end(sumArgs);
    return result;
}
// не работает !!!!
char* marc_sum_char(int n, char* str, ...)
{
    char result[200];
    va_list sumArgs;
    va_start(sumArgs, str);
    for (int i = 0; i < n; i++)
    {
        strcat_s(result, RSIZE_MAX ,va_arg(sumArgs ,char*));
    }
    va_end(sumArgs);
    return result;
}
