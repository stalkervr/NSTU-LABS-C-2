#include "header.h"

void string_unpacking(char* start_point)
{
	int count_numbers;

	while (*start_point++ == '%') {
		if (*start_point == 'd' || *start_point == 'f') {
			count_numbers = 1;
		}
		else {
			count_numbers = (int)*start_point++;
		}
		if (*start_point++ == 'd') {
			printf("  Integers have been entered -> %d, with values -> ", count_numbers);
			int integer_int;
			for (int i = 0; i < count_numbers; i++) {
				integer_int = *((int*)start_point)++;
				printf("%d ", integer_int);
			}
			printf("\n");
		}
		else {
			printf("  Floaters have been entered -> %d, with values -> ", count_numbers);
			float float_f;
			for (int i = 0; i < count_numbers; i++) {
				float_f = *((float*)start_point)++;
				printf("%.2f ", float_f);
			}
			printf("\n");
		}
	}
}

void string_view(char* start_point)
{
	int count_numbers;

	printf("  Packed data sequence -> ");
	while (*start_point++ == '%') {
		if (*start_point == 'd' || *start_point == 'f') {
			count_numbers = 1;
		}
		else {
			count_numbers = (int)*start_point++;
		}
		if (*start_point++ == 'd')
		{
			printf("%%");
			if (count_numbers == 1) {
				printf("d");
			}
			else {
				printf("%dd", count_numbers);
			}
			int integer_int;
			for (int i = 0; i < count_numbers; i++) {
				integer_int = *((int*)start_point)++;
				printf("%d", integer_int);
			}
		}
		else
		{
			printf("%%");
			if (count_numbers == 1) {
				printf("f");
			}
			else {
				printf("%df", count_numbers);
			}
			float float_f;
			for (int i = 0; i < count_numbers; i++) {
				float_f = *((float*)start_point)++;
				printf("%.2f", float_f);
			}
		}
	}
}
