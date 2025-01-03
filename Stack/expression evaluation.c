//后位表达式用栈实现 遍历长度n数组 检测到数值存入栈 检测到运算符pop两次栈并作运算操作，算出的结果再次存入栈。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Node
{
    char data;
    struct Node* next;
}Node;

char Perform(char num1, char n, char num2);
Node* Push(Node* p, char data);
Node* Pop(Node* p);
char Top(Node* p);


EvaluatePostfix(char exp[])
{
    struct Node* stack = NULL;
    for(int i = 0; i <= strlen(exp); i++)
    {
        if(exp[i] <= '9' && exp[i] >='0')
        {
            stack = Push(stack, exp[i]);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || (exp[i]=='^'))
        {
            char num2 = Top(stack);
            stack = Pop(stack);
            char num1 = Top(stack);
            stack = Pop(stack);
            stack = Push(stack,Perform(num1,exp[i],num2));//
        }
    }
    return Top(stack);
}


char Perform(char num1,char n,char num2)//char与值转化
{
    switch(n)
    {
        //注意48的使用很关键
        case '+':return 48+(num1-48)+(num2-48);
        case '-':return 48+(num1-48)-(num2-48);
        case '*':return 48+(num1-48)*(num2-48);
        case '/':return 48+(num1-48)/(num2-48);
        case '^':return 48+(num1-48)^(num2-48);
    }
}



Node* Push(Node* p,char data)
{
    Node* temp =(Node*)malloc(sizeof(Node));
    temp->data = data;
    //在链表头部插入
    temp->next = p;
    p = temp;
    return p;
}

Node* Pop(Node* p)
{
    Node* temp = p;
    if(p==NULL)
        return p;
    p = p->next;
    free(temp);
    return p;
}

void Print(Node* p)
{
    if(p==NULL)
        return;
    printf("stack is: ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

char Top(Node* p)
{
    if(p!=NULL)
        return (p->data);
}

int IsEmpty(Node* p)
{
    if(p==NULL)
        return 1;
    else
        return 0;
}


int main()
{
    char n[MAX_SIZE];
    gets(n);
    // for(int i = 0;i<strlen(n);i++)
    //     printf("%c ",n[i]);
    // printf("\n");
    printf("result is: %d",EvaluatePostfix(n)-48);
    system("pause");
    return 0;
}
