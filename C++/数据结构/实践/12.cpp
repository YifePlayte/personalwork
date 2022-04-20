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

SqList bubble_sort(SqList L)
{

    for (int i = 1; i < L.Length; i++)
    {
        for (int j = 1; j <= L.Length - i; j++)
        {
            if (L.Data[j] > L.Data[j + 1])
                swap(L.Data[j], L.Data[j + 1]);
        }
    }
    return L;
}

int main()
{
    SqList l;
    int n;
    SqLInit(l);
    while (~scanf("%d", &n))
    {
        SqLIns_R(l, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    SqLPrint(bubble_sort(l));
    return 0;
}
