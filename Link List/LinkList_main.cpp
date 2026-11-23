#include "LinkList_head.h"

int main() {
	int a[] = { 25,12,78,34,100,88 };
	int b[] = { 88,10,15,25,32 };
	LinkList La;
	LinkList Lb;
	InitList_L(La);
	InitList_L(Lb);
	CreateList(La, a, 6);
	CreateList(Lb, b, 5);

	cout << "单链表La存放数据分别为：";
	OutputList(La);
	cout << "单链表Lb存放数据分别为：";
	OutputList(Lb);
	cout << endl;

	ElemType e; int i;
	cout << "请输入要在La里插入的数据和位置：";
	cin >> e >> i;
	int result=Insert(La, e, i);
	if (result) {
		cout << "插入后：";
		OutputList(La);
	}
	else cout << "插入失败！" << endl;

	ElemType e2; int i2;
	cout << endl << "请输入Lb中要删除的数据的位置：";
	cin >> i2;
	cout << "删除的数据是：" << Delete(Lb, i2) << endl << "删除后的Lb：";
	OutputList(Lb);

	ElemType e3;LNode* goal;
	cout << endl <<  "请输入要在La中查找的数据：";
	cin >> e3;
	goal=SearchNode(La, e3);
	if (!goal)	cout << "未找到！" << endl;
	else    cout << "已找到" << goal->data << endl;

	Merge(La, Lb);
	cout << endl << "合并La和Lb并存入La后:";
	OutputList(La);

	Reverse(La);
	cout << endl << "La逆置后：";
	OutputList(La);

	Destroy(La);

	return OK;
}
