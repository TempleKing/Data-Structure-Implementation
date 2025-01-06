#include <stdio.h>
#include <stdlib.h>

// Define the structure for the tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to find a node with specific data in the tree
struct Node* Find(struct Node* root, int data) {
    if (root == NULL) return NULL;
    else if (root->data == data) return root;
    else if (root->data < data) return Find(root->right, data);
    else return Find(root->left, data);
}

// Function to find the node with the minimum value in a BST
struct Node* FindMin(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find the inorder successor in a BST

//current 有右子树，那么它的中序后继节点就是其右子树中的 最小节点
//current 没有右子树，那么中序后继节点就是 最近的一个祖先节点
struct Node* Getsuccessor(struct Node* root, int data) {
    // Search the node - O(h)
    struct Node* current = Find(root, data);
    if (current == NULL) return NULL;
    if (current->right != NULL) {  // Case 1: Node has a right subtree
        return FindMin(current->right); // O(h)
    }
    else {   // Case 2: No right subtree - O(h)
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while (ancestor != current) {//如果当前节点 current 的值小于某个祖先节点的值，那么这个祖先节点可能是中序后继节点，因为它是当前节点的最近的较大节点
            if (current->data < ancestor->data) {
                successor = ancestor; // So far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

// Function to visit nodes in inorder (in-order traversal)
void Inorder(struct Node* root) {
    if (root == NULL) return;

    Inorder(root->left);       // Visit left subtree
    printf("%d ", root->data); // Print data
    Inorder(root->right);      // Visit right subtree
}

// Function to insert a node into a Binary Search Tree
struct Node* Insert(struct Node* root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int main() {
    // Create an example tree
    //           5
    //         /   \
    //        3     10
    //       / \      \
    //      1   4     11

    struct Node* root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);

    // Print nodes in inorder
    printf("Inorder Traversal: ");
    Inorder(root);
    printf("\n");

    // Find inorder successor of a given node
    struct Node* successor = Getsuccessor(root, 4);
    if (successor == NULL)
        printf("No successor found\n");
    else
        printf("Successor is %d\n", successor->data);

    return 0;
}
