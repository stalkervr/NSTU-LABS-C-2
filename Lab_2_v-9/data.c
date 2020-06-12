#include "header.h"

student data_add(int* _last_id)
{
	student res;
	int _id = *_last_id + 1;
	char _buffer[35] = { 0 };
	*_last_id = _id;
	

	printf("  Введите данные данные нового студента для добавления в базу : ->  \n");
	
	printf("\n  Фамилия студента -> ");
	scanf("%s", &_buffer);
	strcpy(res.surname, _buffer);
	printf("\n  Имя студента -> ");
	scanf("%s", &_buffer);
	strcpy(res.name, _buffer);
	printf("\n  Отчество студента -> ");
	scanf("%s", &_buffer);
	strcpy(res.second_name, _buffer);

	res.id = _id;
	res.is_free = 0;
	fill_array(res.marks);
	res.marks_count = 0;
	res.marks_average = 0;
	res = add_marks(res);

	return res;
}

student* data_add_to_array(student* students, int* _count_record, int* _last_id, int* _count_free_items)
{
	//Поиск свободной переменной
	int index_free_item;
	if (students != NULL)
	{
		if (*_count_free_items != 0)
		{
			//поиск индекса свободной переменной
			index_free_item = search_index_free_item(students, _count_record);
			//запись данных по найденному индексу
			students[index_free_item] = data_add(_last_id);
			return students;
		}
		else {
			*_count_record = *_count_record + 1;
			students = (student*)realloc(students, *_count_record * sizeof(student));
			students[*_count_record - 1] = data_add(_last_id);
		}
	}
	else {
		*_count_record = *_count_record + 1;
		students = (student*)realloc(students, *_count_record * sizeof(student));
		students[*_count_record - 1]= data_add(_last_id);
	}
	return students;
}

void data_print(student* students, int* _count_record)
{
	if (students) {
		for (student* ptr = students; ptr < students + *_count_record; ptr++)
		{
			if (ptr->is_free == 0) {
				printf(" |%3d | %20s | %15s | %27s | %13d | %11f |\n", ptr->id, ptr->name, ptr->surname, ptr->second_name, ptr->marks_count, ptr->marks_average);
			}
		}
	}
	else {
		printf("  Отсутствуют записи в базе !\n");
	}
}

student add_marks(student item)
{
	int buffer[MARK_COUNT] = { 0 };
	int curent_mark = 0;
	int mark_count = item.marks_count;
	int stop_flag = 0;
	int _yes = 1;
	int _no = 0;
	int _answer;
	fill_array(buffer);
	

	while (stop_flag != 1) {
		printf("  Проставить оценки студенту д/н ? -> ");
		scanf("%d", &_answer);
		if (_answer == _yes)
		{
			mark_count = fill_array_random_mark(buffer);
			copy_array(buffer, item.marks, mark_count);
			item.marks_count = mark_count;
			item.marks_average = average_mark(item.marks);
			stop_flag = 1;
		}
		else
		{
			copy_array(buffer, item.marks, mark_count);
			item.marks_count = mark_count;
			item.marks_average = average_mark(item.marks);
			stop_flag = 1;
		}
	}

	/*printf("\n");
	printf("  Вводите оценки по одной и нажимайте ввод \n");
	printf("  чтобы завершить ввод введите -1 \n");

	while (stop_flag != 1)
	{
		printf("Оценка ->  ");
		scanf("%d", &curent_mark);
		if (curent_mark != -1) {
			mark_count = mark_count + 1;
			buffer[mark_count - 1] = curent_mark;
			item.marks_count = mark_count;
		}
		else stop_flag = 1;
	}*/
	
	stop_flag = 0;
	return item;
}

void copy_array(int* input_array, int* output_array, int count)
{
	for (int i = 0; i < count; i++) {
		output_array[i] = input_array[i];
	}
}

void fill_array(int* input_array)
{
	int count = MARK_COUNT;
	for (int i = 0; i < count; i++) {
		input_array[i] = 0;
	}
}

