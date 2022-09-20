#include <stdio.h>
#include <stdlib.h>

typedef struct FullNode *FNode;

struct FullNode
{
    int Address;
    int Data;
    int Next;
    FNode Link;
};

FNode Reverse(int AddrStart, int N, int K,FNode* L);
void Attach(int addr,int data,int next,FNode *Rear);
FNode GetInform(int AddrStart, int N);

int main()
{
    int addrStart,N,K;
    scanf("%5d %d %d", &addrStart, &N, &K);
    if(K > N) return NULL; //输入不符合规范
    FNode listIn,listOut;
    listIn = GetInform(addrStart,N);
    listOut = Reverse();
    PutInform();
    return 0;
}

void Attach(int addr, int data, int next, FNode *Rear)
{
    FNode P;
    P = (FNode) malloc(sizeof (struct FullNode));
    P->Address = addr;
    P->Data = data;
    P->Next = next;
    P->Link = NULL;
    (*Rear)->Link = P;
    *Rear = P;
}

FNode Sequence(int AddrStart, int N , FNode* L)
{
    FNode P;
    P = (FNode) malloc(sizeof(FullNode));
    while(N-- && (*L)->Address != AddrStart)
    {
        (*L) = (*L)->Link;
        if((*L)->Address == AddrStart)
        {

        }
    }
    int Cnt = N;
    for(N;N>0;N--)
    {
        if((*L)->Address == AddrStart)
    }
}
FNode Reverse(int AddrStart, int N, int K,FNode* L)
{
    FNode P;
    P = (FNode) malloc(sizeof(struct FullNode));
    Find(addr);
    while(N-- && (*L)->Address != AddrStart)
    {
        (*L) = (*L)->Link;
    }
}

FNode GetInform(int AddrStart, int N)
{
    FNode L, Rear, t;
    int addr, data, next;
    L = (FNode) malloc(sizeof(struct FullNode));
    L->Link = NULL;
    Rear = L;
    while (N--)
    {
        scanf("%5d %d %d", &addr, &data, &next);
        Attach(addr, data, next, &Rear);
    }
    t = L;
    L = L->Next;
    free(t);
    Reverse(AddrStart, N, N, &L);//按要求排序
    return L;
}
