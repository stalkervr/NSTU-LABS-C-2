// Lection_3.cpp : СТРУКТУРЫ

#include <stdio.h>
#include <stdlib.h>

int main()
{
     /*struct Man это тип данных !!!!
     следовательно можно создать указатель данного типа
     и использовать для перебора массива структур*/



    struct Man {
        char name[10];
        int day;
        int month;
        int year;
        char* address;
    } ;

    char address[][20] = 
    { 
        "Hollywood",
        "NewYork",
        "Moskow",
        "Novosibirsk",
        "Tomsk"
    };

    struct Man A = { "Petrov",1,10,1977, *(address + 0)};

    struct Man X[10] = {
        { "Petrov1", 12, 11, 1978, *(address + 1) },
        { "Petrov2", 18, 10, 1968, *(address + 2) }
    };



    int n = sizeof(X) / sizeof(X[0]);

    /*for (int i = 0; i < n; i++) 
    {
        printf("Name: %s \t Address: %s\n\n", X[i].name, X[i].address);
    }*/

    for (struct Man* ptr = X; ptr < X + n; ptr++)
    {
        printf("Name: %s \t Address: %s\n\n", ptr->name, ptr->address);
    }

    typedef enum {
        SMALL = 25,
        MIDDLE,
        HIGH = 100,
        HIGHEST = 200
    } eSize;

    eSize var_size = HIGH;

    printf("%d", var_size);

    
    
        // struct Man это тип данных !!!!
        // следовательно можно создать указатель данного типа
        // и использовать для перебора массива структур
        //typedef struct {
        //    char name[10];
        //    int day;
        //    int month;
        //    int year;
        //    char* address;
        //} Man;

        //char address[][20] =
        //{
        //    "Hollywood",
        //    "NewYork",
        //    "Moskow",
        //    "Novosibirsk",
        //    "Tomsk"
        //};

        //Man A = { "Petrov",1,10,1977, *(address + 0) };

        //Man X[] = {
        //    { "Petrov1", 12, 11, 1978, *(address + 1) },
        //    { "Petrov2", 18, 10, 1968, *(address + 2) }
        //};

        //int n = sizeof(X) / sizeof(X[0]);

        //*for (int i = 0; i < n; i++)
        //{
        //    printf("Name: %s \t Address: %s\n\n", X[i].name, X[i].address);
        //}*/

        //for (Man* ptr = X; ptr < X + n; ptr++)
        //{
        //    printf("Name: %s \t Address: %s\n\n", ptr->name, ptr->address);
        //}

        return 0;
    }



    



