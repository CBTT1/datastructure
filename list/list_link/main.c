#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

typedef struct LNode *List;
struct LNode
{
    ElementType Data;
    List Next;
};

//struct LNode L;
//List PtrL;

/***创建新表***/
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Next = NULL;
    return PtrL;
}


List Find(ElementType X,List PtrL)
{
    List p = PtrL;
    while (p!=NULL&&p->Data != X)
        p = p->Next;
    return p; //找到了正常返回，没找到返回NULL
}

/**按序号查找***/
List FindKth(int K,List PtrL)
{
    List p = PtrL;
    int i = 1;
    while (p!=NULL && i<K)
    {
        p = p->Next;
        i++;
    }
    if(i == K) return p;
    else return NULL;
}

/*
 * Usage: PtrL = Insert()
 * O(n)
 * */
List Insert(ElementType X,int i,List PtrL)
{
    List p,s;
    if(i == 1)
    {
        s =(List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s; //插在头上，链表的头指针发生变化
    }

    p = FindKth(i-1,PtrL);
    if(p == NULL)
    {
        printf("参数i错");
        return NULL;
    }
    else
    {
        s =(List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

/**O(n)**/
List Delete(int i,List PtrL)
{
    List p,s;
    if(i == 1)
    {
        s = PtrL;
        if(PtrL!=NULL) p = PtrL -> Next;
        else return NULL;
        free (s);
        return p;
    }

    p = FindKth(i-1,PtrL);
    if(p == NULL)
    {
        printf("第%d个结点不存在",i-1);
        return NULL;
    }
    else if(p->Next == NULL)
    {
        printf("第%d个结点不存在",i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
//    s->Next = NULL;
        free(s);
        return PtrL;
    }
}

/***O(n)***/
int Length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while(p) //!=NULL
    {
        p = p->Next;
        j++;
    }
    return j;
}

int main()
{
    printf("Hello, World!\n");
    return 0;
}
