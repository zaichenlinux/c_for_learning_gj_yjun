#include <stdio.h>

/*
   EOF： end of file
   		 输入结束（使用快捷键来操作）

	输入：
		一行：gets, fgets
		fgets函数在进行输入时，会自动在输入完毕时，添加一个'\n'到输入缓冲区
		一个字符：getc, fgetc, getchar
		get(stdin) == fgetc(stdin) == getchar()
		getc 和 fgetc 区别：getc 是用宏实现的，fgetc 是用函数实现的

	输出：
		一行：puts, fputs
		puts函数在进行输出时，会自动在输出的内容之后添加一个'\n'
		一个字符：putc, fputc, putchar
   */

// 输入输出一行字符
void io_line()
{
	char s[3] = {0};
	/*
	char *gets(char *);
	gets(s);
	printf("s = %s\n", s);
	*/

	fgets(s, 3, stdin);
	//printf("s = %s\n", s);
	//puts(s); // 输出之后，会自动添加\n
	fputs(s, stdout); // 输出之后，不会添加\n
}

// 输入输出一个字符
void io_character()
{
	char s[] = "请输入一个字符：";
	puts(s);

	// getc: 从指定的位置（文件，标准输入）获得一个字符
	// putc: 向指定位置输出一个字符
	// fgetc 和 getc 作用是一样的，唯一的不同是getc是用宏实现的，而fgetc是用函数实现的; fputc 和 putc 同理

	//putc(getc(stdin), stdout);
	//fputc(fgetc(stdin), stdout);

	// getchar 作用也类似于getc, 但是只能从标准输入获得一个字符; putchar 同理
	putchar(getchar());
}

void input()
{
	char s[100] = {0};
	printf("请输入一串字符："); // 想要输入"hello world"进行保存
	/*
	scanf("%s", s); // scanf 函数在遇到空白字符(空格，回车，制表符)时，会认为本次输入结束
	printf("1, s = %s\n", s);
	scanf("%s", s);
	printf("2, s = %s\n", s);
	*/

	//gets(s); // 输入"hello world" // gets函数在进行输入时，不会在最后自动添加一个'\n'
	fgets(s, 100, stdin); // fgets函数在进行输入时，会在最后自动添加一个'\n'
	
	printf("s = %s\n", s);
}

// scanf函数使用注意
void scanf_note()
{
	printf("请输入一个字符：");
	char c;
	scanf("%c ", &c); // scanf函数的第一个参数中，如果在占位符之后出现了空白字符，那么在进入输入时，一定要将这个空白字符用一个非空白字符代替，这样才能使得输入结束
	printf("c = %c\n", c);
}

int main()
{
	//io_line();
	//io_character();
	//input();

	scanf_note();

	return 0;
}
