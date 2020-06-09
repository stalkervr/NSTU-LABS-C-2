#include "header.h"

void print_header()
{
	printf("\n");
	print_line();
	printf(" | Shift+A -> Info \t\t| Shift+I -> Add new int  \t| Shift+D -> Delete all data\t\t   |\n");
	printf(" | Enter -> Load or reload\t| Shift+F -> Add new float\t| ESC -> Exit\t\t\t\t   |\n");
	print_line();
	printf("\n");
}

void print_footer(int total, int free_mem)
{
	printf("\n\n");
	print_line();
	printf(" |  Memory level\t\t|\tTotal :%16d |\tFree :%17d\t\t   |\n", total, free_mem);
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
	printf("\n\t\t\tИнформатика и программирование Ч-2. Лабораторная работа №3 вариант №13.\n\n");
	printf("  Задание : \n");
	printf("\t    Разработать две функции, одна из которых вводит с клавиатуры набор данных в произвольной\n");
	printf("\t  последовательности и размещает в памяти в заданном формате. Другая функция читает  эти  данные  и\n");
	printf("\t  выводит на экран. Программа запрашивает и размещает в памяти несколько наборов данных при помощи\n");
	printf("\t  первой функции, а затем читает их и выводит на экран при помощи второй. Размещение данных \n");
	printf("\t  производить в выделенном массиве байтов с  контролем  его переполнения. \n\n");
	printf("\t    Область памяти представляет собой строку. Если в ней встречается выражение %%nnnd, где nnn - целое, \n");
	printf("\t  то сразу же за ним следует массив из nnn целых чисел (во внутреннем представлении, то есть типа \n");
	printf("\t  int). За выражением %%d - одно целое число, за  %%nnnf - массив из nnn вещественных чисел, за %%f \n");
	printf("\t  - одно вещественное число. \n\n");
	printf("\t\t\t\tДля входа в программу нажмите | Enter |\n");
}

void start(char* start_point, char* curent_point, int total)
{
	system("cls");
	info();
	curent_point = start_point;
	int free_mem;
	while (true)
	{
		switch (_getch())
		{
		case ESC:
			exit(0);
			break;

		case ENTER:
			system("cls");
			print_header();
			string_unpacking(start_point);
			string_view(start_point);
			free_mem = total - (curent_point - start_point);
			print_footer(total, free_mem);
			break;

		case SHIFT_A:
			system("cls");
			info();
			break;

		case SHIFT_F:
			system("cls");
			print_header();
			printf("  You press key Shift+F. The function add new float data...\n\n");
			free_mem = total - (curent_point - start_point);
			curent_point = input_float_numbers(curent_point, free_mem);
			break;

		case SHIFT_I:
			system("cls");
			print_header();
			printf("  You press key Shift+I. The function add new int data...\n\n");
			free_mem = total - (curent_point - start_point);
			curent_point = input_int_numbers(curent_point, free_mem);
			break;

		case SHIFT_D:
			system("cls");
			print_header();
			clear_data(start_point, total);
			string_unpacking(start_point);
			string_view(start_point);
			curent_point = start_point;
			free_mem = total - (curent_point - start_point);
			print_footer(total, free_mem);
			break;
		}
	}
}