# include <stdio.h>
# include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}LNode, * LinkList;

void CreatList(LinkList& La, int m)//��������m�����ݣ������ν�������Ԫ�ؽ�㣬������뵽����β����������ͷ���ĵ�����La
{
	int i;
	LinkList p, r;
	La = (LinkList)malloc(sizeof(LNode));
	La->next = NULL;
	r = La;
	printf("����������m������Ԫ�أ�\n");
	for (i = 1;i <= m;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
void ListInsert(LinkList& L, int i, ElemType e)//�ڴ�ͷ���ĵ�����L�е�i������Ԫ��֮ǰ��������Ԫ��
{
	LinkList s, p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		printf("iֵ����\n");
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
int ListDelete(LinkList& L, int n, ElemType& e) //ɾ������ĵ�n��Ԫ�أ�����e������ֵ
{
	LinkList q, p = L;
	int j = 0;
	while (p->next && j < n - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > n - 1)
	{
		printf("iֵ����\n");
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return e;
}
int ListLength(LinkList L)//������L�ı�
{
	int i;
	LinkList p;
	p = L;
	for (i = 0;p;i++)
		p = p->next;
	return i - 1;
}

void GetUnionSet(LinkList A, LinkList B, LinkList C)//��A��B����C
{
	LinkList a, b;
	int i;
	a = A->next;
	b = B->next;
	for (i = 0;a || b;i++)
	{
		if (a && b)
		{
			if (a->data == b->data)
			{
				b = b->next;
				i--;
			}
			else if (a->data < b->data)
			{
				ListInsert(C, i + 1, a->data);
				a = a->next;
			}
			else
			{
				ListInsert(C, i + 1, b->data);
				b = b->next;
			}

		}
		else if (a)
		{
			ListInsert(C, i + 1, a->data);
			a = a->next;
		}
		else
		{
			ListInsert(C, i + 1, b->data);
			b = b->next;
		}
	}
}

LinkList MutualAgg(LinkList A, LinkList B) {  // A��B
	LinkList C, pa, pb, pc, qc;
	C = pc = (LNode*)malloc(sizeof(LNode));
	pc->data = 0;
	pa = A->next;
	pb = B;
	while (pa != A) {
		pb = B->next;
		while (pb != B) {
			if (pb->data == pa->data) {
				qc = (LNode*)malloc(sizeof(LNode));
				qc->data = pb->data;
				pc->next = qc;
				pc = qc;
			}
			pb = pb->next;
		}
		pa = pa->next;
	}
	pc->next = C;
	return C;
}



int main()
{
	LinkList L;


	return 0;
}
