
//用递归颠倒一个栈。例如输入栈{1, 2, 3, 4, 5}，1在栈顶。颠倒之后的栈为{5, 4, 3, 2, 1}，5处在栈顶。

#include <stdio.h>

int stack[256];
int top = -1;
void reverse_stack();
void put_to_bottom(int val);

void reverse_stack()
{
    int tmp;
    if (top <= 0)
        return;
    tmp = stack[top--];
    reverse_stack();
    put_to_bottom(tmp);
}

void put_to_bottom(int val)
{
    int tmp;

    if (top < 0) //stack empty
    {
        ++top;
        stack[top] = val;
        return ;
    }

    tmp = stack[top--];
    put_to_bottom(val);
    stack[++top] = tmp;
}

int main()
{
    int i;
    
    printf("Original stack:\n");
    for (i = 0; i < 5; i++) {
        stack[++top] = i + 1;
        printf("%d,", i+1);
    }
    printf("\n");

    reverse_stack();

    printf("Reversed stack:\n");
    for (i = 0; i < 5; i++) {
        printf("%d,", stack[i]);
    }
    printf("\n");

}
