#include "header.h"

char* input_int_numbers(char* curent_point, int free_mem)
{
	int count_numbers;
	printf("  Enter the count of integers -> ");
	scanf("%d", &count_numbers);

	int break_flag = overflow_control(free_mem, count_numbers);
	if (break_flag == 1) {
		printf("  Not enough memory to write!!!");
		return curent_point;
	}
	else {
		*curent_point++ = '%';
		if (count_numbers > 1)
		{
			*curent_point++ = (char)count_numbers;
		}
		*curent_point++ = 'd';

		int integer_int;
		for (int i = 0; i < count_numbers; i++) {
			do
			{
				printf("  Enter %d-s integers number -> ", i + 1);
				scanf("%d", &integer_int);
				if (integer_int < INT_MIN || integer_int > INT_MAX)
				{
					printf("  The entered number is out of range !");
				}
			} while (integer_int < INT_MIN || integer_int > INT_MAX);
			*((int*)curent_point)++ = integer_int;
		}
	}
	return curent_point;
}
char* input_float_numbers(char* curent_point, int free_mem)
{
	int count_numbers;
	printf("  Enter the count of floaters -> ");
	scanf("%d", &count_numbers);

	int break_flag = overflow_control(free_mem, count_numbers);
	if (break_flag == 1) {
		printf("  Not enough memory to write!!!");
		return curent_point;
	}
	else {
		*curent_point++ = '%';
		if (count_numbers > 1)
		{
			*curent_point++ = (char)count_numbers;
		}
		*curent_point++ = 'f';

		float float_f;
		for (int i = 0; i < count_numbers; i++) {
			do {
				printf("  Enter %d-s floaters number -> ", i + 1);
				scanf("%f", &float_f);
				if (float_f < FLT_MIN && float_f > FLT_MAX)
				{
					printf("  The entered number is out of range !");
				}
			} while (float_f < FLT_MIN && float_f > FLT_MAX);
			*((float*)curent_point)++ = float_f;
		}
	}
	return curent_point;
}

int overflow_control(int free_mem, int count_numbers)
{
	if (free_mem < ((sizeof(count_numbers) * count_numbers) + 3))
	{
		return 1;
	}
	return 0;
}

void clear_data(char* start_point, int total)
{
	for (int i = 0; i < total; i++)
	{
		*start_point++ = 0;
	}
}