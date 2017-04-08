#include <stdio.h>
/*
自己实现命令 放在~/bin
$PATH
export PATH=$PATH:~/bin

/etc/profile            任何用户登陆时,执行一次
/etc/bash.bashrc    任何用户打开终端,执行一次

~/.profile         当前用户登陆是,执行一次
~/.bashrc         当前用户打开终端,执行一次
*/

//代码的健壮性
//计算字符串的长度
//'\0'结束
int my_strlen(char *s)
{
	//断言宏 assert 
	if(s == NULL){
		printf("%s, %s, %d\n",__func__, __FILE__, __LINE__ );
		return -1;
	}

	int i = 0;
	for (; *s != '\0'; s++)
	{
		i++;
	}
	return i;
}

//两个字符串,对应的位两两进行比较,如果相等,就继续比较下一位
//如果不相等
int my_strcmp(char *s,  char *t)
{
	int i;
	//s[i]   *(s+i)  == *(t + i)
	for(i=0;s[i] == t[i];i++)
		if('\0' == s[i]) return 0;

	return  s[i] - t[i];
}

int main(int argc, char *argv[])
{
	if((argc > 4)  || (argc < 2) {
		printf("请查看:string --help\n");
		return 0;
	}
	if(0 == my_strcmp(argv[1], "-l")){
		if(3 != argc) {
			printf("请输入:string -l 字符串\n");
		} else {
			printf("%s: 有%d个字节\n", argv[2],my_strlen(argv[2]));
		}

	}else if(0 == my_strcmp(argv[1], "-c")){
		if(argc != 4) {//48行代码永远不可能被执行,死区代码
			//出现死区代码,一定是逻辑错误
			printf("请输入:string -c 字符串1  字符串2\n");
		} else {
			printf("%s和%s比较的结果%d\n", argv[2],argv[3], my_strcmp(argv[2], argv[3]));
		}
	}else if (0 == my_strcmp(argv[1], "--help")){
		printf("string -l 字符串1    \n");
		printf("计算字符串1的长度   \n");		
		printf("string  -c 字符串1 字符串2 \n");
		printf("比较两个字符串1    \n");
		printf("string --help 打印帮助\n");
	} else {
		printf("请输入:string --help\n");
	}
	return 0;
}