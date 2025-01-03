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
	if (n == 1) {//��������λ����ͷ��
		temp1->next = head;//ָ��ָ��ǰ�����ͷhead
		head = temp1;//��ʱheadָ���½ڵ�
		return;
	}
	Node* temp2 = head;//temp2���ڱ���������λ������λ�õ�ǰһ���ڵ�
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;//
	temp2->next = temp1;//temp2������temp1
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
