#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 101  // Maximum size of the array that will store Queue

// Queue structure definition
typedef struct {
    int A[MAX_SIZE];//数组空间
    int front, rear;
} Queue;

void InitializeQueue(Queue* q){
    q -> front = -1;
    q -> rear = -1;
}

bool IsEmpty(Queue* q){
    return(q -> front == -1 && q -> rear == -1);
}


bool IsFull(Queue* q){
    return((q -> rear + 1) % MAX_SIZE == q -> front);
}

void Enqueue(Queue* q, int x){
    printf("Enqueuing %d\n", x);
    if(IsFull(q)){
        printf("Error: Queue is Full\n");
        return;
    }
    if(IsEmpty(q)){
        q -> front = q -> rear = 0;
    }
    else{
        q -> rear = (q -> rear + 1) % MAX_SIZE;
    }
    q -> A[q -> rear] = x;
}

void Dequeue(Queue* q){
    printf("Dequeuing\n");
    if(IsEmpty(q)){
        printf("Error: Queue is Empty\n");
        return;
    }
    else if(q -> front == q -> rear)//只有一个元素的情况
    {
        q -> front = q -> rear = -1;
    }
    else{
        q -> front = (q -> front + 1) % MAX_SIZE;
    }
}

int front(Queue* q){
    if(IsEmpty(q)){
        printf("Error: Queue is Empty\n");
        return;
    }
    return(q -> A[q -> front]);//返回当前队列的第一个元素
}

void Print(Queue* q)
{
    if(IsEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    int count = (q -> rear + MAX_SIZE - q -> front) % MAX_SIZE + 1;//+MAX计算相对距离避免出现负数，%MAX环形结构映射位置，+1补偿索引从0开始
    printf("Queue: ");
    for(int i = 0; i < count; i++){
        int index = (q -> front + i) % MAX_SIZE;
        printf("%d ", q -> A[index]);
    }
    printf("\n");
}

int main(){
    Queue q;
    InitializeQueue(&q);

    Enqueue(&q, 2); Print(&q);
    Enqueue(&q, 4); Print(&q);
    Enqueue(&q, 6); Print(&q);
    Dequeue(&q); Print(&q);
    Enqueue(&q, 8); Print(&q);

    return 0;
}
