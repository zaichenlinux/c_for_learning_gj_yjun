#include <stdio.h>
#include <string.h>
#include<math.h>
void  ten_two(int n)  // ten_two十进制转换二进制；
{       
        int tmpN;
        int i=0;
        int j;
        char ch[10000];
        while(n > 0){
        tmpN = n % 2;  
        n = n / 2;        
        ch[i++] = tmpN + '0'; 
    }
       printf("输出2进制数为:") ;
        for(j=0;j<100;j++)
{
        putchar(ch[i--]);
        if(ch[i]=='\0')
        break;        
}
        putchar('\n');
}
void   hex_ten (int count,char *p)// 16进制转换为10进制
{
        int i,sum=0;
        for(i=2;*(p+i) != '\0'; i++)
       {
         if  ((int)*(p+i)<58 && (int)*(p+i)>47 )             // 0到9 转换成ASCLL 为48-57
         sum+=(int)(*(p+i)-48) * pow(16,count);
         else if( (int)*(p+i)<103 && (int)*(p+i)>96)  // a到f 转换成ASCLL 为97-102
         sum+=(int)(*(p+i)-87) * pow(16,count);
         count--;
        }
        printf("输出10进制数:%d\n",sum);
        ten_two(sum); //10 ->2
}
int two_ten(int count,char *p)  // 2进制转换为10进制
{
        int i,sum=0;
        for(i=2;*(p+i) != '\0'; i++)
{       
        sum+=(int)(*(p+i)-48) * pow(2,count);  
        count--;
}
        printf("输出10进制数:%d\n",sum);
        return sum;
       

}
int  str_ten(char *s)  //10字符串转换成整形数
{
    int i, n;
    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <='9'; ++i)
   {
     n = 10 * n + (s[i] - '0');
    }
        return n;

}
 void ten_hex(int m)  // ten_hex 10进制转换16进制；
{       
        int tmpN;
        int i=0;
        int j;
        char ch[10000];
        while(m > 0)
{
        tmpN = m % 16;  
        m =m / 16;
        if(tmpN>9)
        ch[i] = (char)(tmpN+87);      
        else
        ch[i]=tmpN + '0' ;    
        i++;      
}
        printf("输出16进制数为:") ;
        for(j=0;j<100;j++)
{
        putchar(ch[i--]);
        if(ch[i]=='\0')
        break;        
}
        putchar('\n');
}

int main(int argc,char **agrv)
{
        char b[1000];
        int n,m;
        char *p=b;
        printf("自动识别16进制(0x)、10进制(无)、2进制(0b)之间相互转换\n");
        printf("输入如:0x0a(16进制) 0b1010(2进制) 100(10进制)\n");
        scanf("%s",b);  //入口
        int count=strlen(p)-3;       
        if(*(p)=='0'&&(*(p+1)=='x'))  // 0x前缀 为16进制转换成
{
        hex_ten(count ,p);
}
       else if (*(p)=='0'&&(*(p+1)=='b'))
{
        m=two_ten(count,p);
         ten_hex(m);      
}
       else if(*(p)!='0'&&(*(p+1)!='b')&&(*(p+1)!='x'))
{
        n= str_ten(p);
        ten_hex(n); 
        ten_two(n);          
        
}
        return 0;
}

