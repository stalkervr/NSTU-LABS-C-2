#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <locale.h>

double sum(int count, ...);
double sum_use_macros(int count,  ...);

int main()
{
    setlocale(LC_ALL, "RU-ru");

    printf("            Лабораторная работа № 4 вариант № 1\n\n");
    printf("  Задание : Разработать функцию с переменным числом параметров.\n");
    printf("            Для извлечения параметров из списка использовать операцию преобразования типа указателя.\n");
    printf("            Целая переменная - счетчик, затем последовательность вещественных переменных.\n");
    printf("            Функция возвращает сумму переменных.\n\n");
    printf("  Сумма аргументов функция без макросов => %.3f\n", sum(3, 50.1, 40.3, 30.3));
    printf("  Сумма аргументов функция с макросами  => %.3f\n", sum_use_macros(4, 2.1, 1.1, 3.1, NULL));
    getchar();
    return 0;
}

double sum(int count, ...)
{
    double result = 0;
    for (int* ptrArg = &count; count > 0;  count--)
    {
        ptrArg++;
        double ptrDouble;
        ptrDouble = *(double*)ptrArg++;
        result += ptrDouble;
    }
    return result;
}


double sum_use_macros(int count,  ...)
{
    double result = 0;
    va_list sumArgs;
    va_start(sumArgs, count);
    for (int i = 0; i < count; i++)
    {
        result += va_arg(sumArgs, double);
    }
    va_end(sumArgs);
    return result;
}

