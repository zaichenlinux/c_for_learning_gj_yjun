#include <stdio.h>

int fish(int n)
{
	if (n == 1) {  //出口条件
		static int i = 0;
		do {
			i++;
		} while (i%5 != 0);
		return i + 1;

	} else {
		int i = 0;
		do {
			i = fish(n - 1);
		} while (i%4 != 0);
		return i/4 * 5 + 1;
	}
}

int main(void)
{
	printf("%d个人至少捕了%d条鱼\n",
			5, fish(5));

	return 0;
}
