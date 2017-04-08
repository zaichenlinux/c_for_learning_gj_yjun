#include <stdio.h>

void reverse_print(char *a)
{
	if (*a != '\0') //递归的出口条件/结束条件 
		reverse_print(a + 1); //递推
	if (*a != '\0')
		printf("%c", *a);
}

#if 0
void reverse_print(char *p)
{
    if( *p == '\0' ) 
		return;
    inverse( p+1 );
    printf( "%c", *p );
}
#endif

int main(void)
{
	char s[] = "abcd";
	reverse_print(s);
	printf("\n");
	return 0;
}
