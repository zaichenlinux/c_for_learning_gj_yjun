/*

 int printf(const char *format, ...);

 printf  --> fputc  -->putchar
*/

 #include <stdio.h>
 #include <stdarg.h>
 #include <string.h>
//%c %d %s
 //putchar()
//该函数将字符串倒置
 void change_str(char *s)
 {
 	char *p1 = s;
 	char *p2 = s+strlen(s) -1;
 	for(;p1<p2;p1++, p2--) {
 		char tmp = *p1;
 		*p1 = *p2;
 		*p2 = tmp;
 	}
 }

 //整型变量转换成字符串
 //1234  1   2  3  4   '1'  '2'  '3' '4'
 //1 + '0'
void int_to_str(int n, char *s)
{
	int i = 0;
	while(n) {
		s[i++] = n%10 + '0';
		n /= 10;
	}
	change_str(s);	
}

//返回是输出到屏幕的字符数
//my_printf("c = %c, d = %d, s = %s", c, d, s);
int my_printf(const char *format, ...)
{
	va_list ap; //1.定义一个指针
	va_start(ap, format);

	char s[1000] = {0}; //存放字符串
	int count = 0;//统计打印的字符的个数

	for(; *format;format++ ) {
		if('%' == *format){
			format++;
			switch(*format){
				case  'd':
				int_to_str(va_arg(ap,int), s);
				for(int i =0;i<strlen(s);i++) {
					putchar(s[i]);
					count++;
				}
				break;

				case 'c':
				putchar((char)va_arg(ap, int));
				count++;
				break;

				case 's':
				strcpy(s, va_arg(ap, char *));
				for(int i =0;i<strlen(s);i++) {
					putchar(s[i]);
					count++;
				}
				break;
				default:
					break;
			}

		}else {
			putchar(*format);
			count++;
		}

	}

	va_end(ap);
	return count;
}


 int main(int argc, char const *argv[])
 {
 	int k1, k2;
 	k1 = printf("hello c = %c, world = %d, linux = %s\n",'a', 1234, "lalalala" );
 	k2 = my_printf("hello c = %c, world = %d, linux = %s\n",'a', 1234, "lalalala" );

 	printf("k1 = %d, k2 = %d\n",k1, k2 );
 	return 0;
 }