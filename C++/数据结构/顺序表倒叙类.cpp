#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;

class sql
{
    int data[MAX];
    int length = 0;
public:
    void reverse();
    void input();
    void print();
};

void sql::reverse()
{
    int c;
    for (int i = 0; i < (length - 1) / 2; i ++)
    {
        c = data[i];
        data[i] = data[length - 1 - i];
        data[length - 1 - i] = c;
    }
}

void sql::input()
{
    scanf("%d", &length);
    for (int i = 0; i < length; i ++)
    {
        scanf("%d", &data[i]);
    }
}

void sql::print()
{
    if (length == 0)
    {
        printf("sql is empty!\n");
        return;
    }
    printf("%d", data[0]);
    for (int i = 1; i < length; i ++)
    {
        printf(" %d", data[i]);
    }
    printf("\n");
}

int main()
{
    sql sql1;
    sql1.input();
    sql1.reverse();
    sql1.print();
    return 0;
}
