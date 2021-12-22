#include<stdio.h>
#include<stdlib.h>
typedef int QElemType;
/*链队列*/
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

typedef struct
{
	QueuePtr front;          /*队头指针*/
	QueuePtr rear;           /*队尾指针*/
} LinkQueue;

/*初始化一个队列*/
int InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) return 0;/*生成头节点失败*/
	Q->front->next = NULL;
	return 1; //初始化成功则返回1
}

/*销毁队列Q*/
int DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next; /*Q->rear指向Q->front的下一个节点*/
		free(Q->front);/*释放Q->front所指节点*/
		Q->front = Q->rear; /*Q->front指向Q->front的下一个节点*/
	}
	return 1;
}

/*入队：插入元素e为队列Q的新的队尾元素*/
int EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode)); /*动态生成新节点*/
	if (!p) return 0; //生成失败则返回0
	p->data = e; /*将e的值赋给新节点*/
	p->next = NULL; /*新节点的指针为空*/
	Q->rear->next = p; /*原队尾节点的指针域为指向新节点*/
	Q->rear = p; /*尾指针指向新节点*/
	return 1; //入栈成功则返回1
}

/*出队：若队列不为空，删除Q的队头元素，用e返回其值*/
int DeQueue(LinkQueue* Q, QElemType* e)
{
	QueuePtr p;
	if (Q->front == Q->rear) return 0; /*队列为空*/
	p = Q->front->next; /*p指向队头节点*/
	*e = p->data; /*队头元素赋给e*/
	Q->front->next = p->next; /*头节点指向下一个节点*/
	if (Q->rear == p) /*如果删除的队尾节点*/
		Q->rear = Q->front; /*修改队尾指针指向头节点*/
	free(p);
	return 1; //出队成功则返回1
}

/*判断队列是否为空*/
int QueueEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL) return 1; //如果队列为空则返回1
	else return 0;
}

/*将队列清空*/
void ClearQueue(LinkQueue* Q)
{
	Q->front->next = NULL;
}

/*求队列的长度*/
int QueueLength(LinkQueue Q)
{
	int i = 0; /*计数器清0*/
	QueuePtr p = Q.front; /*p指向节点*/
	while (p != Q.rear) /*p所指向的不是尾节点*/
	{
		i++;/*计数器加1*/
		p = p->next;
	}
	return i;
}

/*若队列不空，则用e返回队头元素*/
int GetHead(LinkQueue Q, QElemType* e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return 0;
	p = Q.front->next; /*p指向队头节点*/
	*e = p->data; /*将队头元素的值赋给e*/
	return 1;
}

/*遍历并打印队列（队头到队尾）*/
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

/*主函数*/
int main(void)
{
	int k;
	QElemType d = 0;
	LinkQueue q;

	return 0;
}
