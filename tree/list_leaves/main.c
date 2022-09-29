#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    Tree Left;
    Tree Right;
    int Depth;
}T[MaxTree];
int numNode = 0;

Tree BuildTree(struct TreeNode T[])
{
    int Root = Null;
    scanf("%d",&numNode);
    if(numNode)
    {
        char cl,cr;
        int check[numNode];
        int i;
        for(i = 0;i<numNode;i++) check[i] = 0;
        for(i = 0;i<numNode;i++)
        {
            scanf("\n%c %c",&cl,&cr);
            if(cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = Null;
            }

            if(cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = Null;
            }
        }
        for(i = 0;i<numNode;i++)
            if(!check[i])
                break;
        Root = i;
    }
    return Root;
}

int DepthCount(struct TreeNode T[],int NumNode,int Root)
{
    int DepthMax = -1;
    for(int i = 0;i<NumNode;i++)
    {
        int temp = i;
        int cntDepth = 0;
        while(temp != Root)
        {
            for(int j = 0;i<NumNode;j++)
            {
              if(T[j].Left == temp || T[j].Right == temp)
              {
                  temp = j;
                  cntDepth++;
                  break;
              }
            }
        }
        T[i].Depth = cntDepth;
        if(cntDepth > DepthMax) DepthMax = cntDepth;
    }
    return DepthMax;
}

void PrintLeaves(struct TreeNode T[],int NumNode,int Depthmax)
{
    int flag = 0;
    int checkPrint[NumNode];

    for (int i = 0; i < NumNode; i++)
        if (T[i].Right!= Null || T[i].Left != Null)
            checkPrint[i] = 1; //标记非叶子结点
        else
            checkPrint[i] = 0;

        for(int j =0;j<=Depthmax;j++)
        {
            for(int i=0;i<NumNode;i++)
            {
                if(!checkPrint[i] && j == T[i].Depth)
                {
                    if(!flag) //输出格式
                    {
                        printf("%d",i);
                        flag = 1;
                    }
                    else
                    {
                        printf(" %d",i);
                    }
                }
            }
        }
}

int main()
{
    Tree R;
    R = BuildTree(T);

    int queue[10] = {0},rear = -1,front=-1;
    int flag = 0;
    struct TreeNode p;
    queue[++rear] = R;
    while(front!=rear)
    {
        p = T[queue[++front]];
        if(p.Left != -1) queue[++rear] = p.Left;
        if(p.Right != -1) queue[++rear] = p.Right;
        if(p.Left == Null && p.Right == Null)
        {
            if(flag)
            {
                printf(" %d",queue[front]);
            }
            else
            {
                printf("%d",queue[front]);
                flag = 1;
            }
        }
    }
    return 0;
}
