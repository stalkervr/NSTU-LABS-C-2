#include "header.h"

void string_unpacking(char* pointer)
{
	int countNumbers;

	while (*pointer++ == '%') {
		if (*pointer == 'd' || *pointer == 'f') {
			countNumbers = 1;
		}
		else {
			countNumbers = (int)*pointer++;
		}
		if (*pointer++ == 'd') {
			printf("  Integers have been entered: %d, with values: ", countNumbers);
			int integer_int;
			for (int i = 0; i < countNumbers; i++) {
				integer_int = *((int*)pointer)++;
				printf("%d ", integer_int);
			}
			printf("\n");
		}
		else {
			printf("  Floaters have been entered: %d, with values: ", countNumbers);
			float float_f;
			for (int i = 0; i < countNumbers; i++) {
				float_f = *((float*)pointer)++;
				printf("%.2f ", float_f);
			}
			printf("\n");
		}
	}
}

void string_view(char* pointer)
{
	int countNumbers;

	printf("  Packed data sequence -> ");
	while (*pointer++ == '%') {
		if (*pointer == 'd' || *pointer == 'f') {
			countNumbers = 1;
		}
		else {
			countNumbers = (int)*pointer++;
		}
		if (*pointer++ == 'd')
		{
			printf("%%");
			if (countNumbers == 1) {
				printf("d");
			}
			else {
				printf("%dd", countNumbers);
			}
			int integer_int;
			for (int i = 0; i < countNumbers; i++) {
				integer_int = *((int*)pointer)++;
				printf("%d", integer_int);
			}
		}
		else
		{
			printf("%%");
			if (countNumbers == 1) {
				printf("f");
			}
			else {
				printf("%df", countNumbers);
			}
			float float_f;
			for (int i = 0; i < countNumbers; i++) {
				float_f = *((float*)pointer)++;
				printf("%.2f", float_f);
			}
		}
	}
}
