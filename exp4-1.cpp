#include<stdio.h>
#include<stdlib.h>
typedef int QElemType;
/*������*/
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

typedef struct
{
	QueuePtr front;          /*��ͷָ��*/
	QueuePtr rear;           /*��βָ��*/
} LinkQueue;

/*��ʼ��һ������*/
int InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) return 0;/*����ͷ�ڵ�ʧ��*/
	Q->front->next = NULL;
	return 1; //��ʼ���ɹ��򷵻�1
}

/*���ٶ���Q*/
int DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next; /*Q->rearָ��Q->front����һ���ڵ�*/
		free(Q->front);/*�ͷ�Q->front��ָ�ڵ�*/
		Q->front = Q->rear; /*Q->frontָ��Q->front����һ���ڵ�*/
	}
	return 1;
}

/*��ӣ�����Ԫ��eΪ����Q���µĶ�βԪ��*/
int EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode)); /*��̬�����½ڵ�*/
	if (!p) return 0; //����ʧ���򷵻�0
	p->data = e; /*��e��ֵ�����½ڵ�*/
	p->next = NULL; /*�½ڵ��ָ��Ϊ��*/
	Q->rear->next = p; /*ԭ��β�ڵ��ָ����Ϊָ���½ڵ�*/
	Q->rear = p; /*βָ��ָ���½ڵ�*/
	return 1; //��ջ�ɹ��򷵻�1
}

/*���ӣ������в�Ϊ�գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ*/
int DeQueue(LinkQueue* Q, QElemType* e)
{
	QueuePtr p;
	if (Q->front == Q->rear) return 0; /*����Ϊ��*/
	p = Q->front->next; /*pָ���ͷ�ڵ�*/
	*e = p->data; /*��ͷԪ�ظ���e*/
	Q->front->next = p->next; /*ͷ�ڵ�ָ����һ���ڵ�*/
	if (Q->rear == p) /*���ɾ���Ķ�β�ڵ�*/
		Q->rear = Q->front; /*�޸Ķ�βָ��ָ��ͷ�ڵ�*/
	free(p);
	return 1; //���ӳɹ��򷵻�1
}

/*�ж϶����Ƿ�Ϊ��*/
int QueueEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL) return 1; //�������Ϊ���򷵻�1
	else return 0;
}

/*���������*/
void ClearQueue(LinkQueue* Q)
{
	Q->front->next = NULL;
}

/*����еĳ���*/
int QueueLength(LinkQueue Q)
{
	int i = 0; /*��������0*/
	QueuePtr p = Q.front; /*pָ��ڵ�*/
	while (p != Q.rear) /*p��ָ��Ĳ���β�ڵ�*/
	{
		i++;/*��������1*/
		p = p->next;
	}
	return i;
}

/*�����в��գ�����e���ض�ͷԪ��*/
int GetHead(LinkQueue Q, QElemType* e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return 0;
	p = Q.front->next; /*pָ���ͷ�ڵ�*/
	*e = p->data; /*����ͷԪ�ص�ֵ����e*/
	return 1;
}

/*��������ӡ���У���ͷ����β��*/
void QueueTraverse(LinkQueue Q)
{
	QueuePtr p = Q.front->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/*������*/
int main(void)
{
	int k;
	QElemType d = 0;
	LinkQueue q;

	return 0;
}
