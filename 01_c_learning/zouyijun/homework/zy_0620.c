#include <stdio.h>

/*
	ACII码表中需要记住的几个字符对应的值：
		'\0' 0
		'0' 48
		'a'	97
		'A' 65
   */

//1、实现字符串转为整型数（例如："1234" --> 1234）
int str2int(const char *s)
{
	// '1' --> 1 
	// '1' - '0' == 1

	int flag = 1;
	if (*s == '-') {
		flag = -1;
		s++;
	}

	int num = 0;
	while (*s) { // 等价于 *s != '\0'
		if (*s >= '0' &&  *s <= '9') {
			num = num * 10 + (*s - '0'); 
		} else {
			break;
		}
		s++;
	}
	//printf("num = %d\n", num);

	return flag * num;	
}

#include <string.h>
void swap_arr(char s[]) // [4321-\0]
{
	char *p1 = s, *p2 = s + strlen(s) - 1;

	char c;
	for (; p1 < p2; p1++, p2--) {
		c = *p1;
		*p1 = *p2;
		*p2 = c;
	}

	printf("s = %s\n", s);
}

//2、实现整型数转为字符串（例如：1234 --> "1234"）
void int2str(int n, char s[])
{
	int m = n;
	if (n < 0) {
		m = -n;
	}

	char *t = s;
	while (m) {
		*s = m % 10 + '0';
		s++;
		m /= 10;
	}
	if (n < 0) {
		*s = '-'; 
	}

	swap_arr(t);
}


//3、参考manpage, 实现 strlen, strcpy、strncpy、strcat、strncat、strcmp、strncmp 的功能
size_t my_strlen(const char *s)
{
	int count = 0;
	while (*s++) {
		count++;
	}
	return count;
}

char *my_strcpy(char *dst, const char *src)
{
	char *d = dst;
	while (*dst++ = *src++);

	/*
	while (*src) {
		*dst = *src;
		dst++;
		src++;
	}*/

	return d;
}

char *my_strncpy(char *dst, const char *src, size_t n)
{
	char *d = dst;
	while (n--) {
		if (!(*src)) {
			break;
		}
		*dst++ = *src++;
	}
	*dst = '\0';

	return d;
}

char *my_strcat(char *dst, const char *src)
{
	char *d = dst;
	// 下面2行代码是为了找到dst的'\0'的位置
	while (*dst++) {}
	dst--;

	while (*dst++ = *src++) {}

	return d;
}

char *my_strncat(char *dst, const char *src, size_t n)
{
	char *d = dst;
	while (*dst) { dst++; }
	while (n--) {
		if (!(*src)) {
			break;
		}
		*dst++ = *src++;
	}
	*dst = '\0';

	return d;
} 

int my_strcmp(const char *s1, const char *s2)
{
	while (1) {
		if (*s1 != *s2) { //'1234' '1324'
			return *s1 > *s2 ? 1 : -1;
		} else if (!(*s1)) {
			return 0;
		}
		s1++;
		s2++;
	}
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--) {
		if (*s1 != *s2) { //'1234' '1324'
			return *s1 > *s2 ? 1 : -1;
		} else if (!(*s1)) {
			return 0;
		}
		s1++;
		s2++;
	}
}

#include <limits.h>
#include <stdlib.h>
int main()
{
	/*
	//char *s = "1234";
	char s[] = "-1234abc123";
	printf("%d\n", str2int(s));
	printf("atoi, %d\n", atoi(s));
*/
	printf("int类型的最大值：%d\n", INT_MAX);

	//char s[] = "1234";
	//swap_arr(s);

#if 0
	printf("请输入一个整数：");
	int num;
	scanf("%d", &num);
	char t[12] = {0}; 
	int2str(num, t);
	printf("t = %s\n", t);
#endif

	char *s1 = "world0";
	char t1[sizeof("world")] = {0};
	printf("strlen: %lu\n", my_strlen(s1));
	printf("strcpy: %s\n", my_strcpy(t1, s1));
	printf("strncpy: %s\n", my_strncpy(t1, s1, 13));

	char t2[10] = "123";
	//printf("strcat: %s\n", my_strcat(t2, s1));
	printf("strncat: %s\n", my_strncat(t2, s1, 2));
	
	char *s2 = "world";
	printf("strcmp: %d\n", my_strcmp(s1, s2));
	printf("strncmp: %d\n", my_strncmp(s1, s2, 7));

	return 0;
}
