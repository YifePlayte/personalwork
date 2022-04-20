#include <bits/stdc++.h>
using namespace std;

typedef struct TNode
{
    int Data;
    struct TNode *LChild, *RChild;
} TNode, *Tree;

void TreeCreate(Tree &T)
{
    int num;
    scanf("%d", &num);
    if (num == 0)
        T = NULL;
    else
    {
        T = (Tree)malloc(sizeof(TNode));
        T->Data = num;
        TreeCreate(T->LChild);
        TreeCreate(T->RChild);
    }
}

void TPreOrder(Tree T)
{
    if (T)
    {
        printf("%d", T->Data);
        TPreOrder(T->LChild);
        TPreOrder(T->RChild);
    }
}

void TInOrder(Tree T)
{
    if (T)
    {
        TInOrder(T->LChild);
        printf("%d", T->Data);
        TInOrder(T->RChild);
    }
}

void TLastOrder(Tree T)
{
    if (T)
    {
        TLastOrder(T->LChild);
        TLastOrder(T->RChild);
        printf("%d", T->Data);
    }
}

void TNodeNum(Tree T, int &num)
{
    if (T)
    {
        num++;
        TNodeNum(T->LChild, num);
        TNodeNum(T->RChild, num);
    }
}

void TLeafNum(Tree T, int &num)
{
    if (T)
    {
        if (!T->LChild && !T->RChild)
            num++;
        TLeafNum(T->LChild, num);
        TLeafNum(T->RChild, num);
    }
}

int TDepth(Tree T)
{
    if (!T)
        return 0;
    else
    {
        return 1 + max(TDepth(T->LChild), TDepth(T->RChild));
    }
}

Tree TGetNode(int Data, Tree LChild, Tree RChild)
{
    TNode *T;
    T = (TNode *)malloc(sizeof(TNode));
    T->Data = Data;
    T->LChild = LChild;
    T->RChild = RChild;
    return T;
}

Tree TCopy(Tree T) //8--19:30??
{
    if (!T)
        return NULL;
    return TGetNode(T->Data, TCopy(T->LChild), TCopy(T->RChild));
}

int main()
{
    freopen("input.txt", "rb+", stdin);
    freopen("output.txt", "wb+", stdout);
    Tree T, T2;
    printf("输入先序遍历输入\n");
    TreeCreate(T);
    printf("先序遍历结果:\n");
    TPreOrder(T);
    printf("\n中序遍历结果:\n");
    TInOrder(T);
    printf("\n后序遍历结果:\n");
    TLastOrder(T);
    T2 = TCopy(T);
    printf("\n已复制树！\n");
    printf("先序遍历结果:\n");
    TPreOrder(T2);
    printf("\n中序遍历结果:\n");
    TInOrder(T2);
    printf("\n后序遍历结果:\n");
    TLastOrder(T2);
    int num = 0;
    TNodeNum(T, num);
    printf("\n节点数:\n%d", num);
    num = 0;
    TLeafNum(T, num);
    printf("\n叶子数:\n%d", num);
    printf("\n深度:\n%d", TDepth(T));
    return 0;
}
