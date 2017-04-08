#include <stdio.h>

//int cpu_arch(unsigned int n)
int cpu_arch(size_t n)
{
	/*
	printf("&n = %p\n", &n);
	//printf("0x%x\n", *((char *)(&n)));
	printf("0x%x\n", *((unsigned char *)(&n)));
	*/

	/*
	   char *p1 = (char *)(&n);
	char *p2 = p1 + 1;
	printf("p1 = %p, p2 = %p\n", p1, p2);
	printf("%#x\n", *p2);
	*/

	return *((unsigned char *)(&n)) == 0x88;
}

int main()
{
	// ELF: executeable and linkable format

	/* 内存字节序：内存中数据存放的顺序
		分成两种：
		小端架构LSB：least significant bit （最低有效位）
		大端架构MSB：most significant bit （最高有效位）
	
		LSB： 数据的最低位存放在内存的低地址上
	   	MSB： 数据的最高位存放在内存的低地址上	
	*/

	//int a = 0x11223344;
	//unsigned int a = 0x11223344;
	//long a = 0x1122334455667788; // ssize_t <==> signed long
	size_t a = 0x1122334455667788;
	printf("%s\n", cpu_arch(a) ? "LSB" : "MSB");

	return 0;	
}
