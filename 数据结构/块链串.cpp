#include <bits/stdc++.h>
using namespace std;
const int NLENGTH = 4;

typedef struct BCSNode
{
    char Data[NLENGTH];
    BCSNode *Next;
} BCSNode, *BCString;

void BCSInit(BCString &S)
{
    S = (BCString)malloc(sizeof(BCSNode));
    memset(S, 0, sizeof(BCSNode));
    S->Next = NULL;
}

void BCSEn(BCString &S, char n[NLENGTH])
{
    BCString p = S;
    while (p->Next)
    {
        p = p->Next;
    }
    BCSInit(p->Next);
    for (int i = 0; i < NLENGTH; i++)
    {
        p->Next->Data[i] = n[i];
    }
}

void BCSIn(BCString &S)
{
    char n, cache[NLENGTH];
    int SLength = 0;
    memset(cache, 0, sizeof(char) * NLENGTH);
    while (~scanf("%c", &n))
    {
        if(n == '\n')
        {
            break;
        }
        cache[SLength % NLENGTH] = n;
        SLength++;
        if (!(SLength % NLENGTH))
        {
            BCSEn(S, cache);
            memset(cache, 0, sizeof(char) * NLENGTH);
        }
    }
    BCSEn(S, cache);
}

void BCSPrint(BCString &S)
{
    if (!S->Next)
    {
        printf("Empty!\n");
        return;
    }
    BCString p = S;
    while (p->Next)
    {
        p = p->Next;
        cout << p->Data;
    }
    printf("\n");
}

int BCSLength(BCString &S)
{
    if (!S->Next)
    {
        return 0;
    }
    BCString p = S;
    int n = 0;
    while (p->Next)
    {
        p = p->Next;
        for(int i = 0; i < NLENGTH; i ++)
        {
            if(p->Data[i])
            n ++;
            else return n;
        }
    }
    return n;
}

int main()
{
    // freopen("input.txt", "rb+", stdin);
    // freopen("output.txt", "wb+", stdout);
    BCString S;
    BCSInit(S);
    BCSIn(S);
    // BCSPrint(S);
    cout << BCSLength(S);
    return 0;
}