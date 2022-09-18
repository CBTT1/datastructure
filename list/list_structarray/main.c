#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct infStudent
{
    char name[15];
    int  number;
    char address[20];
}infStu;

typedef infStu ElementType;

typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;
};


/***创建新表***/
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

int Find(ElementType X,List PtrL) /**查找平均次数(n+1)/2**/
{
    int i = 0;
    while(i <= PtrL->Last && PtrL->Data[i].address != X)
        i++;
    if(i>PtrL->Last) return -1; //没有找到这个值，返回-1
    else return i;//找到值了，返回该值存储位置
}

void Insert(ElementType X,int i,List PtrL)
{
    int j;
    if(PtrL->Last == MAXSIZE - 1)
    {
        printf("表已满！");
        return ;
    }

    if(i<1 || i>PtrL->Last+2) //可以插在最后
    {
        printf("位置不合法！");
        return ;
    }
    /***平均移动n/2次，时间复杂度O(n)***/
    for(j = PtrL->Last;j>=i-1;j--)//数组的i-1个就是第i个元素
    {
        PtrL ->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = X;
    PtrL->Last ++;
    return;
}

void Delete(int i,List PtrL)
{
    int j;
    if(i<1 || i>PtrL->Last+1)
    {
        printf("不存在第%d个元素",i);
        return ;
    }
    /***平均移动(n-1)/2次，时间复杂度O(n)***/
    for(j = i;j<PtrL->Last;j++)
    {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last --;
    return;
}


int main()
{
    struct LNode L;
    List p;
    p = MakeEmpty();

    return 0;
}
