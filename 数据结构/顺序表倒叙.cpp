#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;

struct sql
{
    int data[MAX];
    int length = 0;
};

int inputsql(sql *sqlinput)
{
    for(int i = 0; i < sqlinput->length; i ++)
    {
        scanf("%d", &(sqlinput->data[i]));
    }
    return 0;
}

int reverseint(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
    return 0;
}

int reversesql(sql *sqlinput)
{
    for(int i = 0; i < (sqlinput->length - 1) / 2; i ++)
    {
        reverseint(&(sqlinput->data[i]), &(sqlinput->data[sqlinput->length - 1 - i]));
    }
    return 0;
}

int printsql(sql *sqloutput)
{
    if(sqloutput->length == 0)
    {
        printf("sql is empty!\n");
        return 0;
    }
    printf("%d", sqloutput->data[0]);
    for(int i = 1; i < sqloutput->length; i ++)
    {
        printf(" %d", sqloutput->data[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    sql sql1;
    scanf("%d", &sql1.length);
    inputsql(&sql1);
    reversesql(&sql1);
    printsql(&sql1);
    return 0;
}
