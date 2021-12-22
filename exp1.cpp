#include <malloc.h>
#include<stdio.h>
#define INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;


typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList& L, int n)
{
	L.elem = (ElemType*)malloc(n * sizeof(ElemType));
	L.length = 0;
	L.listsize = n;
}
void DestroyList(SqList& L)
{
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
void ClearList(SqList& L)
{
	L.length = 0;
}
int ListInsert(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1) return 0;
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType*  p = &(L.elem[i - 1]);
	for (ElemType*  q = &(L.elem[L.length - 1]); q >= p; --q)
		*(q + 1) = *q;
	*p = e;
	++L.length;
	return 1;
}

int ListDelete(SqList& L, int i, ElemType& e)
{
	if ((i < 1) || (i > L.length)) return 0;
	ElemType*  p = &(L.elem[i - 1]);
	e = *p;
	ElemType*  q = L.elem + L.length - 1;

	for (++p; p <= q; ++p)
		*(p - 1) = *p;

	--L.length;
	return 1;
}

void PrintList(SqList L)
{
	int* p;
	printf("���˳����е�Ԫ��\n");
	for (p = L.elem;p < L.elem + L.length;p++)
	{
		printf("%d\t", *p);
	}
	printf("\n");
}

int Locate(SqList L, int e)
{
	int i;//i��Ų���Ԫ�ص�λ��
	int* p;
	for (i = 1, p = L.elem;p < L.elem + L.length && *p != e;p++)
	{
		i++;
	}
	if (i < L.length)
	{
		return i;
	}
	else
		return 0;
}

void MergeList_Sq(SqList la, SqList lb, SqList& lc)
{ // ��֪˳���La��Lb��Ԫ�ذ�ֵ�ǵݼ����С���P21�㷨2.2����
// �鲢La��Lb�õ��µ�˳�����Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
	ElemType* pa = la.elem;
	ElemType*  pb = lb.elem;
	lc.listsize = lc.length = la.length + lb.length;
	ElemType*  pc = lc.elem = (ElemType*)malloc(sizeof(ElemType) * lc.listsize);
	
	ElemType*  pa_last = la.elem + la.length - 1;
	ElemType*  pb_last = lb.elem + lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) //�鲢
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++; //����la��ʣ��Ԫ��
	while (pb <= pb_last) *pc++ = *pb++; //����lb��ʣ��Ԫ��
}

//�� A=(a1,��,am)�� B=(b1,��,bn)��Ϊ˳���A���� B���ֱ�Ϊ A �� B �г�ȥ���ͬǰ׺����ӱ��Ա�̣���� A,B�Ĵ�С��

void compare(SqList A, SqList B)
{
	int i;
	ElemType* pa, * pb;
	i = 1;
	pa = A.elem;
	pb = B.elem;

	SqList A1;
	SqList B1;
	InitList(A1, 100);
	InitList(B1, 100);
	while (*pa != *pb)
	{
		ListInsert(A1, i, *pa);
		ListInsert(B1, i, *pb);
		pa++;
		pb++;
		i++;
	}
	if (A1.length != 0 || B1.length != 0)
	{
		if (*pa < *pb)
		{
			printf("A<B\n");
		}
		else
		{
			printf("A>B\n");
		}
	}
	else
	{
		printf("A=B\n");
	}
}


void ListInsert2(SqList& L, ElemType n)
{	
	int i = 1;
	ElemType* p = L.elem;
	//��˳����뵽����λ��
	for (;p < L.elem + L.length && *p < n;p++)
	{
		++i;
	}
	ListInsert(L, i,n);
}

void ListDelete2(SqList& L)
{
	int e;
	int i = 1;
	ElemType* p = L.elem;
	//ɾ������Ԫ��
	for (;p < L.elem + L.length;p++, i++)
	{
		if (*(p - 1) == *p)
		{
			ListDelete(L, i,e);
		}
	}
}
int main(void)
{
	int a;
	SqList L;
	InitList(L,100);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 2);
	ListInsert(L, 4, 5);
	ListInsert(L, 5, 6);
	

	
	SqList L2;
	InitList(L2, 100);
	ListInsert(L2, 1, 1);
	ListInsert(L2, 2, 2);
	ListInsert(L2, 3, 2);
	ListInsert(L2, 4, 5);
	ListInsert(L2, 5, 5);

	compare(L, L2);

	


	return 0;

}