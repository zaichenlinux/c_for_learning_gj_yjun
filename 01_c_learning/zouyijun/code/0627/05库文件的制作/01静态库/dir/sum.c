
// 实现计算start到end之间的整数的和
int sum(int start, int end)
{
	int sum = 0;
	for (int i = start; i <= end; i++) {
		sum += i;
	}

	return sum;
}
