#include <stdio.h>

int count = 0;
void move_disk(int n, char start, char end)
{
	printf("移动%d, %c --> %c\n", 
			n, start, end);
	count++;
}

void hanoi(int n, char start, char tmp, char end)
{
	if (n == 1) {
		move_disk(n, start, end);
	} else {
		hanoi(n - 1, start, end, tmp);
		move_disk(n, start, end);
		hanoi(n - 1, tmp, start, end);
	}
}

int main(void)
{
	int n;
	printf("请输入盘子个数：");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	printf("共需要移动%d次\n", count);
	return 0;
}
