#include <stdio.h>

typedef struct SNode* Stack;
struct SNode
{
    int Data;
    int Top;
    int MaxSize;
};


void Judge(int a[],int N,int M)
{
    int cnt = 0;
    for(int i = 0;i<N;i++)
    {
        cnt++;
        if(cnt > M)
        {
            printf("NO\n");
            break;
        }
        int temp = *(a+i+1);
        if(temp > *(a+i))
        {
            cnt = 0;
        }
        int break_flag = 0;
        for(int j = i+1;j<N;j++)
        {
//            printf("%d ",*(a+i));
            if(temp<*(a+i) && temp < *(a+j) && *(a+i)>*(a+j))
            {
                printf("NO\n");
                break_flag = 1;
                break;
            }
        }
        if(break_flag)
            break;
        if(i == N - 1)
        {
            printf("YES\n");
        }
    }
}


int main()
{
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    int a[K][N];
    for(int i = 0;i<K;i++)
    {
        for(int j = 0;j<N;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0;i<K;i++)
        Judge(&a[i][0],N,M);

    return 0;
}
