#include <stdio.h>

//1、用户从键盘输入年、月、日。在屏幕上输出此日期是星期几。（已知1970年1月1日 是星期四）

int leap_year(int year)
{
	return (!(year%4) && (year%100)) || !(year%400);
}

void week(int y, int m, int d, int start_year)
{
	int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 月份对应天数表
	int days = 0; // 统计天数总和的

	// 统计起始年份到输入年份之间的天数
	for (int i = start_year; i < y; i++) {
		days += leap_year(i) ? 366 : 365;
	}

	// 统计1月到m月之间的天数
	for (int i = 1; i < m; i++) {
		days += months[i];
	}

	// y是闰年，并且m大于2月
	if (leap_year(y) && m > 2) {
		days += 1;
	}

	// 总天数（需要加上输入的天）
	days += d;

	printf("总天数：%d\n", days);

	/* 已知1970-1-1 星期4
	   		   1-2 星期5
			   1-3 6
			   1-4 日
			   1-5 1
			   1-6 2
			   1-7 3
			   1-8 4
	   */

	switch (days % 7) {
	case 0:
		printf("星期三\n"); break;
	case 1:
		printf("星期四\n"); break;
	case 2:
		printf("星期五\n"); break;
	case 3:
		printf("星期六\n"); break;
	case 4:
		printf("星期日\n"); break;
	case 5:
		printf("星期一\n"); break;
	case 6:
		printf("星期二\n"); break;
	}
}


//2、求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加由键盘控制。
void sum_num(int a, int n)
{
	int sum = 0, tmp = a; 
	for (int i = 1; i <= n; i++) {
		sum += tmp; 
		tmp = tmp * 10 + a; 
	}
	printf("和 = %d\n", sum);
}


/*
3、小学生在学习进位加法时，发现“进位”特别容易出错。你的任务是：计算两个整数在相加时，需要多少次进位。你编制的程序应该能连续处理多组数据，直到输入两个0结束程序。（假设输入的整数都不超过9个数字）
例如：
	输入 123 456
	输出 0
	输入 555 555
	输出 3
	输入 00
*/

// printf和scanf函数的返回值
void ret_value()
{
	//int n = printf("43\n");
	//printf("n = %d\n", n);
	//printf("%d\n", printf("%d", printf("43")));

	// printf函数的返回值表示：打印到标准输出上的字符的个数，不包括字符串的结束字符'\0'

	int m, n;
	printf("请输入m和n的值：");
	int c = scanf("%d%d", &m, &n); 
	// scanf函数的返回值表示：输入匹配成功的个数。如果第一个就匹配失败了，后续就不会继续匹配了，结果直接为0（匹配失败开始的那些输入，都被扔进了输入缓冲区）
	char d;
	scanf("%c", &d);
	printf("d = %c\n", d);
	scanf("%d", &m);
	printf("m = %d\n", m);

	//printf("%d\n", c);

	printf("缓冲区大小默认值：%d\n", BUFSIZ);
}

void carry_bit()
{
	int n1, n2; //分别表示用户输入的两个整数
	
	printf("请输入两个整数：");
	while ((scanf("%d%d", &n1, &n2) == 2) && (n1 && n2)) {
		printf("%d+%d一共有：", n1, n2);

		int sum = 0; // 统计一共有多少次进位
		int tmp = 0; // 保存上一次的进位
		while (n1 || n2) {
			//sum += tmp; // 1
			//tmp = n1%10 + n2%10 > 9 ? 1 : 0 + tmp; // 1
		
			// n1%10 + n2%10 表示两个数本次的某一位上的和
			tmp = (n1%10 + n2%10 + tmp) > 9 ? 1 : 0;
			sum += tmp;
			
			n1 /= 10; 
			n2 /= 10;
		}	

		printf("%d次进位\n", sum);
		tmp = 0;
		printf("请继续输入两个整数：");
	}
}

int main()
{
	/*
	printf("请输入年月日（形如：2016 4 16, 之间用空格分隔）：");
	int year, month, day, start_year = 1970;
	scanf("%d%d%d", &year, &month, &day);
	week(year, month, day, start_year);
*/

	/*
	printf("请输入一个个位整数：");
	int a;
	scanf("%d", &a);
	printf("请输入你想计算几次：");
	int n;
	scanf("%d", &n);
	sum_num(a, n);
*/

	carry_bit();

	//ret_value();

	return 0;
}
