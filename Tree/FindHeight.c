#include <stdio.h>
#include <stdlib.h>


struct BstNode {
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



int max(int a, int b)
{
    return(a > b)? a:b;
}


int FindHeight(struct BstNode *root){
    if(root == NULL)
        return -1;
    return max(FindHeight(root -> left), FindHeight(root -> right)) + 1;
}
//函数会不断地递归调用自身，直到到达树的叶子节点（其左右子节点为空）。从叶子节点开始，逐层返回各子树的高度，最终返回整棵树的高度。


int main() {
    struct BstNode* root = NULL;

    // 插入一些数据
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    // 输出树的深度
    printf("Height of the tree: %d\n", FindHeight(root));

    return 0;
}
