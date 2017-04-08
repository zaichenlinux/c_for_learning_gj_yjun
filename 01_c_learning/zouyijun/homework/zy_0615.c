/*
1，提示用户输入一个小于10的正整数n，如果n是5，就输出下列图形，其他n值以此类推
 54321
 5432
 543
 54
 5
*/

/*
2, 有一种数字游戏，魔术师要某一个观众想好一个三位数abc(a是百位数，b是十位数，c是个位数)。然后魔术师要这个观众记下另外5个三位数：acb,bac,bca,cab,cba,并把这5个三位数加起来，求得和m。
    如果讲出m是多少，魔术师即能告诉观众想好的原数abc是多少。观众甲说他得的和是2010，观众乙说他得的和是2012。魔术师即作答，甲说的m=2010不对，要么是在说谎，要么就是求和时算错了。而乙想好的数abc是208。请设计程序破解魔术师的这一数字魔术。
*/

#include <stdio.h>
void guess_num()
{
	/*
		原数：abc = 100*a + 10*b + c
		另外5中组合数：
			acb
			bac
			bca
			cab
			cba
		解题关键：
			其他5个数的和(100a+200b+200c + 20a+10b+20c + 2a+2b+c) == m
	*/

	printf("请输入您想的3位数的其他5个组合的和：");
	int m;
	scanf("%d", &m);
	int flag = 0;

	int a, b, c; //原数的百位，十位，个位
	for (a = 1; a <= 9; a++) { // 算百位的可能取值
		for (b = 0; b <= 9; b++) { // 十位
			for (c = 0; c <= 9; c++) {
				if (122*a + 212*b + 221*c == m) {
					printf("abc=%d\n", 100*a+10*b+c);
					flag = 1;
				}
			}
		}
	}
	if (flag == 0) {
		printf("你算错了，或者你在说谎！\n");
	}
}

/*
3、如果n和n+2都是素数，则称它们是孪生素数。输入m(5<=m<=10000)，输出两个数均不超过m的最大孪生素数。例如m=20时答案是17、19，m=1000时答案是881、883。
*/

// 判断参数表示的数据是否是素数（素数：只能被1和它本身整除的数）
int is_primer(int n)
{
	for (int i = 2; i <= n - 1; i++) {
		if (!(n % i)) {
			return 0;
		}
	}
	return 1;
}

void print_twins_prime(int m)
{
	//n是 比较小的那个孪生素数
	for (int n = m - 2; n + 2 >= 5; n--) {
		if (is_primer(n) && is_primer(n + 2)) {
			printf("%d和%d是%d的最大孪生素数.\n", n, n+2, m);
			break;
		}
	}
}

int main()
{
	//guess_num();
	//printf("%s是\n", is_primer(15) ? "" : "不");
	int m = 0;

	while (m < 5 || m > 10000) {
		printf("请输入介于5到10000之间的一个整数：");
		scanf("%d", &m);
	}

	print_twins_prime(m);

	return 0;
}


