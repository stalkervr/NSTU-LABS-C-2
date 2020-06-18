#include "header.h"

void sort_by_surname(student* items, const int* _count_record)
{
    for (int i = 0; i < (*_count_record); i++)
    {
        for (int j = (*_count_record - 1); j > i; j--)
        {
            if (items[j - 1].surname[0] > items[j].surname[0])
            {
                student tmp = items[j - 1];
                items[j - 1] = items[j];
                items[j] = tmp;
            }
        }
    }
}

void sort_by_id(student* items, const int* _count_record)
{
    for (int i = 0; i < (*_count_record); i++)
    {
        for (int j = (*_count_record - 1); j > i; j--)
        {
            if (items[j - 1].id > items[j].id)
            {
                student tmp = items[j - 1];
                items[j - 1] = items[j];
                items[j] = tmp;
            }
        }
    }
}


