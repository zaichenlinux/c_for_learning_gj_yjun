#include <iostream>

void UpperCase( char str[] ) // 将 str 中的小写字母转换成大写字母
{
    for( size_t i=0; i<sizeof(str)/sizeof(str[0]); ++i )
        if( 'a'<=str[i] && str[i]<='z' )
            str[i] -= ('a'-'A' );
}
int main()
{
    char str[] = "aBcDe";
    cout << "str字符长度为: " << sizeof(str)/sizeof(str[0]) << endl;
    UpperCase( str );
    printf("%s\n", str);
    return 0;
}










