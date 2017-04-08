#include <stdio.h>

/*
	"nm 可执行文件" // 查看可执行文件的符号表的
	D data段 变量是非静态
	d data段 变量是静态变量

	B/b .bss段 
 */

int a1;
static int a2;
int a3 = 100;
static int a4 = 100;

int main()
{
	//char *s = "hello world";
	
	//const == constant
	const int a; // 定义了一个只读read-only变量，这个变量的值是不变的
//	a = 2; // a是只读的，只能在声明的同时进行初始化

	int b = 1;
	b = 10;

	const char *s = "hello"; // "hello"这个字符串本身就是不能被修改的，并不因为指向这个字符串的指针前面加了const, "hello"字符串的属性就会发生变化。这里的const的作用，仅仅是让编译器提早发现错误。
	//*s = 'W'; // 这一行编译报错

	/*
	char *t = s;
	*t = 'H';
	printf("s = %s\n", s);
*/
	const int *ss; // 这一行的声明表示：ss指针指向的对象，不能通过ss去修改，但并不是说ss指向的这个变量本身一定不能修改
	ss = &b;
	//*ss = 1000; // 错误
	b = 2000;

	char * const s2; // s2这个指针变量本身是只读的，也就是说s2一旦指向了一个变量，就不能指向其他变量的
	//s2 = "he"; //error s2不能被修改指向

	const int * const s3 = &b; // s3和*s3都是只读的
	//s3 = &a;
	//*s3 = 100;
	b = 200;

	const char s4[] = "1234"; // s4数组中的元素是const char 类型
	//*s4 = 'w';

	return 0;
}
