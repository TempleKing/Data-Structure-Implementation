#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* Insert(Node* head, int data);
void Print(Node* head);
Node* Reverse(Node* head);


int main()
{
    struct Node* head = NULL;
    head = Insert(head,2);//因为这次head是局部变量
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);
    Print(head);
    head = Reverse(head);
    Print(head);
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

void Print(Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* Reverse(struct Node* head){
    struct Node *current, *prev, *next;//前中后
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;//反转指针操作
        prev = current;//向前移动
        current = next;//向前移动
    }
    head = prev;
    return head;
}
