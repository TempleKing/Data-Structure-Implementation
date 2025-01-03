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
    head = Insert(head,2);//��Ϊ���head�Ǿֲ�����
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);
    Print(head);
    head = Reverse(head);
    Print(head);
}

Node* Insert(Node* head, int data){//�˺������ص���һ��ָ��head
    Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
        head = temp;//����head���� �´β���head�����
    else{
        Node* temp1 = head;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;//�����²���Ľڵ�
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
    struct Node *current, *prev, *next;//ǰ�к�
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;//��תָ�����
        prev = current;//��ǰ�ƶ�
        current = next;//��ǰ�ƶ�
    }
    head = prev;
    return head;
}
