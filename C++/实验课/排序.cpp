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

bool SqLIns_C(SqList &L, int Pos, int n)
{
    if ((Pos > (L.Length + 1)) || (L.Length >= MAXLENGTH))
        return false;
    for (int i = L.Length; i >= Pos; i--)
        L.Data[i + 1] = L.Data[i];
    L.Data[Pos] = n;
    L.Length++;
    return true;
}

bool SqLIns_L(SqList &L, int n)
{
    if (L.Length >= MAXLENGTH)
        return false;
    for (int i = L.Length; i > 0; i--)
        L.Data[i + 1] = L.Data[i];
    L.Data[1] = n;
    L.Length++;
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

bool SqLDel_L(SqList &L)
{
    if (L.Length < 1)
        return false;
    for (int i = 1; i < L.Length; i++)
        L.Data[i] = L.Data[i + 1];
    L.Length--;
    return true;
}

bool SqLDel_R(SqList &L)
{
    if (L.Length < 1)
        return false;
    L.Length--;
    return true;
}

void SqLPrint(SqList L)
{
    cout << "顺序表长度为：" << L.Length << endl
         << "顺序表内容为：";
    if (L.Length == 0)
    {
        cout << "空！" << endl;
        return;
    }
    printf("%d", L.Data[1]);
    for (int i = 2; i <= L.Length; i++)
        printf(" %d", L.Data[i]);
    printf("\n");
    return;
}

SqList bubble_sort(SqList L)
{

    for (int i = 1; i < L.Length; i++)
    {
        for (int j = 1; j <= L.Length - i; j++)
        {
            if (L.Data[j] > L.Data[j + 1])
                swap(L.Data[j], L.Data[j + 1]);
        }
    }
    return L;
}

SqList choose_sort(SqList L)
{
    for (int i = 1; i < L.Length; i++)
    {
        int Min = i;
        for (int j = i + 1; j <= L.Length; j++)
        {
            if (L.Data[j] < L.Data[Min])
            {
                Min = j;
            }
        }
        swap(L.Data[i], L.Data[Min]);
    }
    return L;
}

SqList insert_sort(SqList L)
{
    for (int i = 2; i <= L.Length; i++)
    {
        for (int j = i; j > 1; j--)
        {
            if (L.Data[j] < L.Data[j - 1])
            {
                swap(L.Data[j], L.Data[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
    return L;
}

void quick_sort_recursion(SqList &L, int start, int last)
{
    int i = start;
    int j = last;
    int temp = L.Data[i];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j && L.Data[j] >= temp)
            {
                j--;
            }
            if (i < j)
            {
                L.Data[i] = L.Data[j];
                i++;
            }
            while (i < j && temp > L.Data[i])
            {
                i++;
            }
            if (i < j)
            {
                L.Data[j] = L.Data[i];
                j--;
            }
        }
        L.Data[i] = temp;
        quick_sort_recursion(L, start, i - 1);
        quick_sort_recursion(L, i + 1, last);
    }
}

SqList quick_sort(SqList L)
{
    quick_sort_recursion(L, 1, L.Length);
    return L;
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    SqList l;
    int n, data;
    SqLInit(l);
    cout << "请输入顺序表长度：";
    cin >> n;
    if (n > MAXLENGTH || n < 0)
    {
        cout << "长度不合法！" << endl;
        return 0;
    }
    if (n)
        cout << "请输入顺序表：" << endl;
    else
        cout << "新建了个空顺序表！" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        if (!SqLIns_R(l, data))
        {
            cout << "顺序表输入异常！" << endl;
            return 0;
        }
    }
    SqLPrint(l);
    printf("\n冒泡排序：\n");
    SqLPrint(bubble_sort(l));
    printf("\n选择排序：\n");
    SqLPrint(choose_sort(l));
    printf("\n插入排序：\n");
    SqLPrint(insert_sort(l));
    printf("\n快速排序：\n");
    SqLPrint(quick_sort(l));
    printf("\n原表：\n");
    SqLPrint(l);
    return 0;
}
