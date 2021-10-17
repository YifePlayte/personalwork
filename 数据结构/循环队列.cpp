#include <bits/stdc++.h>
using namespace std;

const int MAXQSIZE = 7;

typedef struct SqQueue
{
    int *base;
    int front;
    int rear;
} SqQueue;

bool SqQInit(SqQueue &q)
{
    q.base = (int *)malloc(MAXQSIZE * sizeof(int));
    q.front = q.rear = 0;
    return true;
}

bool SqQEmpty(SqQueue q)
{
    return (q.front == q.rear);
}

int SqQLength(SqQueue q)
{
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

bool SqQHead(SqQueue q, int &n)
{
    if (SqQEmpty(q))
        return false;
    n = *(q.base + q.front);
    return true;
}

bool SqQEn(SqQueue &q, int n)
{
    if ((q.rear + 1) % MAXQSIZE == q.front)
        return false;
    *(q.base + q.rear) = n;
    q.rear = (q.rear + 1) % MAXQSIZE;
    return true;
}

bool SqQDe(SqQueue &q, int &n)
{
    if (SqQEmpty(q))
        return false;
    n = *(q.base + q.front);
    q.front = (q.front + 1) % MAXQSIZE;
    return true;
}

bool SqQDe(SqQueue &q)
{
    if (SqQEmpty(q))
        return false;
    q.front = (q.front + 1) % MAXQSIZE;
    return true;
}

void SqQPrint(SqQueue q)
{
    int i = q.front;
    if (SqQEmpty(q))
    {
        cout << "队列为空！" << endl;
        return;
    }
    else
    {
        printf("%d", *(q.base + i));
        i = (i + 1) % MAXQSIZE;
    }
    while (i != q.rear)
    {
        printf(" %d", *(q.base + i));
        i = (i + 1) % MAXQSIZE;
    }
    cout << endl;
}

int main()
{
    SqQueue Q;
    SqQInit(Q);
    int n, d;
    cout << "请输入队列长度：" << endl;
    cin >> n;
    cout << "请输入队列：" << endl;
    while(n)
    {
        cin >> d;
        SqQEn(Q, d);
        n--;
    }
    cout << "队列内容为：" << endl;
    SqQPrint(Q);
    if (SqQHead(Q, d))
    {
        cout << "队头为：" << d << endl;
    }
    else
        cout << "队列为空！" << endl;
    if (SqQDe(Q, d))
    {
        cout << "队头为：" << d << "，已被弹出" << endl;
    }
    else
        cout << "队列为空！" << endl;
    if (SqQDe(Q, d))
    {
        cout << "队头为：" << d << "，已被弹出" << endl;
    }
    else
        cout << "队列为空！" << endl;
    cout << "队列内容为：" << endl;
    SqQPrint(Q);
    cout << "队列长度为：" << SqQLength(Q) << endl;
    cout << "请输入队列长度：" << endl;
    cin >> n;
    cout << "请输入队列：" << endl;
    while(n)
    {
        cin >> d;
        SqQEn(Q, d);
        n--;
    }
    cout << "队列内容为：" << endl;
    SqQPrint(Q);
    if (SqQHead(Q, d))
    {
        cout << "队头为：" << d << endl;
    }
    else
        cout << "队列为空！" << endl;
    if (SqQDe(Q, d))
    {
        cout << "队头为：" << d << "，已被弹出" << endl;
    }
    else
        cout << "队列为空！" << endl;
    if (SqQDe(Q, d))
    {
        cout << "队头为：" << d << "，已被弹出" << endl;
    }
    else
        cout << "队列为空！" << endl;
    cout << "队列内容为：" << endl;
    SqQPrint(Q);
    cout << "队列长度为：" << SqQLength(Q) << endl;
    return 0;
}