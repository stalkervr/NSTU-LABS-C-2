#include "header.h"

void print_menu_header()
{
	printf("\n");
	print_line();
	printf(" | ESC -> Выход.         | Shift+A -> Добавить.      | Shift+D -> Удалить.    | Shift+S ->  Сортировать.   |\n");
	printf(" | Enter -> Загрузить.   | Shift+E -> Редактировать. | Shift+C -> Очистить.   | Shift+F ->  Запуск поиск.  |\n");
	print_line();
	printf("\n");
}

void print_table_header()
{
	//printf("\n");
	print_line();
	// body
	printf(" | Id | Фамилия              | Имя             | Отчество                    | Кол-во оценок | Средний бал |\n");
	print_line();
	//printf("\n");
}

void print_one_record()
{

}

void print_search_header()
{
	printf("\n");
	print_line();
	// body
	printf(" | Поиск по минимальному среднему балу  ||  |\n");
	print_line();
	printf("\n");
}

void print_footer(int* _count_record, int* _count_free_items, student* items)
{
	*_count_free_items = count_free_items(items, _count_record);
	printf("\n");
	print_line();
	printf(" | <<<< Назад 10 зап.   ||     Всего записей ->  %3d     ||  Свободно ->  %3d    ||    Вперёд 10 зап. >>>> |\n",
		*_count_record,*_count_free_items);
	print_line();
	printf("\n");
}

void print_line()
{
	printf(" ");
	for (int i = 0; i < 107; i++) {
		printf("-");
	}
	printf("\n");
}

void info()
{
	printf("\n\t\t\tИнформатика и программирование Ч-2. Лабораторная работа №2 вариант №9.\n\n");
	printf("  Задание : \n");
	printf("\t    Определить структурированный тип, определить набор функций для работы с массивом структур.\n");
	printf("\t  В  структурированной переменной предусмотреть способ отметки ее как \n\t  не содержащей данных (т.е. ""пустой"").\n");
	printf("\t  Функции должны работать с массивом структур или с отдельной структурой через указатели,\n");
	printf("\t  а также при необходимости возвращать указатель на структуру. \n\n\t  В перечень функций входят:\n\n");
	printf("\t  - «очистка» структурированных переменных;\n");
	printf("\t  - поиск свободной структурированной переменной;\n");
	printf("\t  - ввод элементов (полей) структуры с клавиатуры;\n");
	printf("\t  - вывод элементов (полей) структуры с клавиатуры;\n");
	printf("\t  - поиск в массиве структуры и минимальным значением  заданного поля;\n");
	printf("\t  - сортировка массива  структур в порядке возрастания заданного поля\n");
	printf("\t    (при сортировке можно использовать тот факт, что в Си++ разрешается\n");
	printf("\t    присваивание структурированных переменных);\n");
	printf("\t  - поиск в массиве структур элемента с заданным значением поля \n");
	printf("\t    или с наиболее близким к нему по значению.\n");
	printf("\t  - удаление заданного элемента;\n");
	printf("\t  - изменение (редактирование) заданного элемента.\n");
	printf("\t  - вычисление с проверкой и использованием всех элементов массива по заданному условию\n");
	printf("\t    и формуле (например, общая сумма на всех счетах) -  дается индивидуально.\n\n");
	printf("\t  Перечень полей структурированной переменной.\n\n");
	printf("\t  Вариант № 9. Фамилия И.О., количество оценок, оценки, средний балл.\n\n");
	printf("\t\t\t\tДля входа в программу нажмите | Enter |\n");
}

void start(student* students, int* _count_record, int* _last_id, int* _count_free_items)
{
	system("cls");
	info();
	while (true)
	{
		switch (_getch())
		{
		case ESC:
			free(students);
			exit(0);
			break;

		case ENTER: // загрузить записи
			system("cls");
			print_menu_header();
			print_table_header();
			data_print(students, _count_record);
			print_line();
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_A: // добавить запись
			system("cls");
			print_menu_header();
			print_table_header();
			students = data_add_to_array(students, _count_record, _last_id, _count_free_items);
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_E: // редактировать запись
			system("cls");
			break;

		case SHIFT_D: // удалить запись
			system("cls");
			print_menu_header();
			students = delete_item(students, _count_record);
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_C: // очистить запись
			system("cls");
			print_menu_header();
			students = clear_item(students, _count_record, _count_free_items);
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_S: // запуск сортировки
			system("cls");
			break;

		case SHIFT_F: // запуск поиска
			system("cls");
			print_menu_header();
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_I: // показать задание
			system("cls");
			info();
			break;

		case LEFT: // влево
			system("cls");
			printf("Left press <<");
			//info();
			break;

		case RIGHT: // вправо
			system("cls");
			printf("Right press >>");
			//info();
			break;
		}
	}
}