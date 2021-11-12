#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int Data;
    struct Node *LChild, *RChild;
} *Tree, TNode;

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

void TDepth(Tree T, int &num, int depth = 0)
{
    if (T)
    {
        depth++;
        num = max(num, depth);
        TDepth(T->LChild, num, depth);
        TDepth(T->RChild, num, depth);
    }
}

int main()
{
    Tree T;
    printf("输入先序遍历输入\n");
    TreeCreate(T);
    printf("前序遍历结果:\n");
    TPreOrder(T);
    printf("\n中序遍历结果:\n");
    TInOrder(T);
    printf("\n后序遍历结果:\n");
    TLastOrder(T);
    int num = 0;
    TNodeNum(T, num);
    printf("\n节点数:\n%d", num);
    num = 0;
    TLeafNum(T, num);
    printf("\n叶子数:\n%d", num);
    num = 0;
    TDepth(T, num);
    printf("\n深度:\n%d", num);
    return 0;
}
