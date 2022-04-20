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

int CCharIndex(CChar s, CChar t, int pos)
{
    int sl = CCharLength(s), tl = CCharLength(t), i = pos, j = 0;
    while (i < sl && j < tl)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == tl)
    {
        return i - j;
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
    cout << CCharIndex(s, t, 0) + 1;
    return 0;
}