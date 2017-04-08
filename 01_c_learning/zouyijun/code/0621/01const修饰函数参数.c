#include <stdio.h>

// const出现最多的地方就是：用来修饰指针型函数的参数。这样就可以使得在const修饰的参数所在的函数内，不能通过const修饰的参数来修改这个参数指向的那个变量。
char *str(const char *s)
{
	//*s = 'W'; // *s是const的，所以不能通过s去修改*s
	return s;
}

int main()
{
	char s[] = "world";
	printf("%s\n", str(s));
	printf("s = %s\n", s);

	return 0;
}
