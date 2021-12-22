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
		printf("�밴�ݴε�����˳����������Ԫ��\n");
	for (i = 0;i < n;i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		printf("�������%d���ϵ��: ", i + 1);
		scanf("%d", &s->coefficient);
		printf("�������%d���ָ��: ", i + 1);
		scanf("%d", &s->index);
		p->next = s;
		p = p->next;
	}
	p->next = NULL;
}
void add(LinkList& La, LinkList Lb)//��һԪ����ʽ��Ӳ�����������La��
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
	printf("������һԪ����ʽA(x)��������");
	scanf("%d", &m);
	printf("������һԪ����ʽB(x)��������");
	scanf("%d", &n);
	printf("\n������һԪ����ʽA(x)��\n");
	CreatList(La, m);
	printf("\n������һԪ����ʽB(x)��\n");
	CreatList(Lb, n);
	add(La, Lb);
	printf("\n����ʽ��ӵĽ����:\n");
	for (p = La->next, pa = p->next;pa;p = pa, pa = pa->next)
	{
		printf("%dx^%d+", p->coefficient, p->index);
	}
	printf("%dx^%d", p->coefficient, p->index);
	printf("\n");
	return 0;
}
