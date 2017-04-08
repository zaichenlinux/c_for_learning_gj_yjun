#include <stdio.h>

int sum( int a[], int n )
{
	if (n>0) 
  		return (a[n-1] + sum(a, n-1));
  	else 
  		return 0;
}

int main(void)
{
	int a[100] = {1,2,3,4,5,6,7,8,9,10,11,12};
	printf("sum = %d\n", sum(a, 12));
	return 0;
}
