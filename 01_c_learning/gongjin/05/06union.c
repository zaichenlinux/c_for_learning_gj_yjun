/*
联合体(共用体)

大端存储:低地址存储高字节,高地址存储低字节

小端存储:低地址存储低字节,高地址存储高字节
*/
#include <stdio.h>
//union 联合体,联合体,
//1.所有的成员共用一块内存
//2.所有的成员的地址都是一样的,如果对联合体一个成员赋值,那么会影响到该联合体的其他成员.
//3.如果对联合体进行整体赋值,默认是赋值给第一个成员,而不是最大的成员.
union ufoo{
	unsigned char c;
	int i;
};

int main(int argc, char const *argv[])
{
	/* code */
	union ufoo ufoo= {0x12345678};
	//ufoo.i = 0x12345678;
	//ufoo.c = 0x12345678;

	printf("%#x\n",ufoo.i ); //x以16进制显示,#显示16进制前面加
	printf("%#x\n",ufoo.c);
	printf("%d\n", sizeof(union ufoo));
	return 0;
}