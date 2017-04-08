//将一整数逆序后放入一数组中（要求递归实现） 如: 1234 变为 {4,3,2,1}
#include <stdio.h>

int revert(char s[], int i, int number) 
{
		int n = 10;
		while (i < n) {
        //if (i < strlen(s)) {
            s[i] = number % 10 + '0';
			printf("s[%d] = %c\n", i, s[i]);
            number = (number - number % 10) / 10;
            return revert(s, i + 1, number);
        //} else {
          //  return 0;
        //}
		}
}

int main(void) 
{
    int n = 1234;
	char str[10] = "000000000";
	revert(str, 0, n);
	printf("%s\n", str);

	return 0;
}
