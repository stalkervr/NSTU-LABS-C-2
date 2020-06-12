#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include<string.h>
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
#define MARK_COUNT 200


typedef struct {
	int id;
	int is_free;
	char surname[30];
	char name[30];
	char second_name[35];

	int marks_count;
	int marks[MARK_COUNT];
	float marks_average;
} student;

student* students;



#pragma region Интерфейс

void info();
void print_menu_header();
void print_table_header();
void print_search_header();
void print_one_record();
void print_footer(int* _count_record, int* _count_free_items, student* items);
void print_line();

void start(student* students, int* _count_record, int* _last_id, int* _count_free_items);
int input_item_id();
#pragma endregion

void data_print(student* students, int* _count_record);
student* data_add_to_array(student* students, int* _count_record, int* _last_id,
	int* _count_free_items);

int search_index_free_item(student* items, int* _count_record);

student data_add(int* _last_id);
student add_marks(student item_for_add_mark);
void copy_array(int*, int*, int);
void fill_array(int*);
int count_marks_in_array(int*);
student* clear_item(student* items, int* _count_record, int* _count_free_items);
student* delete_item(student* items, int* _count_record);
student* edit_item(student* items, int* _count_record);
student* search_by_id(student*, int, int*);
int search_index_by_id(student*, int*, int);

int count_free_items(student*, int*);

 //тестовые данные
//student test_data_add();
//student* add_test_data_to_array();
int take_random_mark(int left_range, int right_range);
//int random(int n);
int fill_array_random_mark(int* items);
double average_mark(int* items);
//

//void key_search()
//{
//	int button1 = _getwch();
//	//cout << "1: " << (int)button1;
//	int button2 = _getwch();
//	//cout << " 2: " << (int)button2;
//}


