1.
struct foo {
    int a;   
    int b;  
    char c[10];
};
static void test20()
{
    struct foo s1 = { 
        .a = 10, 
        .b = 30, 
    };  
    struct foo s2 = s1;    
    char s[15] = {0};
    printf("%d, %d, %d, %d, %d, %d\n", sizeof("hello"), sizeof("hello" + 1), 
        sizeof(s), sizeof(s + 1), sizeof(s1), s2.b); 
}



2.
struct {
    int x;
    struct {
        int y, z;
    } nested;
} i = { .nested.y = 5, 6, .x = 1, 2 };
i.x   i.nested.y   i.nested.z 为多少  


3.
对于以下的变量定义，表达式______符合C语言语法。符合语法的各代表什么意思
struct node
{
        int len;
        char *pk;
}x = {2, "right"}, *p = &x;
a. p->pk       b. (*p).pk        c. *p->pk       d. *x.pk



4.
#include <stdio.h>
int main(void)
{
    union
    {
        char i[2];      
        short int k; 
    }r;
    r.i[0]=0; 
    r.i[1]=2; 
    printf("%#x\n",r.k);  

    return 0;
}

5.
输出结果
enum {
    FALSE,
    TRUE,
};

static void test22()
{
    enum {
        A = '\0', B = 10, C = 20,
    } foo;

    foo = 100;
    foo = A;
    printf("%d, %d, %d\n", foo, C, sizeof(foo));
}

6
下面这段程序会输出什么，为什么？
enum {false,true};
int main()
{
    int i=1;

    do
    {
         printf("%d\n",i);
        i++;
        if(i < 15)
            continue;

        printf("ok\n");
    } while(false);

    return 0;
}


7.
static void foo1(int *p, int *q){   
    int tmp = *p;   *p = *q;    *q = tmp;
}
static void foo2(int *p, int *q){   
    int *tmp = p;   p = q;  q = tmp;
}
static void test5()
{
    int a = 3, b = 5;
    void (*p[2])(int*, int*);
    p[0] = foo1;
    p[1] = foo2;
    p[0](&a, &b);
    printf("%d %d\n", a, b); 
    p[1](&a, &b);
    printf("%d %d\n", a, b); 
}

static void test6()
{
    int a = 3, b = 5;
    void (*s[2])(int*, int*);
    void (*(*p)[2])(int*, int*) = &s; 

    s[0] = foo1;
    s[1] = foo2;

    s[0](&a, &b);
    printf("%d %d\n", a, b); 

    (*p)[1](&a, &b); 
    printf("%d %d\n", a, b); 
}


8.
struct foo {
    int data;
    char *str;
    char par[];
};
static void test19()
{
    struct foo s[3] = { {1, "hello"}, {.str = "world"} };
    char str[] = "\x11\x22\x33\x44kernel";
    memcpy(s, str, sizeof(str));
    printf("size=%d\n", sizeof(struct foo));
    printf("%x\n", s[0].data);
    printf("%s\n", s[0].par);
    printf("%s\n", s[1].str);
}

9.
typedef struct {
    char *key;
    char *value;
} T1;
typedef struct {
    long type;
    char *value;
} T3;
T1 a[] = {
    { "", ((char *)&((T3) { 1, (char *)1 })) }
};
int main()
{
    T3 *pt3 = (T3*)a[0].value;
    return pt3->value;
}






