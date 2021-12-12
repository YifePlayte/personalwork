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

bool SqLDel_C(SqList &L, int Pos)
{
    if (L.Length < 1 || Pos > L.Length)
        return false;
    for (int i = Pos; i < L.Length; i++)
        L.Data[i] = L.Data[i + 1];
    L.Length--;
    return true;
}

void SqLDelAA(SqList &L)
{
    int i = 2;
    if (L.Length == 0)
        return;
    L.Data[0] = L.Data[1];
    while (i <= L.Length)
    {
        if (L.Data[i] == L.Data[0])
            SqLDel_C(L, i);
        else
        {
            L.Data[0] = L.Data[i];
            i++;
        }
    }
    return;
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
    SqLDelAA(l);
    SqLPrint(l);
    return 0;
}
