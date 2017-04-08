#include <stdio.h>

//1、编程实现：提示用户输入一个整数，检查输入的整数中是否有出现多于一次的数字。如果有提示“有“，并且显示出重复的数字；否则提示“没有“。比如，用户输入281238, 其中有重复的数字2，所以提示“有，是2“。
void repeat_num(int n)
{
	int arr[10] = {0};

	while (n) {
		arr[n%10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] > 1) {
			printf("%d重复了%d次\n", i, arr[i]);
		} else {
			if (arr[i] == 0) {
				printf("%d没有出现过\n", i);
			} else {
				printf("%d没有重复\n", i);
			}
		}
	}

	// 思路2：判断是否之前出现过，如果没有，说明这是第一次出现; 否则说明该数字重复
}

void repeat_num2(int n) // 11
{
	int arr[10] = {0};

	int i;
	while (n > 0) {
		i = n % 10;
		if (arr[i]) { // 判断这个i之间是否出现过
			//printf("%d之前出现过\n", i);
			arr[i] = 1;
			break;
		}
		arr[i] = 1; // 这里说明是第一次出现
		n /= 10;
	}

	if (n > 0) {
		printf("%d出现了重复的数字\n", i);	
	} else {
		printf("没有出现重复数字\n");
	}
}

//2、输入一个年份，一个天数，计算这个天数是该年的几月几号？
int is_leap_year(int year)
{
	return (!(year%4) && year%100) || !(year%400);

/*
	// 上面一行等价于下面4行
	if (!(year%4) && year%100) || !(year%400) {
		return 1;
	}
	return 0;
*/
}

void month_day(int year, int days) // 56天
{
	printf("%d天是%d年的", days, year);
	int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (is_leap_year(year)) { // 如果闰年
		months[2] += 1;
	}

	int m = 1, d = 1; // 分别用来保存月和日
	if (days <= months[1]) {
		d = days;
	}
	
	while (days > months[m]) {
		days -= months[m];
		m++;
		d = days;
	}

	printf("%d月%d日.\n", m, d);
}

/*
3、班里来了一名新同学，很喜欢学数学，同学们问他年龄的时候，他向大家说：我的年龄的平方是个三位数，立方是个四位数，四次方是个六位数，三次方和四次方正好用遍0、1、2、3、4、5、6、7、8、9、这10个数字，那么大家猜猜我今年多少岁？
*/

void guess_age()
{
	int age_min; // 年龄范围的最小值
	int age_max; // 年龄范围的最大值
	int age;
	int flag = 0;
	for (age = 10; age * age < 1000; age++) {
		if (age * age >= 100) {
			if (flag == 0) {
				age_min = age;
			}
			flag = 1;
		}
	}
	age_max = age - 1;
	printf("min = %d, max = %d\n", age_min, age_max);

	flag = 0;
	for (age = age_min; age <= age_max; age++) {
		if (age*age*age >= 1000 && age*age*age < 10000) { // 年龄的3次方是4位数
			if (flag == 0) {
				age_min = age;
			}
			flag = 1;
		} else {
			break;
		}
	}
	age_max = age - 1;
	printf("min = %d, max = %d\n", age_min, age_max);

	flag = 0;
	for (age = age_min; age <= age_max; age++) {
		if (age*age*age*age >= 100000 && age*age*age*age < 1000000) { // 年龄的4次方是6位数
			if (flag == 0) {
				age_min = age;
			}
			flag = 1;
		}
	}
	age_max = age - 1;
	printf("min = %d, max = %d\n", age_min, age_max);

	//三次方和四次方正好用遍0、1、2、3、4、5、6、7、8、9、这10个数字
	// 年龄的3次方是4位数
	// 年龄的4次方是6位数
	for (age = age_min; age <= age_max; age++) {
		int power3 = age*age*age; // 年龄的3次方
		int power4 = age*power3; // 年龄的4次方

		// 4位数：abcd = 3514
		// 6位数：efghij
		int a[10] = {0};
		for (int i = 0; i < 4; i++) {
			a[i] = power3%10;
			power3 /= 10;
		}

		for (int i = 4; i < 10; i++) {
			a[i] = power4%10;
			power4 /= 10;
		}

/*
		printf("%d岁年龄对应的数组是：", age);
		for (int i = 0; i < 10; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
*/

		// 确定年龄值
		int b[10] = {0};
		for (int i = 0; i < 10; i++) {
			b[a[i]]++;	
		}
/*
		printf("%d岁对于的b数组为：", age);
		for (int i = 0; i < 10; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
*/
		int ret = 1;
		for (int i = 0; i < 10; i++) {
			ret *= b[i];
		}
		if (ret == 1) {
			printf("该同学的年龄是：%d\n", age);
		}
	}
}

int main()
{
#if 1
	printf("请输入一个正整数：");
	int num;
	scanf("%d", &num);
	//repeat_num(num);
	repeat_num2(num);
#endif

#if 0
	printf("请输入一个年份，一个天数: ");
	int year, days;
	scanf("%d%d", &year, &days);
	month_day(year, days);
#endif
	//guess_age();
	return 0;
}
