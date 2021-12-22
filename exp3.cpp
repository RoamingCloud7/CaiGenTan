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

void InitStack(SqStack& S)//��ʼ��ջ
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		printf("��ʼ��ջʧ��!\n");
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void Push(SqStack& S, SElemType e)//��ջ
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
			printf("ջ������!\n");
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
}

void Pop(SqStack& S, SElemType& e)//ɾ��ջ��Ԫ�ز���e������ֵ(��ջ)
{
	if (S.top == S.base)
		printf("����ʧ��!\n");
	e = *--S.top;
}

void GetTop(SqStack S, SElemType& e)//ȡջ��Ԫ�ز���e������ֵ
{
	if (!S.base)
		printf("ջ�����ڣ�����ʧ��!\n");
	e = *(S.top - 1);
}

int StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (!S.base)
	{
		printf("ջ������!\n");
		return 0;
	}
	if (S.top == S.base)
	{
		printf("\nջ��!\n");
		return 1;
	}
	
	else
	{
		printf("\nջ����!\n");
		return 0;
	}
}

void VisitStack(SqStack S)//����ջ
{
	int i, * p;
	if (!S.base)
		printf("ջ������!\n");
	for (i = 1, p = S.base;p < S.top;p++)
		printf("��%d��Ԫ��Ϊ%d\n", i++, *p);
	printf("\n");
}

void conversion(SqStack S)
{
	int N, e;
	InitStack(S);
	printf("������һ��ʮ��������:");
	scanf("%d", &N);
	while (N) {
		Push(S, N % 8);
		N = N / 8;
	}
	printf("תΪ�˽���:");
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
	printf("\n");
}

char prior[7][7] = { {'>','>','<','<','<','>','>'},{'>','>','<','<','<','>','>'},{'>','>','>','>','<','>','>'},
				  {'>','>','>','>','<','>','>'},{'<','<','<','<','<','=','!'},{'>','>','>','>','!','>','>'},
				  {'<','<','<','<','<','!','='} };//�������֮�����ȹ�ϵ�Ķ�ά���� 
//ȷ��������ַ�����ǲ������Ļ��ж��ڶ�ά�����е��±� �������ֵĻ�����������������ֿ� ������������ʽʱ�����ĸ�ջ 
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

//�ж����ȼ�,���ش�С < > = !
char Priority(char a, char b) {
	int x, y;
	x = Index(a); y = Index(b);
	if (x != 7 && y != 7)
		return prior[x][y];
	else
		return '!';
}
//�򵥱��ʽ��ֵ
int Reckon(int a, char theta, int b) {
	switch (theta) {
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	}
}
//�ж����ַ��Ƿ�������
int isdigit(char ch) {
	if (ch >= '0' && ch <= '9') return 1;
	return 0;
}
//�������ʽ��ֵ
void GetExpressionValue() {
	SqStack OPTR, OPND;
	SElemType result;//��������� 
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR, '#');//�����������ڲ������ĵ׶�  
	printf("�������������ʽ:\n");
	char c = getchar();

	while (c != '#' || GetTop(OPTR) != '#') {//��*c=='#'&&ջ���ַ�=='#'��ʱ��
		if (isdigit(c)) {//��������ֵĻ�����ת��Ϊ���� Ȼ���������ջ 
			int data[10];
			int i, num;
			i = num = 0;//num��һ���м��� ���ڽ��ַ����е�����ת��Ϊ����Ȼ����ջ i�����ڽ��ַ����е��ַ�����data���� 
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
		else {//������ַ��Ļ������������ջ
			SElemType a, b, theta;//a b theta���������ز�����ջ�Ͳ�����ջ���Ԫ�ص�
			switch (Priority(GetTop(OPTR), c)) {//�Ƚϼ�����ջ���ַ���ջ�� �����������ȼ���ϵ 
			case '<':Push(OPTR, c);
				c = getchar();
				break;
			case '>':Pop(OPND, b);
				Pop(OPND, a);
				Pop(OPTR, theta);
				Push(OPND, Reckon(a, theta, b));
				break;//�������ջ 
			case '=':Pop(OPTR, theta);
				c = getchar();
				break;//˵���������� ɾ��ջ�����ż��� 
			default:break;
			}
		}
	}
	Pop(OPND, result);
	printf("����ǣ�%d", result);
}


int main()
{
	SqStack S;
	int i, n, m;
	SElemType e, out, top;
	InitStack(S);
	printf("��������ջԪ�ظ�����");
	scanf("%d", &n);
	printf("\n");
	for (i = 0;i < n;i++)
	{
		printf("�����%d����ջԪ�أ�", i + 1);
		scanf("%d", &e);
		Push(S, e);
	}
	printf("\n������Ҫ��ջ��Ԫ�ظ�����");
	scanf("%d", &m);
	printf("\n");
	for (i = 0;i < m;i++)
	{
		Pop(S, out);
		printf("��%d����ջԪ��Ϊ:%d\n", i + 1, out);
	}
	GetTop(S, top);
	printf("\n��ǰջ��Ԫ��Ϊ%d\n", top);
	StackEmpty(S);
	printf("\nջ��Ԫ��Ϊ:\n");
	VisitStack(S);
	return 0;
}
