#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node
{
    ElementType Data;
    struct Node *Next;
};
struct QNode
{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;

ElementType DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    ElementType FrontElem;

    if(PtrQ->front == NULL)
    {
        printf("队列空");
        return -1;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ -> rear)
    {
        PtrQ->front = PtrQ->rear = NULL;
    }
    else
    {
        PtrQ->front = PtrQ->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

int AddQ(Queue PtrQ,ElementType item)
{
    struct Node *Temp = (struct Node*) malloc(sizeof (struct Node*));
    Temp->Data = item;
    PtrQ->rear->Next = Temp;
    PtrQ->rear = Temp;
    return 1;
}
int main()
{
    printf("Hello, World!\n");
    return 0;
}
