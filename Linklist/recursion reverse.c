#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;



int main()
{
    struct Node* head = NULL;//局部变量
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    Print(head);

    printf("\n");

    head = Reverse(head);
    Print(head);
}


Node* Reverse(struct Node* head)
{
    if(head->next == NULL || head == NULL)//判断链表是否为空
    {
        return head;
    }


    Node* newHead = Reverse(head->next);//newHead变量用于递归到最后一个节点

    //从此开始反向连接
    head->next->next = head;//反向连接
    head->next = NULL;

    return newHead;
}


//插入
Node* Insert(Node* head, int data){//此函数返回的是一个指针head
    Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
        head = temp;//赋予head变量 下次插入head不会变
    else{
        Node* temp1 = head;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;//退出循环 接上新插入的节点
    }
    return head;
}


void Print(struct Node* head)//头节点p
{
    if(head == NULL) return;//退出条件
    printf("%d", head->data);
    Print(head->next);
}
