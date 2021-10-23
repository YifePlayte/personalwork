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

bool SqLIns_C(SqList &L, int Pos, int n)
{
    if ((Pos > (L.Length + 1)) || (L.Length >= MAXLENGTH))
        return false;
    for (int i = L.Length; i >= Pos; i--)
        L.Data[i] = L.Data[i - 1];
    L.Data[Pos - 1] = n;
    L.Length++;
    return true;
}

bool SqLIns_L(SqList &L, int n)
{
    if (L.Length >= MAXLENGTH)
        return false;
    for (int i = L.Length; i > 0; i--)
        L.Data[i] = L.Data[i - 1];
    L.Data[0] = n;
    L.Length++;
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

bool SqLDel_C(SqList &L, int Pos)
{
    if (L.Length < 1 || Pos > L.Length)
        return false;
    for (int i = Pos; i < L.Length; i++)
        L.Data[i - 1] = L.Data[i];
    L.Length--;
    return true;
}

bool SqLDel_L(SqList &L)
{
    if (L.Length < 1)
        return false;
    for (int i = 1; i < L.Length; i++)
        L.Data[i - 1] = L.Data[i];
    L.Length--;
    return true;
}

bool SqLDel_R(SqList &L)
{
    if (L.Length < 1)
        return false;
    L.Length--;
    return true;
}

int SqLLength(SqList L)
{
    return L.Length;
}

bool SqLSearch(SqList L, int n, int &ans)
{
    if(n < 1 || n > L.Length)
        return false;
    ans = L.Data[n - 1];
    return true;
}

int main()
{
    int n;
    SqList l;
    SqLInit(l);
    while(~scanf("%d", &n))
    {
        SqLIns_L(l, n);
    }
    // scanf("%d", &n);
    // for(int i = n; i > 0; i --)
    // {
    //     scanf("%d", &n);
    //     SqLIns_L(l, n);
    // }
    printf("%d\n", SqLLength(l));
    while(!SqLEmpty(l))
    {
        SqLSearch(l, 1, n);
        printf("%d", n);
        SqLDel_L(l);
    }
    return 0;
}