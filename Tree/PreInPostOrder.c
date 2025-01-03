#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Preorder ���������������
void Preorder(struct Node *root) {
    if (root == NULL) return;

    printf("%c ", root->data); // ��ӡ�ڵ�����
    Preorder(root->left);      // �ݹ����������
    Preorder(root->right);     // �ݹ����������
}

// Inorder ���������������
void Inorder(struct Node *root) {
    if (root == NULL) return;

    Inorder(root->left);       // �ݹ����������
    printf("%c ", root->data); // ��ӡ�ڵ�����
    Inorder(root->right);      // �ݹ����������
}

// Postorder ���������������
void Postorder(struct Node *root) {
    if (root == NULL) return;

    Postorder(root->left);     // �ݹ����������
    Postorder(root->right);    // �ݹ����������
    printf("%c ", root->data); // ��ӡ�ڵ�����
}


// ����ڵ㵽������������
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
    // ����һ����������������ڵ�
    struct Node* root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');

    // ��ӡ����������
    printf("Preorder: ");
    Preorder(root);
    printf("\n");

    // ��ӡ����������
    printf("Inorder: ");
    Inorder(root);
    printf("\n");

    // ��ӡ����������
    printf("Postorder: ");
    Postorder(root);
    printf("\n");

    return 0;
}
