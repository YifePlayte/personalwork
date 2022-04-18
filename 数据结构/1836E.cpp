#include <bits/stdc++.h>
using namespace std;

typedef struct QNode
{
    char Data;
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

bool QHead(LinkQueue q, char &n)
{
    if (QEmpty(q))
        return false;
    n = q.front->Next->Data;
    return true;
}

bool QEn(LinkQueue &q, char n)
{
    // q.rear->Next = (QueuePtr)malloc(sizeof(QNode));
    // q.rear = q.rear->Next;
    // q.rear->Data = n;
    // q.rear->Next = NULL;
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        return false;
    p->Data = n;
    p->Next = NULL;
    q.rear->Next = p;
    q.rear = p;
    return true;
}

bool QDe(LinkQueue &q, char &n)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front;
    q.front = q.front->Next;
    n = q.front->Data;
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

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    char n;
    LinkQueue q;
    QInit(q);
    while (cin >> n)
    {
        QEn(q, n);
    }
    while (!QEmpty(q))
    {
        QDe(q, n);
        printf("%c", n);
    }
    return 0;
}