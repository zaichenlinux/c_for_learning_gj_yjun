#include <stdio.h>

void arr_arr()
{
	// str这个一维数组本身的类型是：char [sizeof(str)/sizeof(char)]
	char str[] = {'1', '2', 'w', 'x', 'y'};
	int n = sizeof(str)/sizeof(char); // 数组元素个数

	// arr二维数组本身的类型：char[2][5]
	// arr数组中的每一个元素（其实就3个元素：arr[0]和arr[1]和arr[2]）的类型：char[5]
	// arr[0]、arr[1]、arr[2]里面存放的元素的类型：char
	char arr[][5] = {
						{'w', 'o', 'r', 'l', 'd'}, // arr[0]
						{'1', '3', '5', '7'}, // arr[1]
						{'1', '3', '5', '7', '9'}, // arr[2]
					  };
	printf("arr[0][3] = %c\n", arr[0][3]);

	n = sizeof(arr)/sizeof(char[5]);
	printf("n = %d\n", n);
}

int main()
{
	arr_arr();
	return 0;
}
