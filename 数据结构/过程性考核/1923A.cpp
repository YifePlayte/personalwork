#include<bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int Data;
    LNode *Next;
} LNode, *LList;

void LInit(LList &L)
{
    L->Next = NULL;
}

void LInput(LList &L, int n)
{
    int input;
    LList p = L;
    for(int i = 0; i < n; i ++)
    {
        p->Next = (LList)malloc(sizeof(LNode));
        scanf("%d", &p->Next->Data);
        p->Next->Next = NULL;
        p = p->Next;
    }
}

bool LDel_C(LList &L, int Locate)
{
    if (!L->Next)
    {
        return false;
    }
    if (Locate < 1)
    {
        return false;
    }
    LList p = L;
    for (int i = 1; i < Locate; i ++)
    {
        p = p->Next;
        if (!p->Next)
        {
            return false;
        }
    }
    LList q = p->Next;
    p->Next = p->Next->Next;
    free(q);
    return true;
}

void LPrint(LList L)
{
    LList p = L->Next;
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    return;
}

int main()
{
    LList l;
    int n;
    LInit(l);
    scanf("%d", &n);
    LInput(l, n);
    scanf("%d", &n);
    LDel_C(l, n);
    LPrint(l);
    return 0;
}
