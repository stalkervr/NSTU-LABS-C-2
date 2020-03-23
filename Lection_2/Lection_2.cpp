// Lection_2. 4-03-2020
//

#include <stdio.h>
#include <stdlib.h>

void updatePtrs(size_t* ptrA, size_t* ptrB, size_t* val);


int main()
{
    size_t a = 5;
    size_t b = 50;
    size_t val = 10;

    size_t* ptrA = &a;
    size_t* ptrB = &b;
    size_t* pval = &val;

    size_t* ptrA = &a;
    size_t* ptrB = &b;
    size_t* pval = &val;

    int val1 = 4;

    const int* p; // нельзя поменять значение указателя
    int* const p1 = &val1; // нельзя поменять адресс указателя
    const int* const p2 = &val1; // нельзя поменять ни адресс ни значение указателя


    printf("%d  %d  %d\n", a, b, val);

    updatePtrs(ptrA, ptrB, pval);

    printf("%d  %d  %d\n", a, b, val);

    return 0;
}

void updatePtrs(size_t* ptrA, size_t* ptrB, size_t* val)
{
    *ptrA += *val;
    *ptrB += *val;
}
