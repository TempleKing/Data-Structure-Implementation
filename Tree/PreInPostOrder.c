#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Preorder 遍历（先序遍历）
void Preorder(struct Node *root) {
    if (root == NULL) return;

    printf("%c ", root->data); // 打印节点数据
    Preorder(root->left);      // 递归遍历左子树
    Preorder(root->right);     // 递归遍历右子树
}

// Inorder 遍历（中序遍历）
void Inorder(struct Node *root) {
    if (root == NULL) return;

    Inorder(root->left);       // 递归遍历左子树
    printf("%c ", root->data); // 打印节点数据
    Inorder(root->right);      // 递归遍历右子树
}

// Postorder 遍历（后序遍历）
void Postorder(struct Node *root) {
    if (root == NULL) return;

    Postorder(root->left);     // 递归遍历左子树
    Postorder(root->right);    // 递归遍历右子树
    printf("%c ", root->data); // 打印节点数据
}


// 插入节点到二叉搜索树中
struct Node* Insert(struct Node *root, char data){
    if(root == NULL){
        root = (struct Node*)malloc(sizeof(struct Node));
        root -> data = data;
        root -> left = root -> right = NULL;
    }else if(data <= root -> data){
        root -> left = Insert(root -> left, data);
    }else{
        root -> right = Insert(root -> right, data);
    }
    return root;
};


int main() {
    	/*Code To Test the logic
	  Creating an example tree
                M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
    // 创建一个二叉树，并插入节点
    struct Node* root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');

    // 打印先序遍历结果
    printf("Preorder: ");
    Preorder(root);
    printf("\n");

    // 打印中序遍历结果
    printf("Inorder: ");
    Inorder(root);
    printf("\n");

    // 打印后序遍历结果
    printf("Postorder: ");
    Postorder(root);
    printf("\n");

    return 0;
}
