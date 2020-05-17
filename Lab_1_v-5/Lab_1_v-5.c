#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char* inner_search(char*, char*, char*);
void search_wrapper(char*, char*, char*);

int main()
{
    setlocale(LC_ALL, "RU-ru");
    printf("----------------------------------------------------------------------------------------------- \n\n");
    printf("            Лабораторная работа № 1 вариант № 5\n\n");
    printf("  Задание : Функция находит в строке пары инвертированных фрагментов .\n");
    printf("            например \"123apr\" и \"rpa321\"\  и возвращает указатель на первый.\n");
    printf("            С помощью функции найти все пары.\n\n");
    printf("----------------------------------------------------------------------------------------------- \n\n");
    //  тестовые строки для поиска
    char* str  = "xxx 123apr aaadffdz 123apr bbbdffd 123apr cccdffd rpa321 dfgdhxgnfgxh 123apr cccdfhn rpa321 xbf";
    char* str1 = "xxx 123apr aaadffdz 123apr bbbdffd  dfgdhxgnfgxh 123apr cccdfhn  xbf";
    char* str2 = "xxx  aaadffdz  bbbdffd rpa321 dfgdhxgnfgxh  cccdfhn rpa321 xbf";
    char* str3 = "rpa321 xxx 123apr aaadffdz 123apr bbbdffd rpa321 dfgdhxgnfgxh 123apr cccdfhn rpa321 xbf";
    
    // фрагменты для поиска
    char* _str1 = "123apr";
    char* _str2 = "rpa321";

    // тестирование работы функции
    search_wrapper(str, _str1, _str2);
    search_wrapper(str1, _str1, _str2);
    search_wrapper(str2, _str1, _str2);
    search_wrapper(str3, _str1, _str2);
    getchar();

    return 0;
}

void search_wrapper(char* str, char* _str1, char* _str2) 
{
    printf(">> Исходная строка для поиска \n%s\n\n", str);

    int count = 0;
    char* start_next_point = str;

    while (strstr(start_next_point, _str1) && strstr(start_next_point, _str2))
    {
        if (strstr(start_next_point, _str2) < strstr(start_next_point, _str1)) 
        {
            start_next_point = strstr(start_next_point, _str1);
        }
        inner_search(start_next_point, _str1, _str2);
        printf("%s\n", inner_search(start_next_point, _str1, _str2));
        count++;
        start_next_point = inner_search(start_next_point, _str1, _str2) + strlen(_str1);
        inner_search(start_next_point, _str1, _str2);
    }
    printf("Поиск завершон ... найдено %d фрагментов \n\n",count);
    printf("----------------------------------------------------------------------------------------------- \n\n", count);
}

char* inner_search(char* str, char* str1, char* str2)
{
    // указатель на фрагмент
    char* pointer1 = (strstr(str, str1));
    // указатель на инвертированный фрагмент
    char* pointer2 = (strstr(str, str2));
    // указатель на точку продолжения поиска
    char* start_next_point = pointer1 + strlen(str1);
  
    while (pointer1 != NULL && strstr(start_next_point, str1) && (strstr(start_next_point, str1) < pointer2))
    {
        pointer1 = strstr(start_next_point, str1);
        start_next_point = pointer1 + strlen(str1);
    }
    return pointer1;
}

