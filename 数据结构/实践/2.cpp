#include<bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int Data;
    LNode *Next;
} LNode, *LinkList;

void ListInit(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;
    return;
}

void ListIns_R(LinkList &L, int n)
{
    LinkList p = L;
    while (p->Next)
    {
        p = p->Next;
    }
    p->Next = (LinkList)malloc(sizeof(LNode));
    p->Next->Data = n;
    p->Next->Next = NULL;
}

void ListPrint(LinkList L)
{
    LinkList p = L->Next;
    if (p)
    {
        printf("%d", p->Data);
        p = p->Next;
        while (p)
        {
            printf(" %d", p->Data);
            p = p->Next;
        }
        printf("\n");
    }
    else
        printf("Empty!\n");
}

int ListLength(LinkList L)
{
    LinkList p = L;
    int Length = 0;
    while (p->Next)
    {
        p = p->Next;
        Length ++;
    }
    return Length;
}

void ListCombine(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList pa = La->Next, pb = Lb->Next;
    while (pa != NULL && pb != NULL)
    {
        if (pa->Data < pb->Data)
        {
            ListIns_R(Lc, pa->Data);
            pa = pa->Next;
        }
        else
        {
            ListIns_R(Lc, pb->Data);
            pb = pb->Next;
        }
    }
    while (pa != NULL)
    {
        ListIns_R(Lc, pa->Data);
        pa = pa->Next;
    }
    while (pb != NULL)
    {
        ListIns_R(Lc, pb->Data);
        pb = pb->Next;
    }
    return;
}

int main()
{
    LinkList La, Lb, Lc;
    int n;
    ListInit(La);
    ListInit(Lb);
    ListInit(Lc);
    while (~scanf("%d", &n))
    {
        ListIns_R(La, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    while (~scanf("%d", &n))
    {
        ListIns_R(Lb, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    ListCombine(La, Lb, Lc);
    ListPrint(Lc);
    return 0;
}
