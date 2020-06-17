
#include "header.h"

student* clear_item(student* items, int* _count_record)
{
    int _item_id = input_item_id();
    student* item = search_by_id(items, _item_id, _count_record);
    if (item != NULL)
    {
        item->is_free = 1;
        return items;
    }
    else {
        print_not_found_error(_item_id);
    }
    return items;
}


