#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 31 //树从1开始 0留作NULL

int CNT = 0;//输出格式标志位

struct TreeNode
{
    int left,right;
}Tree[MAXSIZE];

int ReadTree()
{
    int N,t,j=1;
    scanf("%d",&N);
    if(!N) return -1;
    int tmp[N]; //存储结点push的顺序

    int stack[N],top = -1; //建栈
    for(int i = 0; i < N; i++) stack[i] = 0;

    char *Operate[2 * N];
    Operate[0] = (char*) malloc(sizeof(char)*5);

    scanf("\n%s",Operate[0]);
    scanf("%d",&tmp[0]);
    stack[++top] = tmp[0];
    for(int i = 1;i<=N;i++)
    {
        Tree[i].left = Tree[i].right = 0;
    }
    for(int i = 1;i< 2 * N - 1; i++)  //一个结点要一次pop一次push
    {
        Operate[i] = (char *)malloc(sizeof(char)*5);
        scanf("\n%s",Operate[i]);
        scanf("%d",&tmp[j]);
        if(strcmp(Operate[i],"Push") == 0)
        {
            stack[++top] = tmp[j];
            if(strcmp(Operate[i-1],"Push") == 0)
            {
                Tree[tmp[j-1]].left = tmp[j];
//                printf("Tree[%d].left = %d\n",tmp[j-1],tmp[j]);
            }
            else if(strcmp(Operate[i-1],"Pop") == 0)
            {
                Tree[t].right = tmp[j];
//                printf("Tree[%d].right = %d\n",t,tmp[j]);
            }
            j++;
        }
        else if(strcmp(Operate[i],"Pop") == 0)
        {
            t = stack[top];
            stack[top] = 0;
            top--;
//            printf("Pop %d, Stack Top %d\n",t,top);
        }
    }
    return tmp[0];
}

void PostOrderTraversal(int T)
{
    if(T)
    {
        PostOrderTraversal(Tree[T].left);
        PostOrderTraversal(Tree[T].right);
        if(!CNT)
        {
            printf("%d",T);
            CNT = 1;
        }
        else
        {
            printf(" %d",T);
        }
    }
}
int main()
{
    int T;
    T = ReadTree();
    PostOrderTraversal(T);
    return 0;
}
