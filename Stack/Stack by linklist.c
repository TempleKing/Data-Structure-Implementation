//��ͷ������O(1)
#include<stdio.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop(){
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

//�Լ�ʵ�� top IsEmpty Print����



int main()
{
    Push(2);
    Push(4);
    Push(6);
    Pop();
}
