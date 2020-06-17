
#include "header.h"

student data_add(int* _last_id)
{
    student item;
    int _id = *_last_id + 1;
    char _buffer[35];
    *_last_id = _id;

    printf("  ������� ������ ������ ������ �������� ��� ���������� � ���� : ->  \n");

    printf("\n  ������� �������� -> ");
    scanf("%s", &_buffer);
    strcpy(item.surname, _buffer);
    printf("\n  ��� �������� -> ");
    scanf("%s", &_buffer);
    strcpy(item.name, _buffer);
    printf("\n  �������� �������� -> ");
    scanf("%s", &_buffer);
    strcpy(item.second_name, _buffer);

    item.id = _id;
    item.is_free = 0;
    fill_array(item.marks);
    item.marks_count = 0;
    item.marks_average = 0;
    item = add_marks(item);

    return item;
}

student* data_add_to_array(student* items, int* _count_record,
    int* _last_id, const int* _count_free_items)
{
    //����� ��������� ����������
    size_t index_free_item;
    if (items != NULL)
    {
        if (*_count_free_items != 0)
        {
            //����� ������� ��������� ����������
            index_free_item = search_index_free_item(items, _count_record);
            //������ ������ �� ���������� �������
            items[index_free_item] = data_add(_last_id);
            return items;
        }
        else {
            *_count_record = *_count_record + 1;
            items = (student*)realloc(items, *_count_record * sizeof(student));
            items[*_count_record - 1] = data_add(_last_id);
        }
    }
    else {
        *_count_record = *_count_record + 1;
        items = (student*)realloc(items, *_count_record * sizeof(student));
        items[*_count_record - 1] = data_add(_last_id);
    }
    return items;
}

student add_marks(student item)
{
    int curent_mark = 0;
    int mark_count = item.marks_count;
    int stop_flag = 0;
    int _yes = 1;
    int _no = 0;
    int _answer;
    printf("\n  �������� ������ �/� ? -> ?");
    scanf("%d", &_answer);
    if (_answer == _yes) {
        printf("\n");
        printf("  ������� ������ �� ����� � ��������� ���� \n");
        printf("  ����� ��������� ���� ������� -1 \n");

        while (stop_flag != 1) {
            printf("  ������ ->  ");
            scanf("%d", &curent_mark);
            if (curent_mark != -1) {
                if (curent_mark < 2 || curent_mark > 5)
                {
                    curent_mark = 0;
                    mark_count = mark_count;
                }
                else {
                    mark_count = mark_count + 1;
                }
                item.marks[mark_count - 1] = curent_mark;
                item.marks_count = mark_count;
                item.marks_average = average_mark(item.marks);
            }
            else stop_flag = 1;
        }
    }
    return item;
}
//TODO Rewrite this function
double average_mark(const int* items)
{
    double average = 0;
    double sum = 0;
    int i = 0;
    while (items[i] != -1)
    {
        sum = sum + items[i];
        i++;
    }
    return i == 0 ? average : (average = sum / i);
}
//
int input_item_id()
{
    int _item_id = 0;
    printf("\n");
    printf("  ��� �������/��������/�������������� ������ ������� id ������ ->  ");
    scanf("%d", &_item_id);
    return _item_id;
}
