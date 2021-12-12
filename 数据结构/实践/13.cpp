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

void quick_sort_recursion(SqList &L, int start, int last)
{
    int i = start;
    int j = last;
    int temp = L.Data[i];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j && L.Data[j] >= temp)
            {
                j--;
            }
            if (i < j)
            {
                L.Data[i] = L.Data[j];
                i++;
            }
            while (i < j && temp > L.Data[i])
            {
                i++;
            }
            if (i < j)
            {
                L.Data[j] = L.Data[i];
                j--;
            }
        }
        L.Data[i] = temp;
        quick_sort_recursion(L, start, i - 1);
        quick_sort_recursion(L, i + 1, last);
    }
}

SqList quick_sort(SqList L)
{
    quick_sort_recursion(L, 1, L.Length);
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
    SqLPrint(quick_sort(l));
    return 0;
}
