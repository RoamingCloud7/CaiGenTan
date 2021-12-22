#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10 /*最大队列长度*/


typedef  int  ElemType;
typedef struct {
    ElemType* base;  /*初始化的动态分配存储空间*/
    int front;       /*头指针,若队列不为空,指向队列头元素*/
    int rear;        /*尾指针,若队列不为空,指向队列尾元素的下一个位置*/
}SqQueue;


int InitQueue(SqQueue Q) {
    Q.base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
   
    Q.front = Q.rear = 0;
    return 1;
}

int EnQueue(SqQueue Q, ElemType * e) 
{
    if ((Q.rear  + 1) % MAXSIZE  == Q.front ) /*判断队列是否满*/
        return 0;  /*队列满*/
    Q.base[Q.rear] = e;   /*  元素e入队  */
    Q.rear  = (Q.rear  + 1) % MAXSIZE; /*  队尾指针向前移动  */
    return 1;      /*  入队成功,返回1  */
}


int OutQueue(SqQueue Q, ElemType * e) {
    if (Q.rear  == Q.front )
        return 0;                      /*队列为空,返回错误*/
    e  = Q.base[Q.front];               /* 取队首元素 */
    Q.front  = (Q.front  + 1) % MAXSIZE;/* 队首指针向前移动 */
    return 1;
}


/*返回Q元素的个数,即队列的长度*/
int QueueLength(SqQueue Q) {
    int i;
    i = (Q.rear - Q.front + MAXSIZE) % MAXSIZE; /*计算队中元素个数*/
    return(i);
}

void PrintQuence(SqQueue Q) {
    int i;
    i = (Q->Front + 1) % MAXSIZE; /*队头加一开始遍历*/
    while (i != Q->rear) {
        printf("%c", Q->base[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("%c", Q->base[i]);       /*队尾*/
    printf("\n");
}

