#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;


//����������ʽ�洢�ṹ
typedef struct Bitnode {
    char data;
    struct Bitnode* lchild;
    struct Bitnode* rchild;
}Bitnode, * Bitree;

//���������д���������
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
        printf("����%c����������", ch);
        creatBitree(T->lchild);
        printf("����%c����������", ch);
        creatBitree(T->rchild);
    }
}
//�������
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
//�������
void InOrder(Bitree T)
{
    if (T == NULL) return;
    else {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}
//��������
void PostOrder(Bitree T) {
    if (T == NULL) return;
    else {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
//��α���
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
//���������
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
//����Ҷ�ĸ���
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
    printf("����������");
    creatBitree(T);
    printf("���������\n");
    preOrder(T);
    printf("\n");
    printf("���������\n");
    InOrder(T);
    printf("\n");
    printf("���������\n");
    PostOrder(T);
    printf("\n");
    printf("��α�����\n");
    levelOrder(T);
    printf("\n");
    printf("���������:\n");
    printf("%d\n", TreeDeep(T));
    printf("����Ҷ�ĸ���:\n");
    printf("%d\n", Leafcount(T, num));
    return 0;
}