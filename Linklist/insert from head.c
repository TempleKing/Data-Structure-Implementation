#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//�ṹ��
struct Node{
    int data;
    struct Node* next;//ָ����һ�ڵ��ָ�� Node*��ʾָ������
};



struct Node* head;//ͷָ�� ȫ�ֱ���
//void Insert(int x);
//void Print(void);

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//������һ���ڵ㣨�ṹ�壩
    temp->data = x;//temp����ָ��ýڵ�λ�� ��ͷ��ʾָ����ָ��Ľṹ��
    temp->next = head;//�²���Ľṹ�����ӵ�head
    head = temp;//�½ڵ���������ĵ�һ���ڵ�
}

void Print()
{
    struct Node* temp = head;//�ֲ�����ָ��Node��ָ�� ���ܸ���ͷָ��

    while(temp != NULL)//������������
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main(){
    head = NULL;//Ŀǰ�ǿ�����
    printf("How many numbers?\n");
    int n, i, x;//n�洢������iѭ���ñ�����x��������
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);//����ʹ�ӡ����
        Print();
    }
    return 0;
}
