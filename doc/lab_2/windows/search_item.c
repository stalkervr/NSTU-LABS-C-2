
#include "header.h"

int search_index_free_item(student* items, int* _count_record)
{
    student* ptr;
    size_t i;
    for (ptr = items, i = 0; ptr < items + *_count_record; ptr++, i++)
    {
        int _is_free = ptr->is_free;
        if (_is_free == 1) {
            return i;
        }
    }
    return  -1;
}

int search_index_by_id(student* items, const int* _count_record, int item_id)
{
    student* ptr;
    size_t i;
    if (items != NULL) {
        for (ptr = items, i = 0; ptr < items + *_count_record; ptr++, i++)
        {
            int _id = ptr->id;
            if (_id == item_id) {
                return i;
            }
        }
    }
    return -1;
}

student* search_by_id(student* items, int item_id, const int* _count_record)
{
    if (items != NULL) {
        for (student* item = items; item < items + *_count_record; item++)
        {
            int _id = item->id;
            if (_id == item_id) {
                return item;
            }
        }
    }
    return NULL;
}

double search_min_average_marks(student* items, const int* _count_record)
{
    double _min = items->marks_average;
    double _tmp;
    if (items != NULL)
    {
        for (student* item = ++items; item < items + *_count_record; item++)
        {
            _tmp = item->marks_average;
            if (item->marks_count > 0)
            {
                _min = _tmp < _min ? _tmp : _min;
            }
        }
        return _min;
    }
    return -1.0;
}

double search_max_average_marks(student* items, const int* _count_record)
{
    double _max = items->marks_average;
    double _tmp;
    if (items != NULL)
    {
        for (student* item = ++items; item < items + *_count_record; item++)
        {
            _tmp = item->marks_average;
            if (item->marks_count > 0)
            {
                _max = _tmp > _max ? _tmp : _max;
            }
        }
        return _max;
    }
    return  -1.0;
}

void search_by_name(student* items, const int* _count_record)
{
    char input_name[30];
    char input_surname[30];
    int flag = 0;
    printf("  Введите фамилию студента для поиска - > ");
    scanf("%s", &input_surname);
    printf("  Введите имя студента для поиска - > ");
    scanf("%s", &input_name);
 
    if (items != 0) {
        for (student* item = items; item < items + *_count_record; item++)
        {
            int surname = strcmp(item->surname, input_surname);
            int name = strcmp(item->name, input_name);

            if (surname == 0 && name == 0)
            {
                print_one_record(item);
                flag = 1;
            }
        } 
    }
    if (flag == 0) {
        printf("  Не найдено записей с введёным именем !!!\n");
    }
}
