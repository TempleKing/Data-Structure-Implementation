#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];d
int top = -1;

int Push(int x){
    if(top == MAX_SIZE -1){
        printf("Error: stack overflow\n");
        return;
    }

    top++;
    A[top] = x;//等同于A[++top]=x
}

void Pop(){
    if(top == -1){
        printf("Error: No element to pop \n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void Print(){//用于可视化过程 只是测试
    int i;
    printf("Stack:");
    for(i = 0; i <= top; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main(){
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
}
