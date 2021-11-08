#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

typedef char CChar[MAXLENGTH];

void CCharInit(CChar &S)
{
    memset(S, 0, sizeof(CChar));
}

int CCharComp(CChar a, CChar b)
{
    int comp, i = 0;
    while (1)
    {
        comp = a[i] - b[i];
        // cout << "[log] i = " << i << endl;
        if (comp != 0 || a[i] == 0 || b[i] == 0)
            return comp;
        i++;
    }
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    CChar a, b;
    CCharInit(a);
    CCharInit(b);
    scanf("%[^\n]", &a);
    getchar();
    scanf("%[^\n]", &b);
    cout << CCharComp(a, b);
    return 0;
}