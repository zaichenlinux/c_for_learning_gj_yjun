//用递归算法判断数组a[N]是否为一个递增数组

#include <stdio.h>

int is_large(int a[],int n)
{
    if(!a){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return is_large(a,n-1) && (a[n-2]<a[n-1]);
}

int main(void)
{
	int a[] = {1,2,3,4,5,6, 3};
	int n = sizeof(a)/sizeof(a[0]);
	printf("%s\n", is_large(a, n) ? "yes" : "no");
	return 0;
}

