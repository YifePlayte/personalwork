#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

typedef char CChar[MAXLENGTH];

void CCharInit(CChar &S)
{
    memset(S, 0, sizeof(CChar));
}

int CCharLength(CChar &n)
{
    int length = 0;
    for (; length < MAXLENGTH; length++)
    {
        if (!n[length])
            break;
    }
    return length;
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    CChar n;
    CCharInit(n);
    scanf("%[^\n]", &n);
    cout << CCharLength(n);
}