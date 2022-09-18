#include <stdio.h>

#define MAXSIZE 50

typedef int ElementType;
typedef struct QNode *Queue;
struct QNode
{
    ElementType Data[MAXSIZE];
    int rear;
    int front;
};

void AddQ(Queue PtrQ , ElementType item)
{
    if((PtrQ -> rear+1)%MAXSIZE == PtrQ->front)
    {
        printf("队列满");
        return ;
    }
    PtrQ->rear = (PtrQ->rear+1)%MAXSIZE;
    PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ -> front == PtrQ->rear)
    {
        printf("队列空");
        return -1;
    }
    else
    {
        PtrQ->front = (PtrQ->front+1)%MAXSIZE;
        return PtrQ->Data[PtrQ->front];
    }
}
int main()
{
    printf("Hello, World!\n");
    return 0;
}
