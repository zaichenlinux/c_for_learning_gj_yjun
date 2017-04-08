#include <stdio.h>

int jc( int n )
{
	if (n == 1) 
		return 1;
  	return n * jc(n - 1);
}

int main(void)
{
	printf("jc = %d\n", jc(4));
	return 0;
}
