
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node* next;
}LStackNode, * LinkStack;

//链栈的初始化

void InitStack(LinkStack* top)
{
    if ((*top = (LinkStack)malloc(sizeof(LStackNode))) == NULL)//为头结点开辟一个存储空间
    {
        exit(-1);
    }
    (*top)->next = NULL; //将链栈的头结点指针域置为空
}

//判断链栈是否为空
int StackEmpty(LinkStack top)
{
    if (top->next == NULL)
    {
        return 1;
    }
    return 0;
}

//进栈操作

void PushStack(LinkStack top, DataType data)
{
    LStackNode* p;
    p = (LStackNode*)(malloc(sizeof(LStackNode)));
    if (p == NULL)
    {
        printf("内存分配失败！\n");
    }
    else
    {
        p->data = data;
        p->next = top->next;
        top->next = p;
    }
}

//出栈操作

void PopStack(LinkStack top, DataType* data)
{
    LStackNode* p;
    p = top->next;
    if (p == NULL)
    {
        printf("栈为空！\n");
    }
    else
    {
        top->next = p->next;
        *data = p->data;
        free(p);   //释放p指向的结点
    }
}

//取栈顶元素

int GetTop(LinkStack top, DataType* data)
{
    LStackNode* p;
    p = top->next;
    if (StackEmpty(top))
    {
        printf("栈为空！\n");
    }
    else
    {
        *data = p->data;
    }
    return *data;
}

//求表长操作

int StackLength(LinkStack top)
{
    int count = 0;
    LStackNode* p;
    p = top;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//销毁链栈
void DestoryStack(LinkStack top)
{
    LStackNode* p;
    LStackNode* q;
    p = top;
    while (!p)
    {
        q = p;
        p = p->next;
        free(q);
    }

}

//打印栈中元素
void StackPrint(LinkStack top)
{
    LStackNode* p;
    if (StackEmpty(top))
    {
        printf("栈为空！\n");
    }
    printf("栈中元素为：\n");
    p = top;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%-3d", p->data);

    }

    printf("\n");
}
