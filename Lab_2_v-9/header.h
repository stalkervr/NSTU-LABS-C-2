#ifndef FIRST_HEADER_H
#define FIRST_HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define ENTER 13
#define ESC 27
#define SHIFT_A 65
#define SHIFT_E 69
#define SHIFT_D 68
#define SHIFT_C 67
#define SHIFT_S 83
#define SHIFT_F 70
#define SHIFT_I 73
#define SHIFT_L 76
#define SHIFT_Q 81
#define SHIFT_W 87
#define SHIFT_R 82
#define SHIFT_T 84

#define MARK_COUNT 100

typedef struct {
    int id;
    int is_free;
    char surname[30];
    char name[30];
    char second_name[35];
    int marks_count;
    int marks[MARK_COUNT];
    double marks_average;
} student;

student* students;
// menu
void info();
void clear_screen();
void print_menu_header();
void print_table_header();
void print_one_record(student* item);
void print_footer(int* _count_record, int* _count_free_items, student* items);
void print_line();
void start(student* items, int* _count_record, int* _last_id,
    int* _count_free_items);
int input_item_id();
double input_average_marks();
void print_all_items(student* items, const int* _count_record);
void print_items_min(student* items, const int* _count_record);
void print_items_max(student* items, const int* _count_record);
void print_items_range_average(student* items, const int* _count_record);
void print_not_found_error(int _item_id);
int count_free_items(student*, const int*);
double all_items_average_marks(student* items, const int* _count_record);
int all_items_count_marks(student* items, const int* _count_record);
int mygetch();
//
// add_item
student* data_add_to_array(student* items, int* _count_record, int* _last_id,
    const int* _count_free_items);
student data_add(int* _last_id);
student add_marks(student item_for_add_mark);
double average_mark(const int* items);
//
// edit_item
student* edit_item(student* items, int* _count_record);
//
// delete_item
student* delete_item(student* items, int* _count_record);
//
// clear_item
student* clear_item(student* items, int* _count_record);
//
// search_items
student* search_by_id(student*, int, const int*);
int search_index_by_id(student*, const int*, int);
int search_index_free_item(student* items, int* _count_record);
double search_min_average_marks(student* items, const int* _count_record);
double search_max_average_marks(student* items, const int* _count_record);
void search_by_name(student* items, const int* _count_record);
//
//sort_items
void sort_by_surname(student* items, const int* _count_record);
void sort_by_id(student* items, const int* _count_record);
//
// add_test_items
student add_test_item(int* _last_id);
student* add_test_data_to_array(student* items, int* _count_record,
    int* _last_id);
int take_random_mark(int left_range, int right_range);
int get_random(int n);
int fill_array_random_mark(int* items);
void fill_array(int*);
int count_marks_in_array(const int*);
//
#endif //FIRST_HEADER_H

