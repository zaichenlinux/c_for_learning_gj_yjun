/*
循环控制

if(条件) {
	语句
} else if (条件2){
	语句
} else {
	语句
}

1.if语句条件,如果判断相等,把常量放在左边,变量放在右边.
 即使不小心,把== 写成=,语法会报错.


switch(表达式) {
	case  数值1或者范围1:
		语句;
		break;
	case  数值2或者范围2:
		.....
	default:
		brak;
}
switch  
1.表示范围的时候,范围不能重叠.
2.  ... 表示范围,  ... 左边和右边都要有空格
3.break........
4. 表示范围,范围必须是有限的
5. switch 会根据表达式的内容,直接跳转到对应case语句中
6.选项不能是浮点类型

2.循环
for while do while
while(条件) {
	语句;
}

do {
	语句
}while(条件);
do{}while(0) 用于宏中
,在宏中,如果替换的序列超过两句话,根据具体情况,用do while封装起来,变成一个程序块. while(0)后面不要加;
#define SAFE_FREE(p)  do{free(p);p=NULL;}while(0)


for(表达式;条件;表达式) {
	语句;	
}
*/
#include <stdio.h>
/*
 warning: incompatible implicit declaration of built-in function ‘printf’
隐式函数的声明,在gcc编译器,隐式函数的声明只是一个警告.

跳转
goto  break   continue  return  exit

goto 标签
批量处理错误用到,其他的场合尽量不要用goto语句

break
跳出这个循环

continue
跳出本次循环

*/

int main(int argc, char const *argv[])
{
	#if 0
	int yanzhi = 90;
	int c = 100;
	printf("约吗\n");

	switch(yanzhi) {		
		case 81:
			printf("c = %d\n", c);
			printf("约\n");
			break;
		case 61 ... 80:
			//printf("c = %d\n", c);
			printf("对不起,我妈喊我回家吃饭\n");
			break;
		case 21 ... 60:
			printf("对不起,你是个好人\n");
			break;
		case 0 ... 20:
			printf("滚蛋\n");
			break;
		default: 
			break;
	}

	if(XXX)   SAFE_FREE;
		free(p);p=NULL;;
		do{free(p);p=NULL;}while(0);
		{free(p);p=NULL;};
	#endif
	//符合C语言的语法,但是编译的时候要加一个选项
	//-std=c99
	//k&r c89/c90  c99 c11


	int a = 1;
	while(a) {
		printf("in break\n");
		if(3 == a) {
			break;
			//continue;
		}
		printf("end break\n");
		a++;
	}
	//1.110 break 输出什么
	//2.110 continue 输出什么

	//在if 可以用break  continue么
	//break  只能用在循环和switch中
	//continue  只在循环中
	if (a == 3) {
		//break;
		continue;
		printf("sssssss\n");
	}

	return 0;
}
