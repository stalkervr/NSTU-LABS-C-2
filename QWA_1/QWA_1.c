// QWA_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>

void	F4(char* p);
void	F10(char* p);
void	F9(char* p);
int* F3(int* p, int n);
void F7(char* p, char* q);
int	F8(char* p);

int main()
{
    int arr[] = { 10,21,3,30,5,6,7,8 };
    char* str = "teststring*/ddd/*dszdgszb";
    char* str1 = " axnd aa adxbxdf ";
    char* str2 = "zzzz";

    //printf("str1 - %s\n", str1);
    //printf("str2 - %s\n", str2);

    //F7(str1, str2);

    //printf("str1 - %d\n", F8(str1));
    //printf("str2 - %s\n", str2);

    //F4(str);
    //printf("%s\n", str);
    //F9(str);
    //printf("%s\n", str);

    
    //F3(arr, 8);
    //F4(str1);

    getchar();
    return 0;
}

#pragma region F1
//------------------------------------------------------- 1
// int a = 10;
// int b = 20;

// int* p1 = &a;
// int* p2 = &b;

// F1(p1,p2);
// c 10
// p1 20
// p2 10
// обмен местами значения которые лежат под p1 & p2
void	F1(int* p1, int* p2)
{
    int c;
    c = *p1;
    *p1 = *p2;
    *p2 = c;
}
#pragma endregion

#pragma region F2
//------------------------------------------------------- 2

void F2(int* p, int* q, int n)
{
    
    for (*q = *(p++); n > 0; n--, p++) {

        if (*p > * q) 
            *q = *p;
    }
}
#pragma endregion

#pragma region F3
//------------------------------------------------------- 3
// поик максимума в массиве
int* F3(int* p, int n)
{
    int* q;
    for (q = p; n > 0; n--, p++)
        if (*p > * q) q = p;
    return q;
}
#pragma endregion

#pragma region F4
//--- Указатели на строки (char*) ----------------------- 4
// переворачивает строку
void	F4(char* p)
{
    char* q = p;
    for (q ; *q != '\0'; q++);

    for (q--; p < q; p++, q--)
    {
        char c;
        c = *p;
        *p = *q; // ошибка
        *q = c;
    }
}
#pragma endregion

#pragma region F5
//------------------------------------------------------- 5
int	F5(char* p) // длинна строки
{
    int n;
    for (n = 0; *p != '\0'; p++, n++);
    return n;
}
#pragma endregion

#pragma region F6
//------------------------------------------------------- 6
// поиск подстроки в строке 
char* F6(char* p, char* q)
{
    char* s1, * s2;
    for (; *p != '\0'; p++)
    {
        for (s1 = p, s2 = q; *s2 != '\0' && *s1 == *s2; s1++, s2++);
        if (*s2 == '\0') return p;
    }
    return NULL;
}
#pragma endregion

#pragma region F7
//------------------------------------------------------- 7
// переписывает символы из q в з
void	F7(char* p, char* q)
{
    for (; *p != '\0'; p++);
    for (; *q != '\0'; *p++ = *q++); // ошибка
    *q = '\0';
}
#pragma endregion

#pragma region F8
//------------------------------------------------------- 8
// считает количество слов в предложении
int	F8(char* p)
{
    int n;
    if (*p == '\0') return (0);
    if (*p != ' ')  n = 1; else n = 0;
    for (p++; *p != '\0'; p++)
        if (p[0] != ' ' && p[-1] == ' ') n++;
    return n;
}
#pragma endregion

#pragma region F9
//------------------------------------------------------- 9
// удаляет пробелы из строки
void	F9(char* p)
{
    char* q; int n;
    for (n = 0, q = p; *p != '\0'; p++)
    {
        if (*p != ' ')
        {
            n = 0; *q++ = *p;
        }
        else
        {
            n++; if (n == 1) *q++ = *p;
        }
    }
}
#pragma endregion

#pragma region F10
//------------------------------------------------------ 10
// удаляет из стоки комментарии вида /* */
void	F10(char* p)
{
    char* q; int cm;
    for (q = p, cm = 0; *p != '\0'; p++)
    {
        if (p[0] == '*' && p[1] == '/') { cm--, p++; continue; }
        if (p[0] == '/' && p[1] == '*') { cm++, p++; continue; }
        if (cm == 0) *q++ = *p;
    }
    *q = 0;
}
#pragma endregion
