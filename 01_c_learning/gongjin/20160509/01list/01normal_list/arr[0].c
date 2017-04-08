#include <stdio.h>

struct data_info {
	size_t data;
	size_t priv[];
};

int main()
{
	printf("%d\n", sizeof(struct data_info));

	struct data_info arr[2] = {{100}, {2000}};

	printf("%d\n", *(arr[0].priv));

	return 0;
}