int count_marks_in_array(int* input_array)
{
	int i = 0;
	int count = 0;
	while (input_array[i] != -1) {
		count++;
	}
	return count;
}

student* clear_item(student* items, int* _count_record, int* _count_free_items)
{
	int _item_id = input_item_id();
	student* ptr = items;
	ptr = search_by_id(items, _item_id, _count_record);
	if (ptr != NULL)
	{
		ptr->is_free = 1;
	}
	else {
		printf("\n  Не найдено записи с введенным id = %d !!!\n", _item_id);
	}
	return items;
}

student* delete_item(student* items, int* _count_record)
{
	int _item_id = input_item_id();
	int _item_index = search_index_by_id(items, _count_record, _item_id);
	if (_item_index != -1) 
	{
		for (int i = _item_index; i < *_count_record; i++)
		{
			items[i] = items[i + 1];
		}
		(*_count_record)--;
	}
	else {
		printf("\n  Не найдено записи с введенным id = %d !!!\n", _item_id);
	}
	return items;
}

student* edit_item(student* items, int* _count_record)
{
	// оценки
	
	int stop_flag = 0;
	int mark_count = items->marks_count;
	int curent_mark = 0;
	//
	int _yes = 1;
	int _no = 0;
	int _answer = -1;
	char buffer[35] = { 0 };
	//
	int _item_id = input_item_id();
	int _item_index = search_index_by_id(items, _count_record, _item_id);
	if (_item_id != -1) // изменение персональных данных
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
					mark_count = mark_count + 1;
					items[_item_index].marks_count = mark_count;
					items[_item_index].marks[mark_count - 1] = curent_mark;
				}
				else stop_flag = 1;
				items[_item_index].marks_average = average_mark(items[_item_index].marks);
			}

		}
	}
	else {
		printf("\n  Не найдено записи с введенным id = %d !!!\n", _item_id);
	}
	return items;
}

student* search_by_id(student* items, int item_id, int* _count_record)
{
	if (items != NULL) {
		for (student* ptr = items; ptr < items + *_count_record; ptr++)
		{
			int _id = ptr->id; // не работает если присватвать внутри условия !!!!!
			if (_id == item_id) {
				return ptr;
			}
		}
	}
	return NULL;
}

int search_index_by_id(student* items, int* _count_record, int item_id)
{
	student* ptr;
	int i;
	if (items != NULL) {
		for (ptr = items, i = 0; ptr < items + *_count_record; ptr++, i++)
		{
			int _id = ptr->id; // не работает если присватвать внутри условия !!!!!
			if (_id == item_id) {
				return i;
			}
		}
	}
	return -1;
}

int input_item_id() 
{
	printf("\n");
	//printf("  Введите необходимый id записи ->  ");
	printf("  Для очистки/удаления/редактирования записи введите id записи ->  ");
	int _item_id;
	scanf("%d", &_item_id);
	return _item_id;
}

int count_free_items(student* items, int* _count_record)
{
	int count = 0;
	int _is_free;
	if (items != NULL) {
		for (student* ptr = items; ptr < items + *_count_record; ptr++)
		{
			_is_free = ptr->is_free;
			if (_is_free == 1) {
				count++;
			}
			
		}
	}
	return count;
}

int search_index_free_item(student* items, int* _count_record)
{
	student* ptr;
	int i;
	for (ptr = items, i = 0; ptr < items + *_count_record; ptr++, i++)
	{
		int _is_free = ptr->is_free; // не работает если присватвать внутри условия !!!!!
		if (_is_free == 1) {
			return i;
		}
	}
}

int random(int n)
{
	
	return rand()%n;
}

int take_random_mark(int left_range, int right_range)
{
	int _mark = random(right_range - left_range + 1) + left_range;
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

double average_mark(int* items)
{
	double average = 0;
	double sum = 0;
	int i = 0;
	while (items[i] != 0)
	{
		sum = sum + items[i];
		i++;
	}
	if (i == 0) {
		return average;
	}
	else {
		return average = sum / i;
	}
}