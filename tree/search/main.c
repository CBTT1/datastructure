#include <stdio.h>

#define ElementType int
#define MAXSIZE 50

typedef struct LNode *List;
struct LNode{
    ElementType Element[MAXSIZE];
    int Length;
};

int SequentialSearch(List Tb1,ElementType K)
{
    int i;
    Tb1->Element[0] = K; //建立哨兵
    for(i = Tb1->Length;Tb1->Element[i] != K; i-- );
    return i;
}

int BinarySearch(List Tbl,ElementType K)
{
    int left,right,mid,NoFound=-1;

    left = 1;
    right = Tbl->Length;
    while(left <= right)
    {
        mid = (left+right)/2;
        if(K < Tbl-> Element[mid]) right = mid - 1;
        else if(K > Tbl->Element[mid]) left = mid + 1;
        else return mid;
    }
    return NotFound;
}

int main()
{
    printf("Hello, World!\n");
    return 0;
}
