#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

typedef int ElementType;
typedef int Position;
typedef struct QNode *Queue;
struct QNode
{
    ElementType * Data;
    Position Front,Rear;
    int MaxSize;
};

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue) malloc(sizeof (struct QNode));
    Q -> Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
    Q -> Front = Q -> Rear = 0;
    Q -> MaxSize = MaxSize;
    return Q;

}

int IsFull(Queue Q)
{
    return((Q->Rear+1)%Q->MaxSize == Q->Front);
}
int AddQ(Queue Q , ElementType item)
{
    if(IsFull(Q))
    {
        printf("Queue is full");
        return -1;
    }
    Q->Rear = (Q->Rear + 1) % MAXSIZE;
    Q->Data[Q->Rear] = item;
    return 1;
}

int IsEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}
ElementType DeleteQ(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("队列空");
        return -1;
    }
    else
    {
        Q->Front = (Q->Front + 1) % MAXSIZE;
        return Q->Data[Q->Front];
        return 1;
    }
}
int main()
{
    printf("Hello, World!\n");
    return 0;
}
