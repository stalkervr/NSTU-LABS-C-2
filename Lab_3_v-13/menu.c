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
	printf("\n\t\t\t����������� � ���������������� �-2. ������������ ������ �3 ������� �13.\n\n");
	printf("  ������� : \n");
	printf("\t    ����������� ��� �������, ���� �� ������� ������ � ���������� ����� ������ � ������������\n");
	printf("\t  ������������������ � ��������� � ������ � �������� �������. ������ ������� ������  ���  ������  �\n");
	printf("\t  ������� �� �����. ��������� ����������� � ��������� � ������ ��������� ������� ������ ��� ������\n");
	printf("\t  ������ �������, � ����� ������ �� � ������� �� ����� ��� ������ ������. ���������� ������ \n");
	printf("\t  ����������� � ���������� ������� ������ �  ���������  ��� ������������. \n\n");
	printf("\t    ������� ������ ������������ ����� ������. ���� � ��� ����������� ��������� %%nnnd, ��� nnn - �����, \n");
	printf("\t  �� ����� �� �� ��� ������� ������ �� nnn ����� ����� (�� ���������� �������������, �� ���� ���� \n");
	printf("\t  int). �� ���������� %%d - ���� ����� �����, ��  %%nnnf - ������ �� nnn ������������ �����, �� %%f \n");
	printf("\t  - ���� ������������ �����. \n\n");
	printf("\t\t\t\t��� ����� � ��������� ������� | Enter |\n");
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