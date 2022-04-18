#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

typedef struct SqList
{
    int Data[MAXLENGTH + 1];
    int Length;
} SqList;

bool SqLInit(SqList &L)
{
    L.Length = 0;
    return true;
}

bool SqLIns_R(SqList &L, int n)
{
    if (L.Length >= MAXLENGTH)
        return false;
    L.Data[L.Length + 1] = n;
    L.Length++;
    return true;
}

void SqLPrint(SqList L)
{
    for (int i = 1; i <= L.Length; i ++)
    {
        printf("%d ", L.Data[i]);
    }
    return;
}

SqList choose_sort(SqList L)
{
    for (int i = 1; i < L.Length; i++)
    {
        int Min = i;
        for (int j = i + 1; j <= L.Length; j++)
        {
            if (L.Data[j] < L.Data[Min])
            {
                Min = j;
            }
        }
        swap(L.Data[i], L.Data[Min]);
    }
    return L;
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    SqList l;
    int n;
    SqLInit(l);
    while (~scanf("%d", &n))
    {
        SqLIns_R(l, n);
    }
    SqLPrint(choose_sort(l));
    return 0;
}
