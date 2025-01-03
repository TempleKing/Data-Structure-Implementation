//C++语言 面向对象


/*
#include<stack>
#include<iostream>
#include<cstring>//**<string.h>是不包括strlen的，要使用cstring**


using namespace std;
void Reverse(char C[], int n)//n是字符数量
{
    stack<char> S;//创建字符栈
    //push的循环
    for(int i=0; i<n; i++){
        S.push(C[i]);
    }
    //pop的循环
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
#include <cstring>  // 这里不需要更改，std::string.h 也可以，但建议用 <cstring>

// 定义链表节点
struct Node {
    int data;
    Node* next;
};

// 假设 head 是全局变量，表示链表的头结点
Node* head = nullptr;

void Reverse() {
    if (head == NULL) return;  // 如果链表为空，直接返回

    std::stack<Node*> S;  // 使用栈存储链表节点的指针
    Node* temp = head;

    // 将所有节点推入栈中
    while (temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }

    // 取出栈顶元素作为新的头结点
    temp = S.top();
    head = temp;
    S.pop();

    // 将栈中的节点连接起来
    while (!S.empty()) {
        temp->next = S.top();  // 设置当前节点的 next 为栈顶节点
        S.pop();
        temp = temp->next;  // 移动 temp 指针
    }

    // 设置链表尾部的 next 为 NULL
    temp->next = NULL;
}

// 辅助函数：用于打印链表（调试用）
void PrintList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// 辅助函数：创建链表节点（调试用）
Node* CreateNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    // 创建一个链表：1 -> 2 -> 3 -> 4 -> 5
    head = CreateNode(1);
    head->next = CreateNode(2);
    head->next->next = CreateNode(3);
    head->next->next->next = CreateNode(4);
    head->next->next->next->next = CreateNode(5);

    std::cout << "Original list: ";
    PrintList(head);

    // 调用反转函数
    Reverse();

    std::cout << "Reversed list: ";
    PrintList(head);

    return 0;
}

