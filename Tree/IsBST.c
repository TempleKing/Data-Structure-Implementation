#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// �������Ľڵ�ṹ��
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ����һ���µĽڵ�
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// �ж��Ƿ�Ϊ�����������ĸ�������
bool IsBstUtil(struct Node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;  // �����Ƕ���������
    }

    // ��ǰ�ڵ��ֵ���������Сֵ��С�����ֵ
    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    // �ݹ�����������������  +1 �� -1 ��Ϊ������ֵ��ȵ����
    return IsBstUtil(root->left, minValue, root->data - 1) &&//maxValue ����Ϊ��ǰ�ڵ��ֵ�� 1����ʾ�������е����нڵ��ֵ�����ϸ�С�ڵ�ǰ�ڵ��ֵ
           IsBstUtil(root->right, root->data + 1, maxValue);//minValue ����Ϊ��ǰ�ڵ��ֵ�� 1����ʾ�������е����нڵ��ֵ�����ϸ���ڵ�ǰ�ڵ��ֵ
}

// �жϸ��������Ƿ��Ƕ���������
bool IsBinarySearchTree(struct Node* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // ʾ��������һ������������
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(25);

    if (IsBinarySearchTree(root)) {
        printf("The tree is a Binary Search Tree.\n");
    } else {
        printf("The tree is not a Binary Search Tree.\n");
    }

    return 0;
}
