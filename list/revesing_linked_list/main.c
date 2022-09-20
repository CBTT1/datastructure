#include <stdio.h>


typedef struct node
{
    int Address;
    int Data;
    int Next;
}list;

void Exchange(list a[],int i,int j)
{
    list temp;
    temp.Address = a[i].Address;
    temp.Data = a[i].Data;
    temp.Next = a[i].Next;
    a[i].Address = a[j].Address;
    a[i].Data = a[j].Data;
    a[i].Next = a[j].Next;
    a[j].Address = temp.Address;
    a[j].Data = temp.Data;
    a[j].Next = temp.Next;

}

void Sort(list a[],int N,int StartAddress)
{
    for(int i = 0;i<N;i++)
    {
        if(a[i].Address == StartAddress)
        {
            Exchange(a,i,0);
            break;
        }
    }
    for(int i = 0;i<N;i++)
    {
        for(int j = i+1;j<N;j++)
        {
            if(a[i].Next == a[j].Address)
            {
                Exchange(a,j,i+1);
                break;
            }
        }
    }
}

void Reverse(list a[],int N,int K)
{
    int cnt = N/K;
    if(cnt)
    {
        for(int i = 1;i<=cnt;i++)
        {
            for(int j = 1;j<=K;j++)
            {
                if(2*j<=K)
                {
                    Exchange(a,(i-1)*K+j-1,i*K-j);
                }
            }
        }
    }
}

int main()
{
    int startAddress,N,K;
    scanf("%5d %d %d",&startAddress,&N,&K);
    list a[N];
    for(int i=0;i<N;i++)
    {
        scanf("%5d %d %d",&a[i].Address,&a[i].Data,&a[i].Next);
    }
    Sort(a,N,startAddress);
    int End;
    for(int i=0;i<N;i++)
    {
        if(a[i].Next == -1)
        {
            End = i+1;
        }
    }
    Reverse(a,End,K);
    for(int i=0;i<End;i++)
    {
        a[i].Next = a[i+1].Address;
        if(i == End-1)
        {
            a[i].Next = -1;
        }
    }
    for(int i=0;i<End;i++)
    {
        if(a[i].Next!=-1)
            printf("%05d %d %05d\n",a[i].Address,a[i].Data,a[i].Next);
        else
            printf("%05d %d %d\n",a[i].Address,a[i].Data,a[i].Next);
    }
    return 0;
}
