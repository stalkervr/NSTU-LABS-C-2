#include "header.h"

void copy_array(const int* input_array, int* output_array, int count)
{
    for (int i = 0; i < count; i++) {
        output_array[i] = input_array[i];
    }
}

void fill_array(int* input_array)
{
    int count = MARK_COUNT;
    for (int i = 0; i < count; i++) {
        input_array[i] = -1;
    }
}

int count_marks_in_array(const int* input_array)
{
    int count = 0;
    while (input_array[count] != -1) {
        count++;
    }
    return count;
}

int get_random(int n)
{
    return rand() % n;
}

int take_random_mark(int left_range, int right_range)
{
    int _mark = get_random(right_range - left_range + 1) + left_range;
    return _mark;
}

int fill_array_random_mark(int* items)
{
    int count;
    for (count = 0; count < 10; count++)
    {
        items[count] = take_random_mark(2, 5);
    }
    return count;
}

student add_test_item(int* _last_id)
{
    student item;
    int _id = *_last_id + 1;
    *_last_id = _id;

    strcpy(item.surname, "Иванов");
    strcpy(item.name, "Иван");
    strcpy(item.second_name, "Ивановичь");

    item.id = _id;
    item.is_free = 0;
    fill_array(item.marks);
    fill_array_random_mark(item.marks);
    item.marks_count = count_marks_in_array(item.marks);
    item.marks_average = average_mark(item.marks);
    return item;
}

student* add_test_data_to_array(student* items, int* _count_record,
    int* _last_id)
{
    *_count_record = *_count_record + 1;
    items = (student*)realloc(items, *_count_record * sizeof(student));
    items[*_count_record - 1] = add_test_item(_last_id);
    return items;

}




