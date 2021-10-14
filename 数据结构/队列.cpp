#include <bits/stdc++.h>
using namespace std;

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

void QInit(LinkQueue &q)
{
    q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
    q.front->Next = NULL;
}

bool QEmpty(LinkQueue q)
{
    if (q.front == q.rear)
        return true;
    return false;
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

void QEn(LinkQueue &q, int n)
{
    q.rear->Next = (QueuePtr)malloc(sizeof(QNode));
    q.rear = q.rear->Next;
    q.rear->Data = n;
    q.rear->Next = NULL;
}

bool QDe(LinkQueue &q, int &n)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front->Next;
    q.front->Next = p->Next;
    n = p->Data;
    free(p);
}

bool QDe(LinkQueue &q)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front->Next;
    q.front->Next = p->Next;
    free(p);
}

void QDestroy(LinkQueue &q)
{
    while (QDe(q))
    {
    }
    free(q.front);
}

void QPrint(LinkQueue q)
{
    QueuePtr p = q.front->Next;
    if (p)
    {
        printf("%d", p->Data);
        p = p->Next;
    }
    while (p)
    {
        printf(" %d", p->Data);
        p = p->Next;
    }
    printf("\n");
}

int main()
{
    LinkQueue Q;
    QInit(Q);
    int n, d;
    printf("请输入队列长度：\n");
    cin >> n;
    printf("请输入队列：\n");
    while (n)
    {
        cin >> d;
        QEn(Q, d);
        n --;
    }
    QPrint(Q);
    return 0;
}