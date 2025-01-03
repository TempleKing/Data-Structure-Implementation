#include<stdio.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

// 创建新节点
struct BstNode* GetNewNode(int data) {
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入节点
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


int FindMin(struct BstNode* root){
    if(root == NULL){
        printf("Error: Tree is Empty");
        return -1;
    }
    while(root -> left != NULL)
    {
        root = root -> left;
    }
    return root -> data;

    //使用递归
    //else if(root -> left != NULL) return root -> data;
    //return FindMin(root -> left)
}


int FindMax(struct BstNode* root){
    if(root == NULL){
        printf("Error: Tree is Empty");
        return -1;
    }
    while(root -> right != NULL)
    {
        root = root -> right;
    }
    return root -> data;

}

int main() {
    struct BstNode* root = NULL;

    // 插入一些数据
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    // 查找最小值和最大值
    printf("Minimum value: %d\n", FindMin(root));
    printf("Maximum value: %d\n", FindMax(root));

    return 0;
}
