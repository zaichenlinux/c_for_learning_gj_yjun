
//用递归法求两个正整数(m,n)累加和 （考虑m>n，m=n，m<n三种情况）
#include <stdio.h>

int sum(int m, int n)
{
    //对于接受的参数，要考虑m>n，m=n，m<n三种情况。
	if (m < n) {
    	return (n - m + sum(++m, n)); //如果m<n,返回“m”加上“m+1到n累加的和”
    } else {
		if (m > n) {
        	//return (m + n + sum(--m, n)); //如果m>n,返回“m”加上“m-1到n累加的和”
        	return (m - (n-1)  + sum(--m, n));
        } else {
			return n; //如果m=n，直接返回n，这是递归的关键。
		}
	}
}

int main(void)
{
    printf("sum = %d\n", sum(1, 100));
    printf("sum = %d\n", sum(100, 1));
    printf("sum = %d\n", sum(80, 80));

	return 0;
}
