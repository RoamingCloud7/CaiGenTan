#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 50
#define STACKINCREMENT 10

typedef int SElemType;
typedef struct
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

void InitStack(SqStack& S)//初始化栈
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		printf("初始化栈失败!\n");
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void Push(SqStack& S, SElemType e)//入栈
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
			printf("栈不存在!\n");
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
}

void Pop(SqStack& S, SElemType& e)//删除栈顶元素并用e返回其值(出栈)
{
	if (S.top == S.base)
		printf("操作失败!\n");
	e = *--S.top;
}

void GetTop(SqStack S, SElemType& e)//取栈顶元素并用e返回其值
{
	if (!S.base)
		printf("栈不存在，操作失败!\n");
	e = *(S.top - 1);
}

int StackEmpty(SqStack S)//判断栈是否为空
{
	if (!S.base)
	{
		printf("栈不存在!\n");
		return 0;
	}
	if (S.top == S.base)
	{
		printf("\n栈空!\n");
		return 1;
	}
	
	else
	{
		printf("\n栈不空!\n");
		return 0;
	}
}

void VisitStack(SqStack S)//遍历栈
{
	int i, * p;
	if (!S.base)
		printf("栈不存在!\n");
	for (i = 1, p = S.base;p < S.top;p++)
		printf("第%d个元素为%d\n", i++, *p);
	printf("\n");
}

void conversion(SqStack S)
{
	int N, e;
	InitStack(S);
	printf("请输入一个十进制整数:");
	scanf("%d", &N);
	while (N) {
		Push(S, N % 8);
		N = N / 8;
	}
	printf("转为八进制:");
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
	printf("\n");
}

char prior[7][7] = { {'>','>','<','<','<','>','>'},{'>','>','<','<','<','>','>'},{'>','>','>','>','<','>','>'},
				  {'>','>','>','>','<','>','>'},{'<','<','<','<','<','=','!'},{'>','>','>','>','!','>','>'},
				  {'<','<','<','<','<','!','='} };//定义算符之间优先关系的二维数组 
//确定输入的字符如果是操作符的话判断在二维数组中的下标 若是数字的话就另外与操作符区分开 便于在输入表达式时是入哪个栈 
int Index(char c) {
	switch (c) {
	case '+': return 0;
	case '-': return 1;
	case '*': return 2;
	case '/': return 3;
	case '(': return 4;
	case ')': return 5;
	case '#': return 6;
	default:  return 7;
	}
}

//判断优先级,返回大小 < > = !
char Priority(char a, char b) {
	int x, y;
	x = Index(a); y = Index(b);
	if (x != 7 && y != 7)
		return prior[x][y];
	else
		return '!';
}
//简单表达式求值
int Reckon(int a, char theta, int b) {
	switch (theta) {
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	}
}
//判断是字符是否是数字
int isdigit(char ch) {
	if (ch >= '0' && ch <= '9') return 1;
	return 0;
}
//算术表达式求值
void GetExpressionValue() {
	SqStack OPTR, OPND;
	SElemType result;//返回最后结果 
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR, '#');//将结束符置于操作符的底端  
	printf("请输入算术表达式:\n");
	char c = getchar();

	while (c != '#' || GetTop(OPTR) != '#') {//当*c=='#'&&栈顶字符=='#'的时候
		if (isdigit(c)) {//如果是数字的话将其转化为数字 然后入操作数栈 
			int data[10];
			int i, num;
			i = num = 0;//num是一个中间数 用于将字符串中的数字转化为整数然后入栈 i是用于将字符串中的字符存入data数组 
			while (isdigit(c)) {
				data[i] = c - '0';
				i++;
				c = getchar();
			}
			for (int j = 0;j < i;j++) {
				num = num * 10 + data[j];
			}
			Push(OPND, num);
		}
		else {//如果是字符的话将其入操作符栈
			SElemType a, b, theta;//a b theta是用来返回操作数栈和操作符栈里的元素的
			switch (Priority(GetTop(OPTR), c)) {//比较即将入栈的字符与栈顶 操作符的优先级关系 
			case '<':Push(OPTR, c);
				c = getchar();
				break;
			case '>':Pop(OPND, b);
				Pop(OPND, a);
				Pop(OPTR, theta);
				Push(OPND, Reckon(a, theta, b));
				break;//将结果入栈 
			case '=':Pop(OPTR, theta);
				c = getchar();
				break;//说明括号相遇 删除栈内括号即可 
			default:break;
			}
		}
	}
	Pop(OPND, result);
	printf("结果是：%d", result);
}


int main()
{
	SqStack S;
	int i, n, m;
	SElemType e, out, top;
	InitStack(S);
	printf("请输入入栈元素个数：");
	scanf("%d", &n);
	printf("\n");
	for (i = 0;i < n;i++)
	{
		printf("输入第%d个入栈元素：", i + 1);
		scanf("%d", &e);
		Push(S, e);
	}
	printf("\n请输入要出栈的元素个数：");
	scanf("%d", &m);
	printf("\n");
	for (i = 0;i < m;i++)
	{
		Pop(S, out);
		printf("第%d个出栈元素为:%d\n", i + 1, out);
	}
	GetTop(S, top);
	printf("\n当前栈顶元素为%d\n", top);
	StackEmpty(S);
	printf("\n栈中元素为:\n");
	VisitStack(S);
	return 0;
}
