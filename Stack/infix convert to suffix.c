//逻辑
//遍历数组 运算符会压入栈，如果下一个运算符的优先级比Top低，则先Pop一个运算符再将新运算符压入栈
//遇到左括号会压入栈 遇到下一个右括号会pop包括左括号以上的所有运算符
//当所有元素都遍历完后，再将剩余运算符全部Pop出来


#include<stdio.h>
#define MAX_SIZE 100

typedef struct Node
{
    char data;
    struct Node* next;
}Node;

char res[MAX_SIZE] = {0};

Node* Push(Node* p, char data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    //从链表头部插入  p是head
    temp -> next = p;
    p = temp;
    return p;
}

Node* Pop(Node* p)
{
    Node* temp = p;
    if(p == NULL)
        return p;
    p = p -> next;
    free(temp);
    return p;
}

void Print(Node* p)
{
    if(p == NULL)
        return;
    printf("The stack is:");
    while(p != NULL)
    {
        printf("c", p -> data);
        p -> next;
    }
    printf("\n");
}

char Top(Node* p)
{
    if(p != NULL)
        return(p -> data);
}

int IsEmpty(Node* p)
{
    if(p==NULL)
        return 1;
    else
        return 0;
}

int IsLeftBuckle(char n)
{
    if( n == '(')
        return 1;
    else
        return 0;
}

int HasHigherPrec(char exp1, char exp2)//exp1是栈里 exp2是数组里
{
    switch(exp1)
    {
        case'+':
        case'-':
            switch(exp2)
            {
                case'+':
                case'-':return 1; break;
                case'*':
                case'/':
                case'^':return 0; break;
            }
            break;
        case'*':
        case'/':
        case'^':
            switch(exp2)
            {
                case'+':
                case'-':
                case'*':
                case'/':
                case'^':return 1; break;
            }
            break;
    }
}

char* InfixToPostfix(char exp[]){
    int n = 0;//保存后缀表达式下标
    Node* stack = NULL;//初始化栈
    char* res = (char*)malloc(sizeof(char) * MAX_SIZE);//后缀表达式结果

    for(int i = 0; i < strlen(exp); i++){
        //如果是数字
        if((exp[i] >= '0') && exp[i] <= '9'){
            res[n++] = exp[i];//数字直接放结果
            }

        //如果是操作符
        else if((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') ||
                 (exp[i] == '/') || (exp[i] == '^'))
        {
                    //更高优先级运算符从栈弹出，直到不优于当前操作符
            while(!IsEmpty(stack) && !IsLeftBuckle(Top(stack)) && HasHigherPrec(Top(stack), exp[i]))
            {
                res[n++] = Top(stack);
                stack = Pop(stack);
                }
                    //当前操作符压入栈
            stack = Push(stack, exp[i]);
        }
        //如果是左括号直接压栈
        else if(exp[i] == '('){
            stack = Push(stack, exp[i]);
                }
        //如果是右括号 弹出栈直到左括号
        else if(exp[i] == ')'){
            while(!IsEmpty(stack) && !IsLeftBuckle(Top(stack))){
                res[n++] = Top(stack);//弹出栈顶操作符
                stack = Pop(stack);//更新栈
            }
            stack = Pop(stack);//弹出左括号
        }
    }

    //遍历完所有的表达式后 弹出所有剩余操作符
    while(!IsEmpty(stack)){
        res[n++] = Top(stack);
        stack = Pop(stack);
    }

    res[n] = '\0';//在结果字符串加上结束符
    return res;


}



int main()
{
    char n[MAX_SIZE];
    gets(n);
    char* postfix_exp = InfixToPostfix(n);
    for(int i = 0; i < strlen(postfix_exp); i++)
    {
        printf("%c", postfix_exp[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

