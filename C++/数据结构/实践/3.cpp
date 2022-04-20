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

void ListDel_C(LinkList &L, int Locate)
{
    if (!L->Next)
    {
        return;
    }
    if (Locate < 1)
    {
        return;
    }
    LinkList p = L;
    for (int i = 1; i < Locate; i ++)
    {
        p = p->Next;
        if (!p->Next)
        {
            return;
        }
    }
    LinkList q = p->Next;
    p->Next = p->Next->Next;
    free(q);
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

int main()
{
    LinkList L;
    ListInit(L);
    int m, n;
    while (~scanf("%d", &n))
    {
        ListIns_R(L, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i ++)
    {
        ListDel_C(L, m);
    }
    ListPrint(L);
    return 0;
}
