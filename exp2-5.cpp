# include <stdio.h>
# include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType coefficient;
	ElemType index;
	struct LNode* next;
}LNode, * LinkList;

void CreatList(LinkList& L, int n)
{
	LinkList p, s;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	p = L;
	L->next = NULL;
	if (n != 0)
		printf("请按幂次递增的顺序输入数据元素\n");
	for (i = 0;i < n;i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		printf("请输入第%d项的系数: ", i + 1);
		scanf("%d", &s->coefficient);
		printf("请输入第%d项的指数: ", i + 1);
		scanf("%d", &s->index);
		p->next = s;
		p = p->next;
	}
	p->next = NULL;
}
void add(LinkList& La, LinkList Lb)//将一元多项式相加并将结果存放在La中
{
	LinkList a, b, ha, pb;
	a = La->next;
	b = Lb->next;
	ha = La;
	pb = b->next;
	while (a && b)
	{
		if (a->index == b->index)
		{
			a->coefficient = a->coefficient + b->coefficient;
			ha = a;
			pb = b->next->next;
			a = a->next;
			b = b->next;
		}
		else if (a->index < b->index)
		{
			ha = a;
			a = a->next;
		}
		else
		{
			ha->next = b;
			b->next = a;
			b = pb;
			pb = pb->next;
		}
	}
	if (b)
	{
		ha->next = b;
	}
}
int main()
{
	LinkList La, Lb, p, pa;
	int m, n;
	printf("请输入一元多项式A(x)的项数：");
	scanf("%d", &m);
	printf("请输入一元多项式B(x)的项数：");
	scanf("%d", &n);
	printf("\n请输入一元多项式A(x)：\n");
	CreatList(La, m);
	printf("\n请输入一元多项式B(x)：\n");
	CreatList(Lb, n);
	add(La, Lb);
	printf("\n多项式相加的结果是:\n");
	for (p = La->next, pa = p->next;pa;p = pa, pa = pa->next)
	{
		printf("%dx^%d+", p->coefficient, p->index);
	}
	printf("%dx^%d", p->coefficient, p->index);
	printf("\n");
	return 0;
}
