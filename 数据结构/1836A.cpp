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
	n = q.front->Next->Data;
	QueuePtr p = q.front;
	q.front = q.front->Next;
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

int main()
{
	int n;
	cin >> n;
	LinkQueue Q;
	QInit(Q);
	while (n)
	{
		QEn(Q, n % 10);
		n /= 10;
	}
	if (QEmpty(Q))
	{
		printf("1\n");
		printf("0");
	}
	else
		printf("%d\n", QLength(Q));
	while (!QEmpty(Q))
	{
		QDe(Q, n);
		printf("%d", n);
	}
	// printf("\n");
}