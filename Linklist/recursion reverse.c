#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;



int main()
{
    struct Node* head = NULL;//�ֲ�����
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
    if(head->next == NULL || head == NULL)//�ж������Ƿ�Ϊ��
    {
        return head;
    }


    Node* newHead = Reverse(head->next);//newHead�������ڵݹ鵽���һ���ڵ�

    //�Ӵ˿�ʼ��������
    head->next->next = head;//��������
    head->next = NULL;

    return newHead;
}


//����
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
        temp1->next = temp;//�˳�ѭ�� �����²���Ľڵ�
    }
    return head;
}


void Print(struct Node* head)//ͷ�ڵ�p
{
    if(head == NULL) return;//�˳�����
    printf("%d", head->data);
    Print(head->next);
}
