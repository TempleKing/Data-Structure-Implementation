#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//结构体
struct Node{
    int data;
    struct Node* next;//指向下一节点的指针 Node*表示指针声明
};



struct Node* head;//头指针 全局变量
//void Insert(int x);
//void Print(void);

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//创建了一个节点（结构体）
    temp->data = x;//temp变量指向该节点位置 箭头表示指针所指向的结构体
    temp->next = head;//新插入的结构体连接到head
    head = temp;//新节点变成了链表的第一个节点
}

void Print()
{
    struct Node* temp = head;//局部变量指向Node的指针 不能更改头指针

    while(temp != NULL)//遍历整个数组
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main(){
    head = NULL;//目前是空链表
    printf("How many numbers?\n");
    int n, i, x;//n存储个数，i循环用变量，x存数字用
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);//插入和打印功能
        Print();
    }
    return 0;
}
