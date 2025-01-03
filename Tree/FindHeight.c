#include <stdio.h>
#include <stdlib.h>


struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};


// �����½ڵ�
struct BstNode* GetNewNode(int data) {
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ����ڵ�
struct BstNode* Insert(struct BstNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}



int max(int a, int b)
{
    return(a > b)? a:b;
}


int FindHeight(struct BstNode *root){
    if(root == NULL)
        return -1;
    return max(FindHeight(root -> left), FindHeight(root -> right)) + 1;
}
//�����᲻�ϵصݹ��������ֱ����������Ҷ�ӽڵ㣨�������ӽڵ�Ϊ�գ�����Ҷ�ӽڵ㿪ʼ����㷵�ظ������ĸ߶ȣ����շ����������ĸ߶ȡ�


int main() {
    struct BstNode* root = NULL;

    // ����һЩ����
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    // ����������
    printf("Height of the tree: %d\n", FindHeight(root));

    return 0;
}
