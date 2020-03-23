#include "function.h"

void updatePtrs(size_t* ptrA, size_t* ptrB, size_t* val)
{
    *ptrA += *val;
    *ptrB += *val;
}
