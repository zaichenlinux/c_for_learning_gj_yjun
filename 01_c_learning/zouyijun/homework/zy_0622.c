#include <stdio.h>
#include <string.h>

//1、用递归实现字符串翻转（逆序存放）
// 一般程序设计中，内部函数是以__开头的，表示这个函数只给当前文件中的其他函数来调用
static void __str_reverse(char *s, int l, int r) // l和r分别表示当前函数中的s数组中的首个元素和'\0'之前的那个元素的下标
{
	if (l >= r) { // 基线条件（l和r下标相遇 或者 交错并且相邻 时，递归结束）
		return;
	}

	// 交换l和r下标对于元素
	char tmp = *(s + l);
	*(s + l) = *(s + r);
	*(s + r) = tmp;

	// 递归调用
	__str_reverse(s, l+1, r-1);
}

void str_reverse_storage(char *s)
{
	int l = 0, r = strlen(s) - 1;
	__str_reverse(s, l, r);
}

#include <stdarg.h>

void swap_arr(char s[]) // [4321-\0]
{
	char *p1 = s, *p2 = s + strlen(s) - 1;

	char c;
	for (; p1 < p2; p1++, p2--) {
		c = *p1;
		*p1 = *p2;
		*p2 = c;
	}
}

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

//2、使用可变参数，实现一个简单的 printf 函数，要求能处理 %d %c %s 类型的数据
int my_printf(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	int count = 0; // 用来统计输出的字符个数

	char s[100] = {0};

	for (; *fmt; fmt++) {
		if (*fmt == '%') {
			fmt++;
			switch (*fmt) {
				case 'd':
					int2str(va_arg(ap, int), s);
					fputs(s, stdout);
					count += strlen(s);
					break;
				case 'c':
					putchar(va_arg(ap, int));
					count++;
					break;
				case 's':
					strcpy(s, va_arg(ap, char *));
					fputs(s, stdout);
					count += strlen(s);
					break;
				default:
					putchar('%');
					putchar(*fmt);
					count += 2;
			}
		} else { // *fmt 指向的字符是普通字符
			putchar(*fmt);
			count++;
		}
	}

	return count;
}

#include <stdlib.h>
//3、参数manpage中的qsort函数，实现对任意类型的的数据的排序(int类型，char*类型，结构体类型)
// cmp_int函数用来告诉qsort函数，如果进行排序（大小关系）
int cmp_int(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int cmp_str(const void *a, const void *b)
{
	return strcmp(*((char**)a), *((char**)b));
}

struct stu {
	char *name;
	int age;
};

int cmp_struct_name(const void *a, const void *b)
{
	return strcmp(((struct stu *)a)->name, ((struct stu *)b)->name);
}

int cmp_struct_age(const void *a, const void *b)
{
	return ((struct stu *)b)->age - ((struct stu *)a)->age;
}

int main()
{
	/*
	char s[] = "12345";
	str_reverse_storage(s);
	printf("s = %s\n", s);
*/

	/*
	int m = printf("hello %d, %v, %c, %s, linux\n", 123, 'A', "kernel");
	printf("m = %d\n", m);

	m = my_printf("hello %d, %v, %c, %s, linux\n", 123, 'A', "kernel");
	printf("m = %d\n", m);
*/

	int a[] = {1,-4,5,0,2,7,9,3};
	int n = sizeof(a)/sizeof(int);
	qsort(a, n, sizeof(int), cmp_int);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	//char s[][6] = {"mike", "jim", "jake", "rose"};
	char *t[] = {"mike", "jim", "jake", "rose"};
	n = sizeof(t)/sizeof(char*);
	qsort(t, n, sizeof(char*), cmp_str);
	for (int i = 0; i < n; i++) {
		printf("%s ", t[i]);
	}
	printf("\n");


	puts("-------------结构体--------------------");
	struct stu stus[5] = {
		{"jim", 20}, 
		{"tim", 19}, 
		{"tom", 21}, 
		{"kate", 18}, 
		{"jerl", 20}
	};
	n = sizeof(stus)/sizeof(struct stu);
	qsort(stus, n, sizeof(stus[0]), cmp_struct_name);
	for (int i = 0; i < n; i++) {
		printf("%s ", (stus + i)->name);
	}
	printf("\n");

	qsort(stus, n, sizeof(stus[0]), cmp_struct_age);
	for (int i = 0; i < n; i++) {
		printf("%d ", (stus + i)->age);
	}
	printf("\n");

	return 0;
}

