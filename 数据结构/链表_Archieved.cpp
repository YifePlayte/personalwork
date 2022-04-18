#include<bits/stdc++.h>
using namespace std;

class LinkList
{
    int Data = 0;
    LinkList *Next = NULL;
public:
    int Ins(int Num, int n);
    int GetElem(int Num);
};

int LinkList::Ins(int Num, int n)
{
    if (Next == NULL && Num != 1)
    {
        return -1;
    }
    LinkList *p = Next;
    for (int Count = 1; ((Count < Num - 1) && p != NULL); Count ++)
    {
        p = p->Next;
    }
    LinkList *q = p->Next;
    p->Next = (LinkList*)malloc(sizeof(LinkList));
    p = p->Next;
    p->Next = q;
    p->Data = n;
    return 0;
}

int LinkList::GetElem(int Num)
{
    LinkList *p = Next;
    for (int i = 1; i < Num; i ++)
    {
        p = p->Next;
        if (p == NULL)
        {
            printf("ERROR!\n");
            return 0;
        }
    }
    return p->Data;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Invalid Number!\n");
        return 0;
    }
    LinkList LL;
    for (int i = 1; i <= n; i ++)
    {
        int input;
        scanf("%d", &input);
        if (LL.Ins(i, input) == -1)
        {
            printf("ERROR!\n");
            return 0;
        }
    }
    while (~scanf("%d", &n))
    {
        printf("%d\n", LL.GetElem(n));
    }
    return 0;
}
