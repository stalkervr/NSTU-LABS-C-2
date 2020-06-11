#include "header.h"

void print_menu_header()
{
	printf("\n");
	print_line();
	printf(" | ESC -> �����.         | Shift+A -> ��������.      | Shift+D -> �������.    | Shift+S ->  �����������.   |\n");
	printf(" | Enter -> ���������.   | Shift+E -> �������������. | Shift+C -> ��������.   | Shift+F ->  ������ �����.  |\n");
	print_line();
	printf("\n");
}

void print_table_header()
{
	//printf("\n");
	print_line();
	// body
	printf(" | Id | �������              | ���             | ��������                    | ���-�� ������ | ������� ��� |\n");
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
	printf(" | ����� �� ������������ �������� ����  ||  |\n");
	print_line();
	printf("\n");
}

void print_footer(int* _count_record, int* _count_free_items, student* items)
{
	*_count_free_items = count_free_items(items, _count_record);
	printf("\n");
	print_line();
	printf(" | <<<< ����� 10 ���.   ||     ����� ������� ->  %3d     ||  �������� ->  %3d    ||    ����� 10 ���. >>>> |\n",
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
	printf("\n\t\t\t����������� � ���������������� �-2. ������������ ������ �2 ������� �9.\n\n");
	printf("  ������� : \n");
	printf("\t    ���������� ����������������� ���, ���������� ����� ������� ��� ������ � �������� ��������.\n");
	printf("\t  �  ����������������� ���������� ������������� ������ ������� �� ��� \n\t  �� ���������� ������ (�.�. ""������"").\n");
	printf("\t  ������� ������ �������� � �������� �������� ��� � ��������� ���������� ����� ���������,\n");
	printf("\t  � ����� ��� ������������� ���������� ��������� �� ���������. \n\n\t  � �������� ������� ������:\n\n");
	printf("\t  - �������� ����������������� ����������;\n");
	printf("\t  - ����� ��������� ����������������� ����������;\n");
	printf("\t  - ���� ��������� (�����) ��������� � ����������;\n");
	printf("\t  - ����� ��������� (�����) ��������� � ����������;\n");
	printf("\t  - ����� � ������� ��������� � ����������� ���������  ��������� ����;\n");
	printf("\t  - ���������� �������  �������� � ������� ����������� ��������� ����\n");
	printf("\t    (��� ���������� ����� ������������ ��� ����, ��� � ��++ �����������\n");
	printf("\t    ������������ ����������������� ����������);\n");
	printf("\t  - ����� � ������� �������� �������� � �������� ��������� ���� \n");
	printf("\t    ��� � �������� ������� � ���� �� ��������.\n");
	printf("\t  - �������� ��������� ��������;\n");
	printf("\t  - ��������� (��������������) ��������� ��������.\n");
	printf("\t  - ���������� � ��������� � �������������� ���� ��������� ������� �� ��������� �������\n");
	printf("\t    � ������� (��������, ����� ����� �� ���� ������) -  ������ �������������.\n\n");
	printf("\t  �������� ����� ����������������� ����������.\n\n");
	printf("\t  ������� � 9. ������� �.�., ���������� ������, ������, ������� ����.\n\n");
	printf("\t\t\t\t��� ����� � ��������� ������� | Enter |\n");
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

		case ENTER: // ��������� ������
			system("cls");
			print_menu_header();
			print_table_header();
			data_print(students, _count_record);
			print_line();
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_A: // �������� ������
			system("cls");
			print_menu_header();
			print_table_header();
			students = data_add_to_array(students, _count_record, _last_id, _count_free_items);
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_E: // ������������� ������
			system("cls");
			break;

		case SHIFT_D: // ������� ������
			system("cls");
			print_menu_header();
			students = delete_item(students, _count_record);
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_C: // �������� ������
			system("cls");
			print_menu_header();
			students = clear_item(students, _count_record, _count_free_items);
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_S: // ������ ����������
			system("cls");
			break;

		case SHIFT_F: // ������ ������
			system("cls");
			print_menu_header();
			print_footer(_count_record, _count_free_items, students);
			break;

		case SHIFT_I: // �������� �������
			system("cls");
			info();
			break;

		case LEFT: // �����
			system("cls");
			printf("Left press <<");
			//info();
			break;

		case RIGHT: // ������
			system("cls");
			printf("Right press >>");
			//info();
			break;
		}
	}
}