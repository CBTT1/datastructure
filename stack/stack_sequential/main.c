/*数组实现堆栈*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 30
#define ERROR -1
typedef int ElementType;
typedef struct  SNode *Stack;
struct SNode
{
    ElementType *Data;
    int Top; //Top == -1表示堆栈为空 0为第一个元素
    int MaxSize;
};

Stack CreateStack( int MaxSize)
{
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->Data = (ElementType *) malloc(MaxSize*sizeof (ElementType));
    S->Top = -1;
    S->MaxSize = MAXSIZE;
    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize - 1);
}

bool IsEmpty(Stack S)
{
    return (S->Top == -1);
}


bool Push(Stack PtrS, ElementType item)
{
    if(PtrS->Top == MAXSIZE-1)
    {
        printf("堆栈满！");
        return false;
    }
    else
    {
        //PtrS->Data[++(PtrS->Top)] = item;
        PtrS->Top ++;
        PtrS->Data[PtrS->Top] = item;
        return true;
    }
}

ElementType Pop(Stack PtrS)
{
    if(PtrS->Top == -1)
    {
        printf("堆栈空！");
        return ERROR;
    }
    else
    {
        return (PtrS->Data[(PtrS->Top)]--);
    }
}

int main()
{

    return 0;
}
