#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

int* insert_sort(int L[], int Length)
{
    for (int i = 2; i <= Length; i++)
    {
        for (int j = i; j > 1; j--)
        {
            if (L[j] < L[j - 1])
            {
                swap(L[j], L[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
    return L;
}

void SqLPrint(int L[], int Length)
{
    if(Length > 0)
        printf("%d", L[1]);
    for (int i = 2; i <= Length; i++)
        printf(" %d", L[i]);
    return;
}

int main()
{
    int l[MAXLENGTH], length;
    scanf("%d", &length);
    for(int i = 1; i <= length; i++)
    {
        scanf("%d", &l[i]);
    }
    SqLPrint(insert_sort(l, length), length);
    return 0;
}
