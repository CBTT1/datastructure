#include <stdio.h>
#include <stdlib.h>



//#define LevelOrder
#ifdef  LevelOrder 1

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef struct QNode *Queue;

typedef struct TNode *BinTree;

typedef BinTree ElementTypeQueue; //队列的元素为二叉树

typedef int ElementType; //二叉树的数据类型为int

struct Node
{ /* 队列中的结点 */
    ElementTypeQueue Data;
    PtrToNode Next;
};

struct QNode
{
    Position Front,Rear;  /* 队列的头、尾指针 */
    int MaxSize;
};

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

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

ElementTypeQueue DeleteQ( Queue Q )
{
    Position FrontCell;
    ElementTypeQueue FrontElem;

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
int AddQ(Queue Q, ElementTypeQueue item)
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

//int ReverseQueue(Queue Q)
//{
//    PtrToNode p;
//    p = Q->Front->Next;
//    while(p)
//    {
//        printf("%d ",p->Data);
//        p = p->Next;
//    }
//    printf("\n");
//    return OK;
//}

void LevelOrderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if(!BT) return;
    Q = CreateQueue(20);
    AddQ(Q ,BT);
    while(!IsEmpty(Q))
    {
        T = DeleteQ(Q);
        printf("%d ",T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}

#else

typedef int ElementType;

typedef struct  TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


/*单向链表存储实现堆栈只能在链表头上实现 插在尾上可以插入但无法删除*/
typedef BinTree ElementTypeStack;
typedef struct SNode *Stack;
struct SNode
{
    ElementTypeStack Data;
    Stack Next;
};

Stack CreateStack()
{
    Stack S;
    S = (Stack) malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

/**空则返回1**/
int IsEmpty(Stack S)
{
    return (S->Next == NULL);
}

void Push(Stack S,ElementTypeStack item)
{
    Stack TmpCell;
    TmpCell=(Stack) malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementTypeStack GetTop(Stack S)
{
    Stack TmpCell;
    ElementTypeStack TopElem;
    if(IsEmpty(S))
    {
        printf("堆栈空");
        return -1;
    }
    else
    {
        TmpCell = S->Next;
        TopElem = TmpCell->Data;
        return TopElem;
    }
}

ElementTypeStack Pop(Stack S)
{
    Stack TmpCell;
    ElementTypeStack TopElem;
    if(IsEmpty(S))
    {
        printf("堆栈空");
        return -1;
    }
    else
    {
        TmpCell = S->Next;
        TopElem = TmpCell->Data;
        S->Next = TmpCell->Next;
        free(TmpCell);
        return TopElem;
    }
}

/***先序非递归遍历***/
void PreorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreateStack();
    T = BT;
    while(T || !IsEmpty(S))
    {
        while(T)
        {
            Push(S,T);
            //if(!T->Left && !T->Right) //打印叶子结点
            printf("%d \n",T->Data);
            T = T->Left;
        }
        if(!IsEmpty(S))
        {
            T = Pop(S);
            T = T->Right;
        }
    }
}

/***中序非递归遍历***/
void InorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreateStack();
    T = BT;
    while(T || !IsEmpty(S))
    {
        while(T)
        {
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S))
        {
            T = Pop(S);
            printf("%d \n",T->Data);
            T = T->Right;
        }
    }
}

/***后序非递归遍历***/
void PostOrderTraversal(BinTree BT)
{
    BinTree T=BT;
    BinTree Exist=NULL;
    Stack S=CreateStack(); //初始化堆
    while(T||!IsEmpty(S)){
        while(T && T->Left!=Exist && T->Right!=Exist){ //是否遍历完，左孩子或右孩子是否已入栈
            Push(S,T); //从(子)树根向左将结点入栈
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=GetTop(S); //获取栈顶元素
            if(T->Right && T->Right!=Exist){ //右孩子存在且未入过栈
                T=T->Right; //如果左边最后的结点有右子树,继续上述入栈操作
            }else{
                T=Pop(S); //没有右子树了，就出栈
                printf("%5d",T->Data); //读根
                Exist=T; //存放已读根的左孩子
                T=GetTop(S); //获取栈顶元素，即返回已读根的父结点
            }
        }
    }
}

/**后序遍历求二叉树高度**/
int PostOrderGetHeight(BinTree BT)
{
    int HL,HR,HMax;
    if(BT)
    {
        HL = PostOrderGetHeight(BT->Left);//分别求左右子树的最大高度
        HR = PostOrderGetHeight(BT->Right);
        HMax = (HL>HR)?HL:HR;
        return (HMax + 1);//返回树的深度
    }
    else return 0;//空树深度为0
}
#endif



int main()
{
//    Queue TestQ = CreateQueue(20);
//    int a[3] = {20,1,5};
//    for(int i = 0;i < 3;i++)
//    {
//        AddQ(TestQ,a[i]);
//        printf("%d\n",*(a+i));
//    }
//    ReverseQueue(TestQ);

    return 0;
}
