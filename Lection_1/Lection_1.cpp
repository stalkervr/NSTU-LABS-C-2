// Лекция 19-02-2020

#include <stdio.h>
#include <stdlib.h>

void test(int*, int*, int*);
void print_abstract(void* pointer, int type_marker);

int main()
{
    int update = 5;
    int update_1 = 50;
    int update_2 = 500;

    int* pointer = &update;
    int* pointer_1 = &update_1;
    int* pointer_2 = &update_2;

    printf("update    - %d\n", update);
    printf("update_1  - %d\n", update_1);
    printf("update_2  - %d\n", update_2);
    printf("\n");

    test(pointer, pointer_1, pointer_2);

    printf("after call test \n\n");
    printf("update    - %d\n", update);
    printf("update_1  - %d\n", update_1);
    printf("update_2  - %d\n", update_2);
    printf("\n");

    int i = 20;
    int* pi = &i;
    int** ppi = &pi;
    int*** pppi = &ppi;

    printf("%d\n", i);
    *pi = 20;
    printf("%d\n", i);
    **ppi = 30;
    printf("%d\n", i);
    ***pppi = 40;
    printf("%d\n", i);
    printf("\n");

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    //int x = *(arr);
    //printf("%d\n", x);

    for (int i = 0; i < 10; i++) {
        printf("%3d", *(arr + i));
    }
    printf("\n\n");

    int* p = arr + 5;

    printf("%d\n", *(p));
    printf("%d\n", *(p-1));
    printf("%d\n", *(p+1));

    printf("\n\n");

    printf("%d\n", p[0]);
    printf("%d\n", p[-1]);
    printf("%d\n", p[1]);

    printf("\n\n");

    char c = 'w';
    int ii = 5;
    double d = 2.54;

    void* po;

    po = &c;
    print_abstract(po, 1);
    po = &ii;
    print_abstract(po, 2);
    po = &d;
    print_abstract(po, 3);
    print_abstract(po, 5);

    return 0;
}

void test(int* pointer, int* pointer_1, int* pointer_2)
{
    *pointer += 1;
    *pointer_1 += 1;
    *pointer_2 += 1;
}

void print_abstract(void* pointer, int type_marker)
{
    if (type_marker == 1) printf("%c\n", *(char*)pointer);
    else if (type_marker == 2) printf("%d\n", *(int*)pointer);
    else if (type_marker == 3) printf("%lf\n", *(double*)pointer);
    else {
        printf("Unknown type_marker");
        exit(1);
    }
}

