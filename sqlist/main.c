#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
        ElemType *list;
        int size;
        int maxsize;
}SqList;

void init_sq(SqList *L);
int againMalloc(SqList *L);

int empty_sq(SqList *L);
int length_sq(SqList *L);
int insert_sq(SqList *L,int i,ElemType e);
void traverse(SqList L);
int get(SqList L,int i,ElemType *e);
int main()
{
    int e = 0;
    int f = 100;
    SqList List1;
    init_sq(&List1);
    insert_sq(&List1,1,f);
    insert_sq(&List1,2,200);
    traverse(List1);
    return 0;
}

void init_sq(SqList *L)
{
    L->list = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L->size = 0;
    L->maxsize = MAXSIZE;
}

int againMalloc(SqList *L)
{
    ElemType *newbase = (ElemType *) realloc(L->list,L->maxsize*2*sizeof(ElemType));

    if(!newbase)
    {
        printf("存储空间分配失败");
        return -1;
    }
    L->list = newbase;
    L->maxsize = 2 * L->maxsize;
    return 1;
}

int empty_sq(SqList *L)
{
    if(!L->size)
        return 1;
    else
        return 0;
}

int length_sq(SqList *L)
{
    return L->size;
}

int insert_sq(SqList *L,int i,ElemType e)
{
    ElemType *p;
    int f;
    if(i<1 || i>L->size+1) return 0; //检查i值是否超出允许的范围
    if(L->size >= L->maxsize)
    {
        f = againMalloc(L);
        if(!f) return -1;
    }
    for(int j = L->size;j>=i;j--)
    {
        L->list[j] = L->list[j-1];
    }
    L->list[i-1] = e;
    ++L->size;
    return 1;
}

void traverse(SqList L)
{
    for(int i=0;i<L.size;i++)
    {
        printf("%d\n",L.list[i]);
    }
}

int get(SqList L,int i,ElemType *e)
{
    if(i<=0||i>L.size)
    {
        printf("位置不合法！");
        return 0;
    }
    *e = L.list[i-1];
    return 1;
}
