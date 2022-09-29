#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node
{ /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode
{
    Position Front,Rear;  /* 队列的头、尾指针 */
    int MaxSize;
};
typedef struct QNode *Queue;

/***创建带有头节点的队列***/
Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Front = Q->Rear = (PtrToNode) malloc(sizeof(PtrToNode));;
    Q->Front->Next = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

int IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}

ElementType DeleteQ( Queue Q )
{
    Position FrontCell;
    ElementType FrontElem;

    if  ( IsEmpty(Q) ) {
        printf("队列空");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}

int QueueLength(Queue Q)
{
    int i = 0;
    PtrToNode p;
    p = Q->Front;
    while(p!= Q->Rear)
    {
        i++;
        p = p->Next;
    }
    return i;

}
int IsFull(Queue Q)
{
    return (QueueLength(Q)>=Q->MaxSize);
}
int AddQ(Queue Q, ElementType item)
{
    if(IsFull(Q))
    {
        printf("队列满");
        return ERROR;
    }
    struct Node *Temp = (PtrToNode) malloc(sizeof (struct Node));
    Temp->Data = item;
    Temp->Next = NULL;
    Q->Rear->Next = Temp;
    Q->Rear = Temp;
    return OK;
}

int ReverseQueue(Queue Q)
{
    PtrToNode p;
    p = Q->Front->Next;
    while(p)
    {
        printf("%d ",p->Data);
        p = p->Next;
    }
    printf("\n");
    return OK;
}


int main()
{
    printf("Hello, World!\n");
    return 0;
}
