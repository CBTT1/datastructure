#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    struct PolyNode *link;
};

int Compare(int a , int b);
void Attach(int pCoef,int pExpon,Polynomial *pRear);

Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int c,e,N;

    scanf("%d",&N);
    P = (Polynomial) malloc(sizeof (struct PolyNode));
    P->link = NULL;
    Rear = P;

    while(N--)
    {
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof (struct PolyNode));
    front = rear;
    while(P1&&P2)
    {
        switch(Compare(P1->expon,P2->expon))
        {
            case 1:
                Attach(P1->coef,P1->expon,&rear);
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&rear);
                P2 = P2->link;
                break;
            case 0:
                sum = P1->coef + P2->coef;
                if(sum) Attach(sum,P1->expon,&rear);
                P1 = P1->link;
                P2 = P2->link;
                break;
        }
    }
    for(;P1;P1 = P1->link) Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2 = P2->link) Attach(P2->coef,P2->expon,&rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}

Polynomial PolyMult(Polynomial P1,Polynomial P2)
{
    Polynomial P,Rear,t1,t2,t;
    int c,e;

    if(!P1||!P2) return NULL;

    t1 = P1; t2 = P2;
    P =(Polynomial) malloc(sizeof (struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1)
    {
        t2 = P2;
        Rear = P;
        while(t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while(Rear->link && Rear->link->expon > e) //下一项的系数和待插入项的系数比较
                Rear = Rear->link;
            if(Rear->link && Rear ->link->expon == e)
            {
                if(Rear->link->coef + c)
                    Rear->link->coef += c;
                else // 系数相加之后为0，删除结点
                {
                    t = Rear->link;
                    Rear -> link = Rear -> link -> link;
                    free(t);
                }
            }
            else
            {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t -> coef = c;
                t -> expon = e;
                t -> link = Rear -> link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;P=P->link;
    free(t2);
    return P;
}

void PrintPoly(Polynomial P)
{
    int flag = 0; //调整格式

    if(!P)
    {
        printf("0 0\n");
        return;
    }

    while(P)
    {
        if(!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d",P->coef,P->expon);
        P = P->link;
    }
    printf("\n");
}



int main()
{
    Polynomial P1,P2;
    Polynomial PSum,PMult;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PSum = PolyMult(P1,P2);
    PrintPoly(PSum);
    PMult = PolyAdd(P1,P2);
    PrintPoly(PMult);
    return 0;
}

void Attach(int pCoef, int pExpon, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial) malloc(sizeof(struct PolyNode));
    P->coef = pCoef;
    P->expon = pExpon;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

int Compare(int a, int b)
{
    if(a>b) return 1;
    else if(a<b) return -1;
    else return 0;
}
