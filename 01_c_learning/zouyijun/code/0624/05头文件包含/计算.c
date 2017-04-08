#include <stdio.h>

#include "suanshu.h"
#include "test.h"

//int sum(int, int);
int main()
{
	int a = 4, b = 6;
	printf("%d + %d = %d\n", a, b, sum(a , b));
	printf("%d - %d = %d\n", a, b, sub(a , b));

	test();

	return 0;
}
