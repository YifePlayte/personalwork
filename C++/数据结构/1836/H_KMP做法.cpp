#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

typedef char CChar[MAXLENGTH];

void CCharInit(CChar &S)
{
    memset(S, 0, sizeof(CChar));
}

int CCharLength(CChar n)
{
    int length = 0;
    for (; length < MAXLENGTH; length++)
    {
        if (!n[length])
            break;
    }
    return length;
}

int CCharKMPNext(CChar t, int *N)
{
    int i = 0, j = -1, tl = CCharLength(t);
    N[0] = -1;
    while (i < tl - 1)
    {
        if (j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            N[i] = j;
        }
        else
        {
            j = -1;
        }
    }
}

int CCharKMP(CChar s, CChar t, int pos)
{
    int i = pos, j = 0, N[MAXLENGTH], sl = CCharLength(s), tl = CCharLength(t);
    CCharKMPNext(t, N);
    while (i < sl && j < tl)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = N[j];
        }
    }
    if (j == tl)
    {
        return (i - j);
    }
    else
        return -1;
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    CChar s, t;
    CCharInit(s);
    CCharInit(t);
    scanf("%[^\n]", &s);
    getchar();
    scanf("%[^\n]", &t);
    cout << CCharKMP(s, t, 0) + 1;
    return 0;
}