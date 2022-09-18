#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
	ElemType *list;
	int size;
	int maxsize;
}SqList;

void init_sq(SqList &L);
int main()
{
	SqList List1;
	init_sq(&List1);
	return 0;
}

void init_sq(SqList &L)
{
	L.list = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	L.size = 0;
	L.maxsize = MAXSIZE;
}
