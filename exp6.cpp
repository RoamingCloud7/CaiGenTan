#include <malloc.h>
#include<stdio.h>
#define INIT_SIZE 100
#define LISTINCREMENT 10
typedef int KeyType;

typedef struct {
	KeyType key; //关键字域
	int data; //其它域
}ElemType;

typedef struct {
	ElemType* elem; // 数据元素存储空间基址，建表时
	// 按实际长度分配，0号单元留空
	int length; // 表的长度
}SSTable;

int Search_Seq(SSTable ST, KeyType key) {
	// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0。
	ST.elem[0].key = key; // “哨兵”
	int i = ST.length;
	while (ST.elem[i].key != key) i--; // 从后往前找
	return i; // 找不到时，i为0
}

int Search_Bin(SSTable ST, KeyType key) {
	// 在有序表ST中折半查找其关键字等于key的数据元素。
	// 若找到，则函数值为该元素在表中的位置，否则为0。
	int low = 1;
	int high = ST.length; // 置区间初值
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == ST.elem[mid].key)
			return mid; //找到待查元素
		else if (key < ST.elem[mid].key) high = mid - 1;
		// 继续在前半区间进行查找
		else low = mid + 1; // 继续在后半区间进行查找
	}
	return 0; // 顺序表中不存在待查元素
}

void BubbleSort(SqList& L)
{ // 冒泡排序
	for (i = 1; i <= L.length - 1;i++) //排序趟数
	{
		flag = 0;
		for (j = 1; j <= L.length - i; j++)
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1;
				L.r[j] <--> L.r[j + 1] //交换前后两个记录
			}
		if (flag == 0) return;
	}
}

int Partition(SqList& L, int low, int high)
{ //对顺序表L中的子表 r[low..high]进行一趟排序，返回支点位置
	L.r[0] = L.r[low]; // 用子表的第一个记录作为支点记录
	pivotkey = L.r[low].key; // 支点记录关键字
	while (low < high) { // 从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey) --high;
		L.r[low] = L.r[high]; // 将比支点记录小的记录移到低端
		while (low < high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low]; // 将比支点记录大的记录移到高端
	}
	L.r[low] = L.r[0]; // 支点记录到位
	return low; // 返回枢轴位置
}

void QSort(SqList& L, int low, int high)
{ // 对顺序表L中的子序列L.r[low..high]作快速排序
	if (low < high) { // 长度大于1
		pivotloc = Partition(L, low, high); // 将L.r[low..high]一分为二
		QSort(L, low, pivotloc - 1); //对低子表递归排序，pivotloc是支点位置
		QSort(L, pivotloc + 1, high); // 对高子表递归排序
	}
}



