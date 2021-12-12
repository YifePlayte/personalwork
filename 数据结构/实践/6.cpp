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

int ListFind(LinkList L, int n)
{
    LinkList p = L->Next;
    int loc = 1;
    while (p)
    {
        if (p->Data == n)
            return loc;
        else
        {
            loc++;
            p = p->Next;
        }
    }
    return 0;
}

void ListDelFromAB(LinkList &L, LinkList A, LinkList B)
{
    LinkList p = L, q;
    while (p->Next)
    {
        if (ListFind(A, p->Next->Data) > 0 && ListFind(B, p->Next->Data))
        {
            q = p->Next;
            p->Next = q->Next;
            free(q);
        }
        else
        {
            p = p->Next;
        }
    }
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
    while (~scanf("%d", &n))
    {
        ListIns_R(Lc, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    ListDelFromAB(La, Lb, Lc);
    ListPrint(La);
    return 0;
}
