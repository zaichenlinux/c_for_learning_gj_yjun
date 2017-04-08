#include <stdio.h>
#include <string.h>

void reverse(char *s, int left, int right)
{
	if (left >= right)
		return;

	char tmp = s[left];
	s[left] = s[right];
	s[right] = tmp;

	reverse(s, left + 1, right - 1);	
}

int main(void)
{
	char s[] = "12345";
	reverse(s, 0, strlen(s) - 1);

	printf("%s\n", s);

	return 0;
}
