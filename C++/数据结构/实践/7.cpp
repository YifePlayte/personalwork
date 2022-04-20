#include<bits/stdc++.h>
using namespace std;

typedef struct SNode
{
	char Data;
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

void SPush(Stack &S, char n)
{
	Stack p = S->Next;
	S->Next = (Stack)malloc(sizeof(SNode));
	S->Next->Data = n;
	S->Next->Next = p;
}

char STop(Stack S)
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

bool SPop(Stack &S, char &n)
{
	if (SEmpty(S))
		return false;
	Stack p = S->Next;
	S->Next = p->Next;
	n = p->Data;
	free(p);
	return true;
}

int main()
{
	char n[100];
	Stack s;
	SInit(s);
	cin >> n;
	int i = 0, j = 0;
	while (n[i])
	{
		if (n[i] == 'S')
		{
			n[j] = 'S';
			j++;
		}
		else
		{
			SPush(s, 'H');
		}
		i++;
	}
	while (!SEmpty(s))
	{
		SPop(s, n[j]);
		j++;
	}
	cout << n << endl;
	return 0;
}