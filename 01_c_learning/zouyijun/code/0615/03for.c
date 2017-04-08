#include <stdio.h>

/*
	for (初始化语句; 判断条件; 改变增量的语句) {
		判断条件成立时，执行的代码
	} 
	
	for循环在计数型的循环中最常使用
*/

// 计算100以内能够被3整除的正整数的和
int sum_of_divide3()
{
	int sum = 0;
	for (int i = 1; i < 100; i++) {
		if (i % 3 == 0) { //等价于  if (!(i % 3))
			printf("%d ", i);
			sum += i;
		}
	}

/*
	int j = 1, sum2 = 0
	while (j < 100) {
		if (!(j % 3)) {
			sum2 += j;
		}
		j++;
	}
*/

	return sum;
}

int main()
{
	printf("\n和 = %d\n", sum_of_divide3());
	return 0;
}
