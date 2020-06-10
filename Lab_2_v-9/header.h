#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>
//#include <limits.h>
//#include <float.h>

//#define BUFFER_SIZE 20

#define ENTER 13
#define ESC 27
#define SHIFT_A 65
#define SHIFT_E 69
#define SHIFT_D 68
#define SHIFT_C 67
#define SHIFT_S 83
#define SHIFT_F 70
#define SHIFT_I 73
#define LEFT 75
#define RIGHT 77


typedef struct {
	unsigned id;
	int free;
	char surname[30];
	char name[30];
	char second_name[35];

	unsigned number_of_rating;
	unsigned ratings[200];
	float average_rating;
} student;

student* students;

#pragma region Èםעונפויס

void info();
void print_menu_header();
void print_table_header();
void print_search_header();
void print_one_record();
void print_footer();
void print_line();
void start(student* students, int* _count_record, int* _last_id);

#pragma endregion

void data_print(student* students, int* _count_record);
student* data_add_to_array(student* students, int* _count_record, int* _last_id);
student data_add(int* _last_id);
student add_marks(student item_for_add_mark);

//void key_search()
//{
//	int button1 = _getwch();
//	//cout << "1: " << (int)button1;
//	int button2 = _getwch();
//	//cout << " 2: " << (int)button2;
//}


