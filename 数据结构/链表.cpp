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

void ListIns_L(LinkList &L)
{
    LinkList p = L->Next;
    L->Next = (LinkList)malloc(sizeof(LNode));
    scanf("%d", &L->Next->Data);
    L->Next->Next = p;
}

void ListIns_R(LinkList &L)
{
    LinkList p = L;
    while (p->Next)
    {
        p = p->Next;
    }
    p->Next = (LinkList)malloc(sizeof(LNode));
    scanf("%d", &p->Next->Data);
    p->Next->Next = NULL;
}

void ListIns_C(LinkList &L, int Locate)
{
    if (Locate < 1)
    {
        printf("位置不合法，无法插入！\n");
        return;
    }
    LinkList p = L;
    for (int i = 1; i < Locate; i ++)
    {
        p = p->Next;
        if (!p)
        {
            printf("位置不合法，无法插入！\n");
            return;
        }
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    scanf("%d", &q->Data);
    q->Next = p->Next;
    p->Next = q;
}

void ListDel_L(LinkList &L)
{
    if (!L->Next)
    {
        printf("链表为空，无法删除！\n");
        return;
    }
    LinkList p = L->Next;
    L->Next = L->Next->Next;
    free(p);
}

void ListDel_R(LinkList &L)
{
    if (!L->Next)
    {
        printf("链表为空，无法删除！\n");
        return;
    }
    LinkList p = L;
    while (p->Next->Next)
    {
        p = p->Next;
    }
    free(p->Next);
    p->Next = NULL;
}

void ListDel_C(LinkList &L, int Locate)
{
    if (!L->Next)
    {
        printf("链表为空，无法删除！\n");
        return;
    }
    if (Locate < 1)
    {
        printf("位置不合法，无法删除！\n");
        return;
    }
    LinkList p = L;
    for (int i = 1; i < Locate; i ++)
    {
        p = p->Next;
        if (!p->Next)
        {
            printf("位置不合法，无法删除！\n");
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

void ListCreate_L(LinkList &L, int Length)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;
    LinkList p;
    for (int i = Length; i > 0; i --)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->Data);
        p->Next = L->Next;
        L->Next = p;
    }
}

void ListCreate_R(LinkList &L, int Length)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;
    LinkList p;
    LinkList R = L;
    for (int i = Length; i > 0; i --)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->Data);
        p->Next = NULL;
        R->Next = p;
        R = R->Next;
    }
}

void ListClear(LinkList &L)
{
    LinkList p;
    while (L->Next)
    {
        p = L->Next;
        L->Next = L->Next->Next;
        free(p);
    }
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

void ListSearch(LinkList L, int Locate)
{
    if (!L->Next)
    {
        printf("链表为空！\n");
        return;
    }
    if (Locate < 1)
    {
        printf("位置不合法！\n");
        return;
    }
    LinkList p = L;
    for (int i = 1; i <= Locate; i ++)
    {
        p = p->Next;
        if (!p)
        {
            printf("位置不合法！\n");
            return;
        }
    }
    printf("%d\n", p->Data);
}


int main()
{
    LinkList L;
    int n;
    printf("输入链表长度：\n");
    scanf("%d", &n);
    char Way;
    printf("选择构建链表时的插入方式（头插L，尾插R）：\n");
    getchar();
    scanf("%c", &Way);
    switch (Way)
    {
    case 'L':
        printf("请输入链表：\n");
        ListCreate_L(L, n);
        break;
    case 'R':
        printf("请输入链表：\n");
        ListCreate_R(L, n);
        break;
    default:
        printf("请输入正确的选项！\n");
        return -1;
    }
    printf("链表内容为：\n");
    ListPrint(L);
    printf("选择插入元素时的插入方式（头插L，尾插R，选插C）：\n");
    getchar();
    scanf("%c", &Way);
    switch (Way)
    {
    case 'L':
        printf("请输入要插入的数值：\n");
        ListIns_L(L);
        break;
    case 'R':
        printf("请输入要插入的数值：\n");
        ListIns_R(L);
        break;
    case 'C':
        printf("请输入要插入的位置：\n");
        scanf("%d", &n);
        printf("请输入要插入的数值：\n");
        ListIns_C(L, n);
        break;
    default:
        printf("请输入正确的选项！\n");
        return -1;
    }
    printf("链表内容为：\n");
    ListPrint(L);
    printf("选择删除元素的方式（头删L，尾删R，选删C）：\n");
    getchar();
    scanf("%c", &Way);
    switch (Way)
    {
    case 'L':
        ListDel_L(L);
        break;
    case 'R':
        ListDel_R(L);
        break;
    case 'C':
        printf("请输入要删除的位置：\n");
        scanf("%d", &n);
        ListDel_C(L, n);
        break;
    default:
        printf("请输入正确的选项！\n");
        return -1;
    }
    printf("链表内容为：\n");
    ListPrint(L);
    printf("请输入要查找的位置：\n");
    scanf("%d", &n);
    printf("位置%d的值为：\n", n);
    ListSearch(L, n);
    printf("链表长度为：%d\n", ListLength(L));
    printf("清空链表\n");
    ListClear(L);
    printf("链表内容为：\n");
    ListPrint(L);
    return 0;
}
