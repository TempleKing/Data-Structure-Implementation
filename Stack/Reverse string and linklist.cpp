//C++���� �������


/*
#include<stack>
#include<iostream>
#include<cstring>//**<string.h>�ǲ�����strlen�ģ�Ҫʹ��cstring**


using namespace std;
void Reverse(char C[], int n)//n���ַ�����
{
    stack<char> S;//�����ַ�ջ
    //push��ѭ��
    for(int i=0; i<n; i++){
        S.push(C[i]);
    }
    //pop��ѭ��
    for(int i=0; i<n; i++){
        C[i] = S.top();
        S.pop();
    }
}

int main(){
    char C[51];
    printf("Enter a string:");
    gets(C);
    Reverse(C, strlen(C));
    printf("Output = %s", C);
}
*/

#include <stack>
#include <iostream>
#include <cstring>  // ���ﲻ��Ҫ���ģ�std::string.h Ҳ���ԣ��������� <cstring>

// ��������ڵ�
struct Node {
    int data;
    Node* next;
};

// ���� head ��ȫ�ֱ�������ʾ�����ͷ���
Node* head = nullptr;

void Reverse() {
    if (head == NULL) return;  // �������Ϊ�գ�ֱ�ӷ���

    std::stack<Node*> S;  // ʹ��ջ�洢����ڵ��ָ��
    Node* temp = head;

    // �����нڵ�����ջ��
    while (temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }

    // ȡ��ջ��Ԫ����Ϊ�µ�ͷ���
    temp = S.top();
    head = temp;
    S.pop();

    // ��ջ�еĽڵ���������
    while (!S.empty()) {
        temp->next = S.top();  // ���õ�ǰ�ڵ�� next Ϊջ���ڵ�
        S.pop();
        temp = temp->next;  // �ƶ� temp ָ��
    }

    // ��������β���� next Ϊ NULL
    temp->next = NULL;
}

// �������������ڴ�ӡ���������ã�
void PrintList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// ������������������ڵ㣨�����ã�
Node* CreateNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    // ����һ������1 -> 2 -> 3 -> 4 -> 5
    head = CreateNode(1);
    head->next = CreateNode(2);
    head->next->next = CreateNode(3);
    head->next->next->next = CreateNode(4);
    head->next->next->next->next = CreateNode(5);

    std::cout << "Original list: ";
    PrintList(head);

    // ���÷�ת����
    Reverse();

    std::cout << "Reversed list: ";
    PrintList(head);

    return 0;
}

