
#include "header.h"

student* delete_item(student* items, int* _count_record)
{
    int _item_id = input_item_id();
    int _item_index = search_index_by_id(items, _count_record, _item_id);
    if (_item_index != -1)
    {
        for (size_t i = _item_index; i < *_count_record; i++)
        {
            items[i] = items[i + 1];
        }
        (*_count_record)--;
    }
    else {
        print_not_found_error(_item_id);
    }
    return items;
}

