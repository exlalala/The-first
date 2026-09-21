#include"sqlist.h"

const int LIST_INIT_LISTSIZE = 50;//存储空间初始分配量
const int LISTINCREMENT = 10;	//存储空间分配增量

int main()
{
	SqList La, Lb;
	int A[] = { 12,25,34,78, 88,100 };
	int B[] = { 10,15,25,32,88 };
	int lable;
	La = InitList_Sq(LIST_INIT_LISTSIZE, LISTINCREMENT);
	Lb = InitList_Sq(LIST_INIT_LISTSIZE, LISTINCREMENT);
	lable = CreateList_Sq(La, A, sizeof(A) / sizeof(A[0]));//创建顺序表La
	if (lable) {
		cout << "顺序表La为：" << endl;
		ListTraverse_Sq(La);
	}
	lable = CreateList_Sq(Lb, B, sizeof(B) / sizeof(B[0]));//创建顺序表Lb
	if (lable) {
		cout << "顺序表Lb为：" << endl;
		ListTraverse_Sq(Lb);
	}
	cout << endl;

	cout << "输入在La中要插入的元素X：" << endl;
	ElemType X;
	cin >> X;
	lable = ListInsert_Sq(La, X);//将38插入到La的第loc的位置
	if (lable)
	{
		cout << "插入元素e后后的顺序表La为：" << endl;
		ListTraverse_Sq(La);
	}
	else cout << "插入失败" << endl;

	int K;
	ElemType e = 0;
	cout << "输出在La中删除元素的位序：" << endl << endl;
	cin >> K;
	lable = ListDelete_Sq(La, K, e);//删除顺序表La中第i个元素
	if (lable)
	{
		cout << "La 的第" << K << "个元素是：" << e << endl;
		cout << "删除后的La是：" << endl;
		ListTraverse_Sq(La);
	}
	cout << endl;

	cout << "输入在La中查找的元素" << endl;
	cin >> X;
	int loc = LocateElem_Sq(La, X);//在La中查找元素e
	cout << "查找元素的位置为：" << loc << endl << endl;


	SqList	Lc;
	Lc = MergeList_Sq(La, Lb);//合并La和Lb到Lc，并保留La和Lb
	cout << "合并La和Lb后的顺序表为:" << endl;
	ListTraverse_Sq(Lc);
	cout << endl << endl;


	lable = DestroyList_Sq(La);
	if (lable)cout << "La is released" << endl;

	DestroyList_Sq(Lb);
	if (lable)cout << "Lb is released" << endl;

	DestroyList_Sq(Lc);
	if (lable)cout << "Lc is released" << endl;

	system("pause");
	return OK;
}