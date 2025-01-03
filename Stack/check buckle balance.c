#include<stdio.h>


#define MAX_SIZE 100

/*
struct Node*
{   int data
    int next
};
*/

char stack[MAX_SIZE] = {0};//数组
int top = -1;

void Push(char x)
{
    if(top == MAX_SIZE)
    {
        printf("the stack is overflow!");
        return;
    }
    stack[++top] = x;
}


void Pop()
{
    if(top == -1)
    {
        printf("the stack is empty");
        return;
    }
    top--;
}

int Top()
{
    if(top == -1)
    {
        printf("the stack is empty");
        return;
    }
    return stack[top];
}

void Print()
{
    printf("The stack is:\n");
    for(int i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
}


int Balance(char c[])
{
    for(int i = 0; i <= strlen(c); i++)
    {
        if((c[i] == '(') || (c[i] == '[') || (c[i] == '{'))
            {
                Push(c[i]);
            }
        else if((c[i] == ')') || (c[i] == ']') || (c[i] == '}'))//只需要与栈顶进行比较
            {
                if((c[i] - Top() == 1) || (c[i]-Top() == 2))
                {
                    Pop();
                }
                else
                    return 0;
            }
    }
    IsEmpty()?1:0;
}

int IsEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}


int main()
{
    char n[MAX_SIZE];
    int flag = -1;//是否平衡的变量

    printf("Enter a string:\n");
    gets(n);

    flag = Balance(n);

    if(flag == 1)
        printf("success!\n");
    else
        printf("fail...\n");

    system("pause");
    return 0;
}


/*
( 的 ASCII 值是 40
) 的 ASCII 值是 41
[ 的 ASCII 值是 91
] 的 ASCII 值是 93
{ 的 ASCII 值是 123
} 的 ASCII 值是 125
*/
