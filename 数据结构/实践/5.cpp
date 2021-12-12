#include <bits/stdc++.h>
using namespace std;
const int MAXLENGTH = 100;

typedef struct SqList
{
    int Data[MAXLENGTH + 1];
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
    L.Data[L.Length + 1] = n;
    L.Length++;
    return true;
}

bool SqLDel_C(SqList &L, int Pos)
{
    if (L.Length < 1 || Pos > L.Length)
        return false;
    for (int i = Pos; i < L.Length; i++)
        L.Data[i] = L.Data[i + 1];
    L.Length--;
    return true;
}

int SqLFind_Half(SqList L, int n)
{
    int l = 1, r = L.Length, m = (l + r) / 2;
    while (l <= r)
    {
        if (n == L.Data[m])
            return m + 1;
        else if (n > L.Data[m])
            l = m + 1;
        else
            r = m - 1;
        m = (l + r) / 2;
    }
    return 0;
}

void SqLDelFromAB(SqList &L, SqList A, SqList B)
{
    int i = 1;
    while (i <= L.Length)
    {
        if (SqLFind_Half(A, L.Data[i]) > 0 && SqLFind_Half(B, L.Data[i]) > 0)
        {
            SqLDel_C(L, i);
        }
        else
            i++;
    }
}

void SqLPrint(SqList L)
{
    cout << "Length: " << L.Length << endl
         << "Data: ";
    if (L.Length == 0)
    {
        cout << "Empty!" << endl;
        return;
    }
    printf("%d", L.Data[1]);
    for (int i = 2; i <= L.Length; i++)
        printf(" %d", L.Data[i]);
    printf("\n");
    return;
}

int main()
{
    SqList a, b, c;
    SqLInit(a);
    SqLInit(b);
    SqLInit(c);
    int n;
    while (~scanf("%d", &n))
    {
        SqLIns_R(a, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    while (~scanf("%d", &n))
    {
        SqLIns_R(b, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    while (~scanf("%d", &n))
    {
        SqLIns_R(c, n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    SqLDelFromAB(a, b, c);
    SqLPrint(a);
    return 0;
}
