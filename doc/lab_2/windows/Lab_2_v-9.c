
#include "header.h"

//void key_search();
int main()
{
    srand(time(0));

    system("chcp 1251");
    system("mode 109,40");
    // последний сохраненный идентификатор
    int last_id = 0;
    int* _last_id = &last_id;
    // количество записей
    int count_record = 0;
    int* _count_record = &count_record;
    // количество записей
    int count_free_items = 0;
    int* _count_free_items = &count_free_items;
    //student* item;
    start(students, _count_record, _last_id, _count_free_items);
    //key_search();
    return 0;
}

//void key_search()
//{
//    int button1 = mygetch();
//    printf("Button1 -> %d", (int)button1);
//}