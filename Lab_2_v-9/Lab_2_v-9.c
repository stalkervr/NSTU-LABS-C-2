#include "header.h"
//int test(int*, int*);
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
	
	start(students, _count_record, _last_id, _count_free_items);
	return 0;
}

//int test(int* _p1, int* _p2) 
//{
//	*_p1 = *_p1 + 2;
//	*_p2 = *_p2 + 3;
//	return 0;
//}