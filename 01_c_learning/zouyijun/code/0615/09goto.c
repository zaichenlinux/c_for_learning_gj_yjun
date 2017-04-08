#include <stdio.h>

// setjmp longjmp

// goto 实现函数内的跳转的

// 不利用任何的循环结构，实现计算：1+2+...+100
int sum100()
{
	int sum = 0, i = 1;
loop:
	if (i <= 100) {
		sum += i;
		i++;
		goto loop;
	}

	return sum;
}

void jump()
{
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			if (i + j == 9) {
				printf("i=%d, j=%d\n", i, j);
				//break;
				goto out; // 从深层循环内部直接跳出整个循环，goto的最大用处
			}
		}
		//break;
	}
out:
	printf("out loop, i = %d, j = %d\n", i, j);
}

int main()
{
	printf("sum = %d\n", sum100());

	jump();

	return 0;
}
