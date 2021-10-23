#include<bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int Data;
    LNode *Next;
} LNode, *LinkList;

void ListIns_L(LinkList &L, int n)
{
    LinkList p = L->Next;
    L->Next = (LinkList)malloc(sizeof(LNode));
    L->Next->Data = n;
    L->Next->Next = p;
}

bool ListDel_L(LinkList &L)
{
    if (!L->Next)
        return false;
    LinkList p = L;
    L = L->Next;
    free(p);
}

void ListInit(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;
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

bool ListSearch(LinkList L, int Locate, int &n)
{
    if (!L->Next || Locate < 1)
        return false;
    LinkList p = L;
    for (int i = 1; i <= Locate; i ++)
    {
        p = p->Next;
        if (!p)
            return false;
    }
    n = p->Data;
    return true;
}

bool ListEmpty(LinkList L)
{
    return (L->Next == NULL);
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    int n;
    LinkList l;
    ListInit(l);
    while(~scanf("%d", &n))
    {
        ListIns_L(l, n);
    }
    printf("%d\n", ListLength(l));
    while(!ListEmpty(l))
    {
        ListSearch(l, 1, n);
        printf("%d", n);
        ListDel_L(l);
    }
    return 0;
}
