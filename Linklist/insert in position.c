#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* head;

void Insert(int data, int n)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1) {//如果插入的位置是头部
		temp1->next = head;//指针指向当前链表的头head
		head = temp1;//此时head指向新节点
		return;
	}
	Node* temp2 = head;//temp2用于遍历链表，定位到插入位置的前一个节点
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;//
	temp2->next = temp1;//temp2连接上temp1
}


void Print() {
	Node* temp = head;
	while (temp != NULL) {
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	head = NULL;
	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 1);
	Insert(5, 2);
	Print();
}
