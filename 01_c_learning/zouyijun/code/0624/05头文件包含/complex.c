
int power(int x)
{
	return x * x;
}

// 用递归计算1+2+...+100
int sum100(int n)
{
	if (n == 1) 
		return 1; 
	return n + sum100(n-1);
}
