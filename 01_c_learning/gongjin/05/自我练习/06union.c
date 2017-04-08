#include<stdio.h>
#if 0
union ufoo
{
	unsigned char c;
	int i;
};
int main()
{
	union ufoo ufoo={0x12345678};//8位16进制的数可以用4个字节表示
	ufoo.i=0x12345678;
	ufoo.c=0x12345678;
	printf("ufoo.i=%#x\n",ufoo.i);//为整形可以完全存储
	printf("ufoo.c=%#x\n",ufoo.c);//为小端存储
	printf("sizeof(union ufoo)=%lu\n",sizeof(union ufoo));//为4个字节
	return 0;
}
/*输出结果为：
ufoo.i=0x12345678
ufoo.c=0x78
sizeof(union ufoo)=4
*/
#endif
union ufoo
{
	unsigned char c;
	int i;
};
int main()
{
	union ufoo ufoo={0x12345678};//8位16进制的数可以用4个字节表示
	//ufoo.i=0x12345678;
	ufoo.c=0x12345678;
	if(ufoo.c==0x78)
	{
		printf("计算机类型为小端存储\n");
	}
	else
	{	
		printf("计算机类型为大端存储\n");
	}
	//printf("ufoo.i=%#x\n",ufoo.i);//为整形可以完全存储
	//printf("ufoo.c=%#x\n",ufoo.c);//为小端存储
	printf("sizeof(union ufoo)=%lu\n",sizeof(union ufoo));//为4个字节
	return 0;
}


