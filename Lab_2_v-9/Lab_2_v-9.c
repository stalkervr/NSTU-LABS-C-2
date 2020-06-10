#include "header.h"
int test(int*, int*);
int main()
{
	system("chcp 1251");
	system("mode 109,40");
	// последний сохраненный идентификатор
	int last_id = 0;
	int* _last_id = &last_id;
	// количество записей
	int count_record = 0;
	int* _count_record = &count_record;
	printf("Last id = %d", last_id);
	/*printf("Count record = %d", count_record);
	test(_last_id, _count_record);
	printf("Last id = %d", last_id);
	printf("Count record = %d", count_record);*/
	_getch();
	start(students, _count_record, _last_id);
	return 0;
}

int test(int* _p1, int* _p2) 
{
	*_p1 = *_p1 + 2;
	*_p2 = *_p2 + 3;
	return 0;
}