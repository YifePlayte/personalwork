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

bool QDe(LinkQueue &q, int &n)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front->Next;
    if (p == q.rear)
        q.rear = q.front;
    q.front->Next = p->Next;
    n = p->Data;
    free(p);
    return true;
}

bool QDe(LinkQueue &q)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front->Next;
    if (p == q.rear)
        q.rear = q.front;
    q.front->Next = p->Next;
    free(p);
    return true;
}

bool QDe2(LinkQueue &q, int &n)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front;
    q.front = q.front->Next;
    n = p->Data;
    free(p);
    return true;
}

bool QDe2(LinkQueue &q)
{
    if (QEmpty(q))
        return false;
    QueuePtr p = q.front;
    q.front = q.front->Next;
    free(p);
    return true;
}

void QPrint(LinkQueue q)
{
    QueuePtr p = q.front->Next;
    if (p)
    {
        printf("%d", p->Data);
        p = p->Next;
    }
    else
    {
        cout << "队列为空！" << endl;
        return;
    }
    while (p)
    {
        printf(" %d", p->Data);
        p = p->Next;
    }
    printf("\n");
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
    LinkQueue Q;
    QInit(Q);
    int n, d;
    cout << "请输入队列长度：" << endl;
    cin >> n;
    cout << "请输入队列：" << endl;
    while (n)
    {
        cin >> d;
        QEn(Q, d);
        n--;
    }
    cout << "队列内容为：" << endl;
    QPrint(Q);
    if (QHead(Q, d))
    {
        cout << "队头为：" << d << endl;
    }
    else
        cout << "队列为空！" << endl;
    if (QDe(Q, d))
    {
        cout << "队头为：" << d << "，已被弹出" << endl;
    }
    else
        cout << "队列为空！" << endl;
    if (QDe(Q, d))
    {
        cout << "队头为：" << d << "，已被弹出" << endl;
    }
    else
        cout << "队列为空！" << endl;
    cout << "队列内容为：" << endl;
    QPrint(Q);
    cout << "队列长度为：" << QLength(Q) << endl;
    QDestroy(Q);
    cout << "队列已被Destroy！" << endl;
    return 0;
}