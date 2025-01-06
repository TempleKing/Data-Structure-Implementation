#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to find minimum in a tree.
struct Node* FindMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from tree.
struct Node* Delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    // Found the node to be deleted
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            struct Node* temp = FindMin(root->right);// 找到右子树的最小节点
            root->data = temp->data;// 用最小节点的值替换当前节点的值
            root->right = Delete(root->right, temp->data);//temp 现在就是右子树中的最小节点。由于已经将 root 的值替换成了 temp->data，所以接下来要删除的是 temp 节点
        }
    }
    return root;
}

// Function to visit nodes in Inorder
void Inorder(struct Node* root) {
    if (root == NULL) return;

    Inorder(root->left);         // Visit left subtree
    printf("%d ", root->data);   // Print data
    Inorder(root->right);        // Visit right subtree
}

// Function to insert a node into a Binary Search Tree
struct Node* Insert(struct Node* root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for new node
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}


int main() {
    // Code to test the logic
    // Creating an example tree:
    //               5
    //             /   \
    //            3     10
    //           / \      \
    //          1   4     11

    struct Node* root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);

    // Deleting node with value 5, change this value to test other cases
    root = Delete(root, 3);

    // Print nodes in Inorder
    printf("Inorder: ");
    Inorder(root);
    printf("\n");

    return 0;
}
