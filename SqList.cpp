#include  <stdio.h> 
#include <malloc.h>
#define MaxSize 100

typedef int status;
typedef int ElemType;

typedef struct {
	int data[MaxSize];
	int length;
}SqList;

//初始化 
status InitList(SqList* L) {
	L->length = 0;
	return 1;
}

//按位查找 
status GetElem(SqList* L, int i, ElemType* e) {
	if (i<1 || i>L->length) return 0;
	*e = L->data[i - 1];                           //elem[i-1]单元存储第i个数据元素 
	return 1;
}

//按值查找 
status LocateElem(SqList* L, ElemType e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) return i + 1;          //查找成功，返回i+1 
	}
	return 0;                                  //查找失败，返回0 
}

//插入 
status ListInsert(SqList* L, int i, ElemType e) {
	if (i<1 || i>L->length + 1) return 0;
	if (L->length == MaxSize) return 0;
	for (int j = L->length - 1; j > i - 1; j--) {
		L->data[j + 1] = L->data[j];               //插入位置及之后的元素后移（L->data[j-1]=L->data[j];） 
	}
	L->data[i - 1] = e;                            //将元素e放入第i个位置 
	L->length++;                               //表长加1 
	return 1;
}

//删除 
status ListDelete(SqList* L, int i) {
	if (i<1 || i>L->length) return 0;
	for (int j = i; j > L->length - 1; j++) {
		L->data[j - 1] = L->data[j];               //被删除元素前移 
	}
	L->length--;                               //表长减1 
	return 1;
}

//判断表是否为空 
status EmptyList(SqList* L) {
	return L->length == 0;
}

//显示 
void DisList(SqList* L) {
	printf("顺序表元素：");
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//销毁 
int DestroyList(SqList* L) {
	L->length = 0;
	for (int i = 0; i < MaxSize; i++) {
		L->data[i] = 0;
	}
	return 1;
}

int main() {
	SqList L;
	ElemType e;

	printf("1.初始化顺序表：");
	if (InitList(&L)) printf("初始化成功！\n");

	printf("2.顺序表为\"%s\"\n", EmptyList(&L) ? "空" : "非空");

	printf("3.插入元素:\n");
	ListInsert(&L, 1, 10);
	ListInsert(&L, 2, 20);
	ListInsert(&L, 3, 30);
	ListInsert(&L, 4, 40);
	ListInsert(&L, 5, 50);
	DisList(&L);

	printf("4.删除元素:\n");
	ListDelete(&L, 3);
	DisList(&L);

	printf("5.查找元素的值:\n");
	if (GetElem(&L, 2, &e)) {
		printf("第2个元素是%d\n", e);
	}

	printf("6.查找元素的位置:%d\n", LocateElem(&L, 40));

	printf("7.销毁顺序表：");
	if (DestroyList(&L)) printf("销毁成功！\n");

	return 0;
}