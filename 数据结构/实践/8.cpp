#include<bits/stdc++.h>
using namespace std;

int main()
{
	char n[100];
	int i = 0;
	char m;
	m = getchar();
	while (m != '@')
	{
		n[i] = m;
		i ++;
		m = getchar();
	}
	for (int j = 0; j < i - j - 1; j++)
	{
		if (n[j] != n[i - j - 1])
		{
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 0;
}