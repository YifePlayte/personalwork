#include<bits/stdc++.h>
using namespace std;

typedef struct SNode
{
	int Data;
	SNode *Next;
} SNode, *Stack;

Stack SNew()
{
	Stack S = (Stack)malloc(sizeof(SNode));
	S->Next = NULL;
	return S;
}

void SPush(Stack &S, int n)
{
	Stack p = S->Next;
	S->Next = (Stack)malloc(sizeof(SNode));
	S->Next->Data = n;
	S->Next->Next = p;
}

int STop(Stack S)
{
	return S->Next->Data;
}

void SPop(Stack &S)
{
	Stack p = S->Next;
	S->Next = p->Next;
	free(p);
}

bool SEmpty(Stack S)
{
	if (S->Next)
		return false;
	else
		return true;
}

int main() //十进制转八进制 
{
	int m, n;
	bool neg = false;
	scanf("%d", &m);
	n = abs(m);
	if (m < 0)
		neg = true;
	Stack S = SNew();
	while (n != 0)
	{
		SPush(S, n % 8);
		n /= 8;
	}
	if (neg)
		printf("(%d)10 = (-", m);
	else
		printf("(%d)10 = (", m);
	if (SEmpty(S))
		printf("0");
	else
	{
		while (!SEmpty(S))
		{
			printf("%d", STop(S));
			SPop(S);
		}
	}
	printf(")8\n");
	return 0;
}