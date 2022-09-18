#include <stdio.h>

typedef int ElementType;
typedef struct GNOde *Glist;
struct GNOde
{
    int Tag; /*标志域：0表示结点是单元素，1表示结点是广义表*/
    union /*子表指针域Sublist与单元素数据域Data公用存储空间*/
    {
        ElementType Data;
        Glist SubList;
    }URegion;
    GList Next;
};

int main()
{
    printf("Hello, World!\n");
    return 0;
}
