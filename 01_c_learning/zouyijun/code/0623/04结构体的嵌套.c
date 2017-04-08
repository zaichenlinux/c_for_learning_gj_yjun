#include <stdio.h>

enum sex {
	MAN, WOMAN, UNKOWN,
};

struct person {
	char *name;
	enum sex sex;
	struct date {
		int year;
		int month;
		int day;
	} birthday, *pb;
	//struct date *pb; 
};

int main()
{
/*
	struct foo {
		int a;
		char c;
	};	

	struct foo f;
	f = {10, 'a'};
*/

/*
	struct person p1;
	//p1.birthday = {2001, 10, 1}; // 结构体变量不能在定义之后，整体赋值，但是可以使用下面两行的方式迂回解决
	struct date d = {2001, 10, 1};
	p1.birthday = d;
	printf("年：%d\n", p1.birthday.year);
*/
	struct person p = {
		"rose", 
		.birthday = {.day = 9, .month = 10},
		.birthday = {.day = 10, .month = 1, .year = 1991},
		.birthday.year = 1990,

		.pb = &(p.birthday),
	};

	struct person *pp = &p;

	printf("出生日期：%d-%d-%d\n", 
			p.birthday.year, p.birthday.month, p.birthday.day);
	printf("出生日期：%d-%d-%d\n", 
			pp->birthday.year, pp->birthday.month, pp->birthday.day);
	
	printf("出生日期：%d-%d-%d\n", 
			p.pb->year, (&p)->pb->month, pp->pb->day);

	return 0;
}
