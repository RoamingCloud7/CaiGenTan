
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
void Hanoi1(int n, char a, char b, char c)
{
    if (n == 1)
        printf("\t����%d����Ƭ��%c�ƶ���%c\n", n, a, c);
    else
    {
        Hanoi1(n - 1, a, c, b);
        printf("\t����%d����Ƭ��%c�ƶ���%c\n", n, a, c);
        Hanoi1(n - 1, b, a, c);
    }
}


typedef struct
{
    int n;                          //��Ƭ����
    char x, y, z;                     //3������
    bool flag;                      //��ֱ���ƶ���ƬʱΪtrue,����Ϊfalse
} ElemType;                         //˳��ջ��Ԫ������
typedef struct
{
    ElemType data[MaxSize];         //���Ԫ��
    int top;                        //ջ��ָ��
} StackType;                        //˳��ջ����

//--���Hanoi�����Ӧ˳��ջ�Ļ��������㷨--------------
void InitStack(StackType*& s)           //��ʼ��ջ
{
    s = (StackType*)malloc(sizeof(StackType));
    s->top = -1;
}
void DestroyStack(StackType*& s)        //����ջ
{
    free(s);
}
bool StackEmpty(StackType* s)           //�ж�ջ�Ƿ�Ϊ��
{
    return(s->top == -1);
}
bool Push(StackType*& s, ElemType e)     //��ջ
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(StackType*& s, ElemType& e)     //��ջ
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(StackType* s, ElemType& e)       //ȡջ��Ԫ��
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

