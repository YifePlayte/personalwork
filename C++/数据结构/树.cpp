#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode
{
    int Data;
    BiTNode *LChild;
    BiTNode *RChild;
} BiTNode, *BiTree;

typedef struct QNode
{
    int Data;
    QNode *Next;
} QNode, *QueuePtr;

struct LinkQueue
{
    QueuePtr front;
    QueuePtr rear;
};

bool QInit(LinkQueue &q)
{
    q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
    q.front->Next = NULL;
    return true;
}

bool QEmpty(LinkQueue q)
{
    return (q.front == q.rear);
}

int QLength(LinkQueue q)
{
    int n = 0;
    QueuePtr p = q.front;
    while (p->Next)
    {
        n++;
        p = p->Next;
    }
    return n;
}

bool QHead(LinkQueue q, int &n)
{
    if (QEmpty(q))
        return false;
    n = q.front->Next->Data;
    return true;
}

bool QEn(LinkQueue &q, int n)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        return false;
    p->Data = n;
    p->Next = NULL;
    q.rear->Next = p;
    q.rear = p;
    return true;
}

bool QDe(LinkQueue &q, int &n)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front;
    q.front = q.front->Next;
    n = p->Data;
    free(p);
    return true;
}

bool QDe(LinkQueue &q)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front;
    q.front = q.front->Next;
    free(p);
    return true;
}

void QDestroy(LinkQueue &q)
{
    while (QDe(q))
    {
    }
    free(q.front);
    q.front = q.rear = NULL;
}

typedef struct SNode
{
    BiTree Data;
    SNode *Next;
} SNode, *Stack;

bool SInit(Stack &S)
{
    S = (Stack)malloc(sizeof(SNode));
    S->Next = NULL;
    return true;
}

bool SEmpty(Stack S)
{
    return (S->Next == NULL);
}

void SPush(Stack &S, BiTree n)
{
    Stack p = S->Next;
    S->Next = (Stack)malloc(sizeof(SNode));
    S->Next->Data = n;
    S->Next->Next = p;
}

BiTree STop(Stack S)
{
    return S->Next->Data;
}

bool SPop(Stack &S)
{
    if (SEmpty(S))
        return false;
    Stack p = S->Next;
    S->Next = p->Next;
    free(p);
    return true;
}

bool SPop(Stack &S, BiTree &n)
{
    if (SEmpty(S))
        return false;
    Stack p = S->Next;
    S->Next = p->Next;
    n = p->Data;
    free(p);
    return true;
}

BiTree BiTGoFarLeft(BiTree n, Stack &s)
{
    if (!n)
        return NULL;
    while (n->LChild)
    {
        SPush(s, n);
        n = n->LChild;
    }
    return n;
}

void BiTInorder_I(BiTree t, LinkQueue &q)
{
    Stack s;
    SInit(s);
    t = BiTGoFarLeft(t, s);
    while (t)
    {
        QEn(q, t->Data);
        if (t->RChild)
            t = BiTGoFarLeft(t->RChild, s);
        else if (!SEmpty(s))
            SPop(s, t);
        else
            t = NULL;
    }
}
