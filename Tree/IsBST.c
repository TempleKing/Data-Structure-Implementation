#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// 定义树的节点结构体
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 创建一个新的节点
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// 判断是否为二叉搜索树的辅助函数
bool IsBstUtil(struct Node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;  // 空树是二叉搜索树
    }

    // 当前节点的值必须大于最小值且小于最大值
    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    // 递归检查左子树和右子树  +1 和 -1 是为了允许值相等的情况
    return IsBstUtil(root->left, minValue, root->data - 1) &&//maxValue 更新为当前节点的值减 1，表示左子树中的所有节点的值必须严格小于当前节点的值
           IsBstUtil(root->right, root->data + 1, maxValue);//minValue 更新为当前节点的值加 1，表示右子树中的所有节点的值必须严格大于当前节点的值
}

// 判断给定的树是否是二叉搜索树
bool IsBinarySearchTree(struct Node* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // 示例：构建一个二叉搜索树
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
