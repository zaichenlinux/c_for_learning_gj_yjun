
//1、用联合体判断大小端
#include <stdio.h>

int test_endian()
{
	union endian {
		unsigned int a;
		char c;
	} u = {1};

	return u.c == 1;
}

int main()
{
	printf("%s_endian\n", test_endian() ? "little" : "big");
	return 0;
}


