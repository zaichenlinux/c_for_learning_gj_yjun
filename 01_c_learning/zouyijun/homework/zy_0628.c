#include <stdio.h>

//1、用宏实现将字节逆序存放(0x12345678 --> 0x78563412)
#define REVERSE_ENDIAN(n) \
	((n & 0xff) << 24) | \
	((n & 0xff00) << 8) | \
	((n & 0xff0000) >> 8) | \
	((n & 0xff000000) >> 24)

#define REVERSE_BYTE_SORT(n) \
	((n & 0xff) << 24) | \
	(((n >> 8) & 0xff) << 16) | \
	(((n >> 16) & 0xff) << 8) | \
	(n >> 24)

//2、打印出一个整数的二进制形式


#define CHAR_BIT 8

//3、编程实现10进制转2进制，2进制转10进制，10进制转16进制，16进制转10进制
void reverse(char *s)
{
	char *p1 = s, *p2 = s;
	for (; *(p2 + 1); p2++) {} // 循环执行完毕，p2指向了\0之前的那个字符 
	//printf("%d\n", *p2);

	for (; p1 < p2; p1++, p2--) {
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
	}
}

void dec2bin(int n) // 10-->2 : 不断除以2
{
	char s[sizeof(int) * CHAR_BIT] = {0}; // 存放最后的结果
	for (int i = 0; n > 0; i++) {
		s[i] = n % 2 + '0';
		n /= 2;
	}

	reverse(s);
	printf("0b%s\n", s);
}

void dec2hex(int n) // 10-->16 : 不断除以16
{
	char s[sizeof(int) * CHAR_BIT] = {0}; // 存放最后的结果
	char tmp[] = "0123456789abcdef";
	
	for (int i = 0; n > 0; i++) {
		s[i] = tmp[n % 16];
		n /= 16;
	}

	reverse(s);
	printf("0x%s\n", s);
}

int power(int x, int y)
{
	int ret = 1;
	while (y--) {
		ret *= x;
	}
	return ret;
}


// 0b1011 = 1*2的0次方 + 1*2的1次方 + 0*2的2次方 + 1*2的3次方
int bin2dec(int n) // 2-->10
{
	int sum = 0; // 得到最后结果的
	int tmp = 0; // 取出的每一位

	for (int i = 0; n > 0; i++) {
		tmp = n % 2;
		sum += tmp*power(2, i);
		n /= 2;
	}

	return sum;
}

// 0x4f = f*16的0次方 + 4*16的1次方
int hex2dec(int n) // 16-->10
{
	int sum = 0; // 得到最后结果的
	int tmp = 0; // 取出的每一位

	for (int i = 0; n > 0; i++) {
		tmp = n % 16;
		sum += tmp*power(16, i);
		n /= 16;
	}

	return sum;
}

// 0b1101
int bin2dec_2(char s[]) // 2-->10 方案2
{
	int sum = 0;
	char *p = s + 2;
	for (; *(p+1); p++) {}
	for (int i = 0; *p != 'b'; i++, p--) {
		sum += (*p - '0') * power(2, i);
	}

	return sum;
}

// 0x4f = (4*16的0次方)*16 + 15*16的0次方
int hex2dec_2(char *p) // 16-->10 方案2
{
	//"0...9a...fA...F"
	int sum = 0;
	int tmp = 0;
	for (; *p; p++) {
		if (*p >= '0' && *p <= '9') {
			tmp = *p - '0';
		} else if (*p >= 'a' && *p <= 'f') {
			tmp = *p - 'a' + 10;
		} else if (*p >= 'A' && *p <= 'F') {
			tmp = *p - 'A' + 10;
		}

		sum = sum * 16 + tmp; // 4
	}

	return sum;
}

int main()
{
	/*
	unsigned int a = 0x12345678;
	a = REVERSE_ENDIAN(a);
	printf("%#x\n", a);

	a = 0x12345678;
	a = REVERSE_BYTE_SORT(a);
	printf("%#x\n", a);
*/

	int n = 125;
	dec2bin(n);
	dec2hex(n);

	// 10000000 00000000 0000000 00000001 -1原码
	// 0x80000001
	
	//printf("10-->16: %#x\n", n);

	n = 0b11010010; //2+16+64+128 = 210
	printf("%d\n", bin2dec(n));

	char s[] = "0b11010010";
	printf("%d\n", bin2dec_2(s));

	n = 0x4f;
	printf("%d\n", hex2dec(n));

	char t[] = "0x4f";
	printf("%d\n", hex2dec_2(t + 2));

	return 0;
}
