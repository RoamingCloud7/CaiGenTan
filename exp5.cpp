#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;


//二叉树的链式存储结构
typedef struct Bitnode {
    char data;
    struct Bitnode* lchild;
    struct Bitnode* rchild;
}Bitnode, * Bitree;

//按先序序列创建二叉树
void creatBitree(Bitree& T)
{
    char ch;
    scanf("%c", &ch);
    getchar();
    if (ch == ' ')
        T = NULL;
    else
    {
        T = (Bitree)malloc(sizeof(Bitnode));
        T->data = ch;
        printf("输入%c的左子树：", ch);
        creatBitree(T->lchild);
        printf("输入%c的右子树：", ch);
        creatBitree(T->rchild);
    }
}
//先序遍历
void preOrder(Bitree T)
{
    if (T == NULL) return;
    else
    {
        printf("%c", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
//中序遍历
void InOrder(Bitree T)
{
    if (T == NULL) return;
    else {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}
//后续遍历
void PostOrder(Bitree T) {
    if (T == NULL) return;
    else {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
//层次遍历
void levelOrder(Bitree T)
{
    Bitree p = T;
    queue<Bitree> Q;
    Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();
        printf("%c", p->data);
        if (p->lchild != NULL)
            Q.push(p->lchild);
        if (p->rchild != NULL)
            Q.push(p->rchild);
    }
}
//求树的深度
int TreeDeep(Bitree T)
{
    int deep = 0;
    if (T)
    {
        int leftdeep = TreeDeep(T->lchild);
        int rightdeep = TreeDeep(T->rchild);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
    }
    return deep;
}
//求树叶的个数
int Leafcount(Bitree T, int& num)
{
    if (T)
    {
        if (T->lchild == NULL && T->rchild == NULL)
            num++;
        Leafcount(T->lchild, num);
        Leafcount(T->rchild, num);
    }
    return num;
}

int main()
{
    Bitree T;
    int num = 0;
    printf("输入树根：");
    creatBitree(T);
    printf("先序遍历：\n");
    preOrder(T);
    printf("\n");
    printf("中序遍历：\n");
    InOrder(T);
    printf("\n");
    printf("后序遍历：\n");
    PostOrder(T);
    printf("\n");
    printf("层次遍历：\n");
    levelOrder(T);
    printf("\n");
    printf("求树的深度:\n");
    printf("%d\n", TreeDeep(T));
    printf("求树叶的个数:\n");
    printf("%d\n", Leafcount(T, num));
    return 0;
}