//递归-调用自己的方法
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
//正向输出
void Print(struct Node* p)//头节点p
{
    printf("%d", p->data);
    Print(p->next);

    if(p == NULL) return;//退出条件
}*/


//反向输出  先全部递归完成后再输出 反向与栈的结构有关系
void Print(struct Node* p)//头节点p
{
    if(p == NULL) return;//退出条件
    Print(p->next);
    printf("%d ", p->data);

}




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
        temp1->next = temp;//接上新插入的节点
    }
    return head;
}

int main()
{
    struct Node* head = NULL;//局部变量
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    Print(head);
}
