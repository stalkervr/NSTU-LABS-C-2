
#include "header.h"

student* edit_item(student* items, int* _count_record)
{
    int stop_flag = 0;
    int mark_count;
    int curent_mark = 0;
    int _yes = 1;
    int _answer = -1;
    char buffer[35] = { 0 };
    int _item_id = input_item_id();
    int _item_index = search_index_by_id(items, _count_record, _item_id);
    // изменение персональных данных
    if (_item_index != -1)
    {
        printf("\n  Изменить фамилию студента д/н ? -> ");
        scanf("%d", &_answer);
        if (_answer == _yes)
        {
            printf("  Старая фамилия студента -> %s", items[_item_index].surname);
            printf("\n  Изменить фамилию студента на -> ");
            scanf("%s", buffer);
            strcpy(items[_item_index].surname, buffer);
        }
        printf("\n  Изменить имя студента д/н ? -> ");
        scanf("%d", &_answer);
        if (_answer == _yes)
        {
            printf("  Старое имя студента -> %s", items[_item_index].name);
            printf("\n  Изменить имя студента на -> ");
            scanf("%s", buffer);
            strcpy(items[_item_index].name, buffer);
        }
        printf("\n  Изменить отчество студента д/н ? -> ");
        scanf("%d", &_answer);
        if (_answer == _yes)
        {
            printf("  Старое отчество студента -> %s", items[_item_index].second_name);
            printf("\n  Изменить отчество студента на -> ");
            scanf("%s", buffer);
            strcpy(items[_item_index].second_name, buffer);
        }
        //
// добавление оценок
        printf("\n  Добавить оценки д/н ? -> ?");
        scanf("%d", &_answer);
        if (_answer == _yes) {
            printf("\n");
            printf("  Вводите оценки по одной и нажимайте ввод \n");
            printf("  чтобы завершить ввод введите -1 \n");
            while (stop_flag != 1)
            {
                printf("  Оценка ->  ");
                scanf("%d", &curent_mark);
                if (curent_mark != -1) {
                    if (curent_mark < 2 || curent_mark > 5)
                    {
                        curent_mark = 0;
                        mark_count = items[_item_index].marks_count;
                    }
                    else {
                        mark_count = items[_item_index].marks_count + 1;// увелич к-во оценок
                    }
                    items[_item_index].marks_count = mark_count;
                    items[_item_index].marks[mark_count - 1] = curent_mark;// записываем  оценку
                }
                else {
                    stop_flag = 1;
                }
                items[_item_index].marks_average = average_mark(items[_item_index].marks);
            }
        }
    }
    else {
        print_not_found_error(_item_id);
    }
    return items;
}

