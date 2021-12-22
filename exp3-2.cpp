
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node* next;
}LStackNode, * LinkStack;

//��ջ�ĳ�ʼ��

void InitStack(LinkStack* top)
{
    if ((*top = (LinkStack)malloc(sizeof(LStackNode))) == NULL)//Ϊͷ��㿪��һ���洢�ռ�
    {
        exit(-1);
    }
    (*top)->next = NULL; //����ջ��ͷ���ָ������Ϊ��
}

//�ж���ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack top)
{
    if (top->next == NULL)
    {
        return 1;
    }
    return 0;
}

//��ջ����

void PushStack(LinkStack top, DataType data)
{
    LStackNode* p;
    p = (LStackNode*)(malloc(sizeof(LStackNode)));
    if (p == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
    }
    else
    {
        p->data = data;
        p->next = top->next;
        top->next = p;
    }
}

//��ջ����

void PopStack(LinkStack top, DataType* data)
{
    LStackNode* p;
    p = top->next;
    if (p == NULL)
    {
        printf("ջΪ�գ�\n");
    }
    else
    {
        top->next = p->next;
        *data = p->data;
        free(p);   //�ͷ�pָ��Ľ��
    }
}

//ȡջ��Ԫ��

int GetTop(LinkStack top, DataType* data)
{
    LStackNode* p;
    p = top->next;
    if (StackEmpty(top))
    {
        printf("ջΪ�գ�\n");
    }
    else
    {
        *data = p->data;
    }
    return *data;
}

//�������

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

//������ջ
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

//��ӡջ��Ԫ��
void StackPrint(LinkStack top)
{
    LStackNode* p;
    if (StackEmpty(top))
    {
        printf("ջΪ�գ�\n");
    }
    printf("ջ��Ԫ��Ϊ��\n");
    p = top;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%-3d", p->data);

    }

    printf("\n");
}
