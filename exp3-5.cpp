
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
void Hanoi1(int n, char a, char b, char c)
{
    if (n == 1)
        printf("\t将第%d个盘片从%c移动到%c\n", n, a, c);
    else
    {
        Hanoi1(n - 1, a, c, b);
        printf("\t将第%d个盘片从%c移动到%c\n", n, a, c);
        Hanoi1(n - 1, b, a, c);
    }
}


typedef struct
{
    int n;                          //盘片个数
    char x, y, z;                     //3个塔座
    bool flag;                      //可直接移动盘片时为true,否则为false
} ElemType;                         //顺序栈中元素类型
typedef struct
{
    ElemType data[MaxSize];         //存放元素
    int top;                        //栈顶指针
} StackType;                        //顺序栈类型

//--求解Hanoi问题对应顺序栈的基本运算算法--------------
void InitStack(StackType*& s)           //初始化栈
{
    s = (StackType*)malloc(sizeof(StackType));
    s->top = -1;
}
void DestroyStack(StackType*& s)        //销毁栈
{
    free(s);
}
bool StackEmpty(StackType* s)           //判断栈是否为空
{
    return(s->top == -1);
}
bool Push(StackType*& s, ElemType e)     //进栈
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(StackType*& s, ElemType& e)     //出栈
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(StackType* s, ElemType& e)       //取栈顶元素
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

