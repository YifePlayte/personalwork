#include <bits/stdc++.h>
using namespace std;
const int MAXLENGTH = 100;

typedef struct SqList
{
    int Data[MAXLENGTH];
    int Length;
} SqList;

bool SqLEmpty(SqList L)
{
    return (L.Length == 0);
}

bool SqLInit(SqList &L)
{
    L.Length = 0;
    return true;
}

bool SqLIns_R(SqList &L, int n)
{
    if (L.Length >= MAXLENGTH)
        return false;
    L.Data[L.Length] = n;
    L.Length++;
    return true;
}

int SqLFind(SqList L, int n)
{
    for (int i = 0; i < L.Length; i++)
    {
        if (L.Data[i] == n)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    SqList l;
    int n;
    while (~scanf("%d", &n))
    {
        SqLInit(l);
        SqLIns_R(l, n);
        if (getchar() == '\n')
        {
            scanf("%d", &n);
            printf("%d\n", SqLFind(l, n));
        }
        else
        {
            while (~scanf("%d", &n))
            {
                SqLIns_R(l, n);
                if (getchar() == '\n')
                {
                    break;
                }
            }
            scanf("%d", &n);
            printf("%d\n", SqLFind(l, n));
        }
    }
    return 0;
}