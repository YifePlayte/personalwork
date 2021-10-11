#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;

struct sql
{
	int data[MAX];
	int length = 0;
};

int main()
{
	sql sqla;
	scanf("%d", &(sqla.length));
	if(sqla.length == 0)
	{
		printf("length cannot be 0!\n");
		return 0;
	}
	for(int i = 0; i < sqla.length; i ++)
	{
		scanf("%d", &(sqla.data[i]));
	}
	int c;
	for(int i = 0; i < ((sqla.length - 1) / 2); i ++)
	{
		c = sqla.data[i];
		sqla.data[i] = sqla.data[sqla.length - 1 - i];
		sqla.data[sqla.length - 1 - i] = c;
	}
	printf("%d", sqla.data[0]);
	for(int i = 1; i < sqla.length; i ++)
	{
		printf(" %d", sqla.data[i]);
	}
	printf("\n");
	return 0;
}