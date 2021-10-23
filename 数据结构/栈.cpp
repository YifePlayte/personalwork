#include<bits/stdc++.h>
using namespace std;

typedef struct SNode
{
	int Data;
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

bool SPop(Stack &S)
{
	if(SEmpty(S))
		return false;
	Stack p = S->Next;
	S->Next = p->Next;
	free(p);
	return true;
}

bool SPop(Stack &S, int &n)
{
	if(SEmpty(S))
		return false;
	Stack p = S->Next;
	S->Next = p->Next;
	n = p->Data;
	free(p);
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
	Stack S;
	SInit(S);
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