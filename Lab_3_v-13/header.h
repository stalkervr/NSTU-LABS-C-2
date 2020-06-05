#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#define BUFFER_SIZE 20

#define ENTER 13
#define ESC 27
#define SHIFT_A 65
#define SHIFT_D 68
#define SHIFT_I 73
#define SHIFT_F 70


char* input_int_numbers(char* pointer, int free_mem);
char* input_float_numbers(char* pointer, int free_mem);
int overflow_control(int free_mem, int numbers);
void clear_data(char* start_point, int total);

void string_unpacking(char* pointer);
void string_view(char* pointer);

void info();
void print_header();
void print_footer(int total, int free_mem);
void print_line();
void start(char*, char*, int total);



