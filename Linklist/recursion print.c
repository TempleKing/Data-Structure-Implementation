//�ݹ�-�����Լ��ķ���
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
//�������
void Print(struct Node* p)//ͷ�ڵ�p
{
    printf("%d", p->data);
    Print(p->next);

    if(p == NULL) return;//�˳�����
}*/


//�������  ��ȫ���ݹ���ɺ������ ������ջ�Ľṹ�й�ϵ
void Print(struct Node* p)//ͷ�ڵ�p
{
    if(p == NULL) return;//�˳�����
    Print(p->next);
    printf("%d ", p->data);

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

int main()
{
    struct Node* head = NULL;//�ֲ�����
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    Print(head);
}
