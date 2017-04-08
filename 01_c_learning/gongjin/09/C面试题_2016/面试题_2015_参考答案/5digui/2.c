#include <stdio.h>

int sum(int n)
{
	if (n == 1)
		return 1;
	return n + sum(n-1);
}

int main(void)
{
	printf("sum = %d\n", sum(100));
	return 0;
}
