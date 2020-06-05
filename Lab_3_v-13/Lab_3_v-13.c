#include "header.h"

int main()
{
	system("chcp 1251");
	system("mode 115,40");

	char string[BUFFER_SIZE];
	char* curent_point = string;

	int total = sizeof(string) / sizeof(string[0]);

	start(string, curent_point, total);

	return 0;
}

