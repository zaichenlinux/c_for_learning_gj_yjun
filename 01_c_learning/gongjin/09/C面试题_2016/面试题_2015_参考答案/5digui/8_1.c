#include <stdio.h>
 
void convert(int *result, int n)  
{  
    if(n >= 10) {         
        convert(result + 1, n/10);  
    }  
    *result = n % 10;  
}  

int main(void) 
{
    int num, save_num;  
    printf("请输入整数\n"); 
    scanf("%d",&num);  
    save_num = num;
    
    int n = 0;
    while (num) {
    	num /= 10;
    	n++;
    }
    
    int i, arr[n];
    convert(arr,save_num);  
    for(i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  

	return 0;
}
