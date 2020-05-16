// Lab_4_v-1.cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sum(int n, ...);
double use_macr_sum(int n,  ...);

int main()
{
    /*double a[] = { 1.1, 2.2, 3.3 };

    int* pointer = &a;
    double d;
    d = *(double*)pointer;

    for (int i = 0; i < 3; i++)
    {
        printf("Load num %f \n", d);
        d++;
    }*/


    printf("Sum %3f\n", sum(3, 50.1, 40.3, 30.3));
    printf("Sum %3f\n", use_macr_sum(4, 2.1, 1.1, 3.1, NULL));
    getchar();
    return 0;
}

double sum(int n, ...)
{
    double result = 0;
    for (int* ptrArg = &n; n > 0;  n--)
    {
        ptrArg++;
        double d;
        d = *(double*)ptrArg++;
        printf("Load args -> %f\n", d);
        result += d;
    }
    return result;
}


double use_macr_sum(int n,  ...)
{
    double result = 0;
    va_list sumArgs;
    va_start(sumArgs, n);
    for (int i = 0; i < n; i++)
    {
        result += va_arg(sumArgs, double);
    }
    va_end(sumArgs);
    return result;
}
