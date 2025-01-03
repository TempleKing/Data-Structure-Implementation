#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

//为了使得插入删除操作的复杂度都为O(1)，新加一个尾节点指向最后
struct Node* front = NULL;//将它们设为全局变量
struct Node* rear = NULL;

void Enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp -> data = x;
    temp -> next = NULL;

    if(front == NULL && rear ==NULL){
        front = rear = temp;
        return;
    }
    rear -> next = temp;//连接新插入
    rear = temp;//重置尾节点
}

void Dequeue()
{
    struct Node* temp = front;//新建节点变量仅仅是为了释放内存free
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
