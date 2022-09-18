#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkedList,LNode;

int init_l(LinkedList *L)
{
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL; //单向链表中尾指针指向NULL
    return 1;
}

/****头插法创建单链表****/
void create_L(LinkedList *L,int n)
{
    LinkedList *p;
    init_l(L);
    for(int i=0;i<n;i++)
    {
        p = (LinkedList *)malloc(sizeof(LNode));
        p -> data = rand()%100 + 1;
        p ->next = L ->next;
        L ->next = p;
    }
}

/***尾插法创建单链表***/
void create_L_tail(LinkedList *L,int n)
{
    LinkedList *p,*s;
    init_l(L);
    s = L;
    for(int i=0;i<n;i++)
    {
        p = (LinkedList *)malloc(sizeof (LNode));
        p -> data = rand()%100 + 1;
        p -> next = NULL;
        s -> next = p;
        s = s->next;
    }
}

int insert_L(LinkedList *L,int i,ElemType e)
{
    LinkedList * p, *s;
    p = L;
    int j = 0;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i-1) return 0;
    s = (LinkedList *) malloc(sizeof(LNode));
    s -> data = e;
    s -> next = p-> next;
    p -> next = s;
    return 1;
}

/****删除第i个节点上的值并赋给e****/
int delete_L(LinkedList *L,int i ,ElemType *e)
{
    if(L->next == NULL) return 0;
    LinkedList *p,*q;
    p = L;
    for(int j = 1;j<i;j++)
    {
        p = p->next;
        if(p->next == NULL)
        {
            printf("删除位置不合法！");
            return 0;
        }
    }
    q = p->next;
    p -> next = q -> next;
    *e = q->data;
    free(q);
    return 1;
}

/****取得单链表第i个位置元素****/
int get_L(LinkedList *L,int i,ElemType *e)
{
    if(L -> next == NULL ) return 0;
    LinkedList *p;
    p = L;
    for(int j = 1;j<=i;j++)
    {
        p = p->next;
        if(p->next == NULL && j!=i)
        {
            printf("检索位置不合法!\n");
            return 0;
        }
    }
    *e = p->data;
    return 1;
}

int traverse_L(LinkedList *L)
{
    if(L ->next == NULL) return 0;
    LinkedList *p = L->next;
    while (p)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}
int main()
{
    time_t t;
    srand((unsigned ) time(&t));

    LinkedList List1;
    create_L_tail(&List1,11);
    ElemType a;
//    if(!get_L(&List1,5,&a))
//    {
//        printf("ERROR\n");
//    }
//    printf("a = %d\n",a);
//    if(!delete_L(&List1,5,&a))
//    {
//        printf("ERROR\n");
//    }
//    printf("a = %d\n",a);
    traverse_L(&List1);
    return 0;
}
