#include "header.h"
//TODO: ѕереписать эту функцию с возвр указател€
student data_add(int* _last_id)
{
	student res;
	
	char _name[20];
	char _surname[20];
	char _second_name[50];
	int _free;

	printf("¬ведите данные данные нового студента дл€ добавлени€ в базу : ->  \n");
	scanf("%s %s %s %d", &_name, &_surname, &_second_name, &_free);
	res.id = *_last_id + 1;
	*_last_id = *_last_id + 1;
	res.free = _free;
	strcpy(res.name, _name);
	strcpy(res.surname, _surname);
	strcpy(res.second_name, _second_name);
	//res.ratings[0] = 0;
	res.number_of_rating = 0;
	res.average_rating = 0;
	res = add_marks(res);
	return res;
}

student* data_add_to_array(student* students, int* _count_record, int* _last_id)
{
	*_count_record = *_count_record + 1;
	students = (student*)realloc(students, *_count_record * sizeof(student));
	int pos = *_count_record - 1;
	students[pos]= data_add(_last_id);
	return students;
}

void data_print(student* students, int* _count_record)
{
	if (students) {
		for (student* ptr = students; ptr < students + *_count_record; ptr++)
		{
			if (ptr->free == 0) {
				printf(" |%3d | %20s | %15s | %27s | %13d | %11f |\n", ptr->id, ptr->name, ptr->surname, ptr->second_name, ptr->number_of_rating, 4.5);
			}
		}
	}
	else {
		printf("  ќтсутствуют записи в базе !\n");
	}
}

student add_marks(student item)
{
	int buffer[50] = { 0 };
	int curent_mark = 0;
	int mark_count = item.number_of_rating;
	//int* pointer_to_number_of_rating = item_for_add_mark->number_of_rating;
	int stop_flag = 0;
	printf("\n");
	printf("  ¬водите оценки по одной и нажимайте ввод \n");
	printf("  чтобы завершить ввод введите -1 \n");

	while (stop_flag != 1)
	{
		printf("ќценка ->  ");
		scanf("%d", &curent_mark);
		if (curent_mark != -1) {
			mark_count = mark_count + 1;
			buffer[mark_count - 1] = curent_mark;
			item.number_of_rating = mark_count;
		}
		else stop_flag = 1;
	}
	stop_flag = 0;
	return item;
}

