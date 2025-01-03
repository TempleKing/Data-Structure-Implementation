//�߼�
//�������� �������ѹ��ջ�������һ������������ȼ���Top�ͣ�����Popһ��������ٽ��������ѹ��ջ
//���������Ż�ѹ��ջ ������һ�������Ż�pop�������������ϵ����������
//������Ԫ�ض���������ٽ�ʣ�������ȫ��Pop����


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
    //������ͷ������  p��head
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

int HasHigherPrec(char exp1, char exp2)//exp1��ջ�� exp2��������
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
    int n = 0;//�����׺���ʽ�±�
    Node* stack = NULL;//��ʼ��ջ
    char* res = (char*)malloc(sizeof(char) * MAX_SIZE);//��׺���ʽ���

    for(int i = 0; i < strlen(exp); i++){
        //���������
        if((exp[i] >= '0') && exp[i] <= '9'){
            res[n++] = exp[i];//����ֱ�ӷŽ��
            }

        //����ǲ�����
        else if((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') ||
                 (exp[i] == '/') || (exp[i] == '^'))
        {
                    //�������ȼ��������ջ������ֱ�������ڵ�ǰ������
            while(!IsEmpty(stack) && !IsLeftBuckle(Top(stack)) && HasHigherPrec(Top(stack), exp[i]))
            {
                res[n++] = Top(stack);
                stack = Pop(stack);
                }
                    //��ǰ������ѹ��ջ
            stack = Push(stack, exp[i]);
        }
        //�����������ֱ��ѹջ
        else if(exp[i] == '('){
            stack = Push(stack, exp[i]);
                }
        //����������� ����ջֱ��������
        else if(exp[i] == ')'){
            while(!IsEmpty(stack) && !IsLeftBuckle(Top(stack))){
                res[n++] = Top(stack);//����ջ��������
                stack = Pop(stack);//����ջ
            }
            stack = Pop(stack);//����������
        }
    }

    //���������еı��ʽ�� ��������ʣ�������
    while(!IsEmpty(stack)){
        res[n++] = Top(stack);
        stack = Pop(stack);
    }

    res[n] = '\0';//�ڽ���ַ������Ͻ�����
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

