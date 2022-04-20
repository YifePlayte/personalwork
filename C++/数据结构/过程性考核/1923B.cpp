#include<bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

int LFind(int L[], int length, int kval)
{
    L[0] = kval;
    int ans = length;
    while(L[ans] != kval)
    {
        ans--;
    }
    return ans;
}

int main()
{
    int l[MAXLENGTH], length, kval;
    scanf("%d", &length);
    for(int i = 1; i <= length; i++)
    {
        scanf("%d", &l[i]);
    }
    scanf("%d", &kval);
    printf("%d", LFind(l, length, kval));
    return 0;
}
