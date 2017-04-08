#include <stdio.h>

int main()
{
	int *p;
	p = 1;

	printf("%p\n", p);

	int a = 10;
	*(&a) = 100;

	return 0;
}
