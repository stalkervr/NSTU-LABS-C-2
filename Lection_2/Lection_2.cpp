// Lection_2. 4-03-2020
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define NULL 0




int main()
{
    size_t a = 5;
    size_t b = 50;
    size_t val = 10;

    int val1 = 4;

    const int* p; // нельзя поменять значение указателя
    int* const p1 = &val1; // нельзя поменять адресс указателя
    const int* const p2 = &val1; // нельзя поменять ни адресс ни значение указателя


    printf("%d  %d  %d\n", a, b, val);

    updatePtrs(&a, &b, &val);

    printf("%d  %d  %d\n", a, b, val);

    // НУЛЕВОЙ УКАЗАТЕЛЬ

    int* ptr(0); // ptr теперь нулевой указатель
    int* ptr1; // ptr1 не инициализирован
    ptr1 = 0; // ptr1 теперь нулевой указатель

    double* ptr2(0);
    if (ptr2) {
        printf("Pointer to double");
    }
    else {
        printf("NULL pointer");
    }

    return 0;
}
