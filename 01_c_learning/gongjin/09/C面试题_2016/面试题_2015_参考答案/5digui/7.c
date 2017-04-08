//递归实现回文判断（如：abcdedbca就是回文，判断一个面试者对递归理解的简单程序）
#include <stdio.h>
#include <string.h>

int loopstr(char *str, int n) {

     if(n<=1) 
     	return 1;
     else 
     	if(str[0]==str[n-1])   
			return loopstr(str+1, n-2);
     	else     
     		return 0;
}

int main(void) 
{
    char *str = "abcdedcba";
    printf("%s: %s\n", str, loopstr(str, strlen(str)) ? "Yes" : "No");
	return 0;
}
    
