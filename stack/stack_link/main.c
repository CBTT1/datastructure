#include <stdio.h>
#include <stdlib.h>

/*单向链表存储实现堆栈只能在链表头上实现 插在尾上可以插入但无法删除*/
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data;
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

void Push(ElementType item,Stack S)
{
    Stack TmpCell;
    TmpCell=(Stack) malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Pop(Stack S)
{
    Stack TmpCell;
    ElementType TopElem;
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

int main()
{
    printf("Hello, World!\n");
    return 0;
}
