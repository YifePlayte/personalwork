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

int SqLFind_Half(SqList L, int n)
{
    int l = 0, r = L.Length - 1, m = (l + r) / 2;
    while(l <= r)
    {
        if(n == L.Data[m])
        {
            return m + 1;
        }
        else if(n > L.Data[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
        m = (l + r) / 2;
    }
    return 0;
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    SqList l;
    int n;
    while (~scanf("%d", &n))
    {
        SqLInit(l);
        SqLIns_R(l, n);
        if (getchar() == '\n')
        {
            scanf("%d", &n);
            printf("%d\n", SqLFind_Half(l, n));
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
            printf("%d\n", SqLFind_Half(l, n));
        }
    }
    return 0;
}