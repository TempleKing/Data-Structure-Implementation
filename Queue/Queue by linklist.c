#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

//Ϊ��ʹ�ò���ɾ�������ĸ��Ӷȶ�ΪO(1)���¼�һ��β�ڵ�ָ�����
struct Node* front = NULL;//��������Ϊȫ�ֱ���
struct Node* rear = NULL;

void Enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp -> data = x;
    temp -> next = NULL;

    if(front == NULL && rear ==NULL){
        front = rear = temp;
        return;
    }
    rear -> next = temp;//�����²���
    rear = temp;//����β�ڵ�
}

void Dequeue()
{
    struct Node* temp = front;//�½��ڵ����������Ϊ���ͷ��ڴ�free
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front -> next;
    }
    free(temp);
}


int Front()
{
    if(front == NULL){
        printf("The queue is empty\n");
        return;
    }
    return front -> data;
}

void Print()
{
    struct Node* temp = front;
    while(temp != NULL)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}


int main()
{
    Enqueue(2); Print();
    Enqueue(4); Print();
    Enqueue(6); Print();
    Dequeue(); Print();
    Enqueue(8); Print();
}
