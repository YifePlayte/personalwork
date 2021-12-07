#include<bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

typedef struct SQList
{
    int Data[MAXLENGTH];
    int Length;
};

void SQLScan(SQList &L)
{
    scanf("%d", &L.Length);
    for(int i = 1; i <= L.Length; i ++)
    {
        scanf("%d", &L.Data[i]);
    }
}

void SQLPrint(SQList L)
{
    printf("Sorted SQL:");
    for(int i = 1; i <= L.Length; i ++)
        printf(" %d", L.Data[i]);
    printf("\n");
}

void SQLSort(SQList &L)
{
    for(int i = 1; i < L.Length; i ++)
    {
        for(int j = i + 1; j <= L.Length; j ++)
        {
            if(L.Data[j] < L.Data[i])
                swap(L.Data[i], L.Data[j]);
        }
    }
    SQLPrint(L);
}

int SQLSearch(SQList L, int n)
{
    int i = L.Length;
    for(L.Data[0] = n; L.Data[i] != n; i --);
    return i;
}

int SQLHalfSearch(SQList L, int n)
{
    int l = 1, r = L.Length, m = (l + r) / 2;
    int time = 0;
    SQLSort(L);
    while(l <= r)
    {
        if(n == L.Data[m])
        {
            printf("Half time: %d\n", time);
            return m;
        }
        else if(n > L.Data[m])
            l = m + 1;
        else
            r = m - 1;
        m = (l + r) / 2;
        time ++;
    }
    printf("Half time: %d\n", time);
    return 0;
}

int main()
{
    SQList l;
    SQLScan(l);
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d\n", SQLSearch(l, n));
        printf("%d\n\n", SQLHalfSearch(l, n));
    }
    return 0;
}