#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 100;

typedef struct SqList
{
    int Data[MAXLENGTH];
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
        L.Data[i] = L.Data[i - 1];
    L.Data[Pos - 1] = n;
    L.Length++;
    return true;
}

bool SqLIns_L(SqList &L, int n)
{
    if (L.Length >= MAXLENGTH)
        return false;
    for (int i = L.Length; i > 0; i--)
        L.Data[i] = L.Data[i - 1];
    L.Data[0] = n;
    L.Length++;
    return true;
}

bool SqLIns_R(SqList &L, int n)
{
    if (L.Length >= MAXLENGTH)
        return false;
    L.Data[L.Length] = n;
    L.Length++;
    return true;
}

bool SqLDel_C(SqList &L, int Pos)
{
    if (L.Length < 1 || Pos > L.Length)
        return false;
    for (int i = Pos; i < L.Length; i++)
        L.Data[i - 1] = L.Data[i];
    L.Length--;
    return true;
}

bool SqLDel_L(SqList &L)
{
    if (L.Length < 1)
        return false;
    for (int i = 1; i < L.Length; i++)
        L.Data[i - 1] = L.Data[i];
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
    printf("%d", L.Data[0]);
    for (int i = 1; i < L.Length; i++)
        printf(" %d", L.Data[i]);
    printf("\n");
    return;
}

int main()
{
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
    cout << "请输入要选插的位置以及数据：";
    cin >> n >> data;
    if (!SqLIns_C(l, n, data))
    {
        cout << "顺序表选插异常！" << endl;
    }
    SqLPrint(l);
    cout << "请输入要头插的数据：";
    cin >> data;
    if (!SqLIns_L(l, data))
    {
        cout << "顺序表头插异常！" << endl;
    }
    SqLPrint(l);
    cout << "请输入要尾插的数据：";
    cin >> data;
    if (!SqLIns_R(l, data))
    {
        cout << "顺序表尾插异常！" << endl;
    }
    SqLPrint(l);
    cout << "请输入要选删的位置：";
    cin >> n;
    if (!SqLDel_C(l, n))
    {
        cout << "顺序表选删异常！" << endl;
    }
    SqLPrint(l);
    if (!SqLDel_L(l))
    {
        cout << "顺序表头删异常！" << endl;
    }
    else cout << "已完成头删！" << endl;
    SqLPrint(l);
    if (!SqLDel_R(l))
    {
        cout << "顺序表尾删异常！" << endl;
    }
    else cout << "已完成尾删！" << endl;
    SqLPrint(l);
    return 0;
}