#include <stdio.h>

//1、编写一个函数，判断某个字符串是否为回文。回文就是从左边开始读 和 从右边开始读 都是一样的，比如"abcba”.

/*2、参考manpage, 实现
	strchr（在字符串中找到某个字符第一次出现的位置）, 
	strstr（在一个字符串中查找一个子字符串）
*/
char *my_strstr(const char *s1, const char *s2)
{
	/*
		s1: world
		s2: or
	*/

	const char *ps1 = NULL, *ps2 = NULL;

	for (; *s1; s1++) {
		for (ps1 = s1, ps2 = s2; *ps1 == *ps2; ps1++, ps2++) {
			if (*(ps2 + 1) == '\0') {
				return (char *)s1;
			}
		}
	}
	return NULL; // 没找到
}


//3、参考manpage, 实现memcmp, memset、memcpy, memmove 的功能，并自己测试。
void *my_memmove(void *dst, const void *src, size_t n)
{
	char *d = dst;
	const char *s = src;

	if (s >= d) { // 内存不重叠
		while (n--) {
			*d++ = *s++;
		}
	} else { // 重叠
		d = dst + n - 1; // 指针定位到最后，往前拷贝
		s = src + n - 1;
		while (n--) {
			*d-- = *s--;
		}
	}
	return dst;
}


int main()
{
	char *s = "world";
	char *t = "ow";
	printf("strstr: %s\n", my_strstr(s, t));


	char src[100] = "world";
	//char dst[sizeof(src)] = {0};
	printf("%s\n", (char *)my_memmove(src, src+2, 2));

	return 0;
}
