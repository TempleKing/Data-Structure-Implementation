#include<stdio.h>
#include<stdlib.h>


//使用队结构进行广度优先遍历
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    struct Node* nodes[100];
    int front, rear;
};


//队列操作
void initQueue(struct Queue* q){
    q -> front = -1;
    q -> rear = -1;
}

int isQueueEmpty(struct Queue* q) {
    return q -> front == -1;
}


// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->nodes[++q->rear] = node;
}

// Function to dequeue (remove) an element from the queue
struct Node* dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node* node = q -> nodes[q -> front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}

//树操作
// Function to insert a Node in a Binary Search Tree
void LevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {//直到队列为空，表示树中所有节点都已经被访问过
        struct Node* current = dequeue(&q);//取前一节点赋值给current
        printf("%c ", current->data);

        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }
}


struct Node* Insert(struct Node* root, char data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}



// Main function to test the code
int main() {
    // Creating an example tree
    //                     M
    //                 /       \
    //               B          Q
    //             /   \         \
    //            A     C         Z

    struct Node* root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');

    // Print Nodes in Level Order
    LevelOrder(root);

    return 0;
}
