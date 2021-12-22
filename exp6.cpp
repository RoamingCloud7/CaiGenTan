#include <malloc.h>
#include<stdio.h>
#define INIT_SIZE 100
#define LISTINCREMENT 10
typedef int KeyType;

typedef struct {
	KeyType key; //�ؼ�����
	int data; //������
}ElemType;

typedef struct {
	ElemType* elem; // ����Ԫ�ش洢�ռ��ַ������ʱ
	// ��ʵ�ʳ��ȷ��䣬0�ŵ�Ԫ����
	int length; // ��ĳ���
}SSTable;

int Search_Seq(SSTable ST, KeyType key) {
	// ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0��
	ST.elem[0].key = key; // ���ڱ���
	int i = ST.length;
	while (ST.elem[i].key != key) i--; // �Ӻ���ǰ��
	return i; // �Ҳ���ʱ��iΪ0
}

int Search_Bin(SSTable ST, KeyType key) {
	// �������ST���۰������ؼ��ֵ���key������Ԫ�ء�
	// ���ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0��
	int low = 1;
	int high = ST.length; // �������ֵ
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == ST.elem[mid].key)
			return mid; //�ҵ�����Ԫ��
		else if (key < ST.elem[mid].key) high = mid - 1;
		// ������ǰ��������в���
		else low = mid + 1; // �����ں��������в���
	}
	return 0; // ˳����в����ڴ���Ԫ��
}

void BubbleSort(SqList& L)
{ // ð������
	for (i = 1; i <= L.length - 1;i++) //��������
	{
		flag = 0;
		for (j = 1; j <= L.length - i; j++)
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1;
				L.r[j] <--> L.r[j + 1] //����ǰ��������¼
			}
		if (flag == 0) return;
	}
}

int Partition(SqList& L, int low, int high)
{ //��˳���L�е��ӱ� r[low..high]����һ�����򣬷���֧��λ��
	L.r[0] = L.r[low]; // ���ӱ�ĵ�һ����¼��Ϊ֧���¼
	pivotkey = L.r[low].key; // ֧���¼�ؼ���
	while (low < high) { // �ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey) --high;
		L.r[low] = L.r[high]; // ����֧���¼С�ļ�¼�Ƶ��Ͷ�
		while (low < high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low]; // ����֧���¼��ļ�¼�Ƶ��߶�
	}
	L.r[low] = L.r[0]; // ֧���¼��λ
	return low; // ��������λ��
}

void QSort(SqList& L, int low, int high)
{ // ��˳���L�е�������L.r[low..high]����������
	if (low < high) { // ���ȴ���1
		pivotloc = Partition(L, low, high); // ��L.r[low..high]һ��Ϊ��
		QSort(L, low, pivotloc - 1); //�Ե��ӱ�ݹ�����pivotloc��֧��λ��
		QSort(L, pivotloc + 1, high); // �Ը��ӱ�ݹ�����
	}
}



