#include "head.h"

int main() {
	char prs[] = "AB#D##CE###";
	char* p = prs;
	BiTree T;
	CreateBiTree(T, p);
	cout << "递归方法遍历：" << endl;
	cout << "先序：" << endl;
	PreOrder_0(T);
	cout << endl << "中序：" << endl;
	InOrder_0(T);
	cout << endl << "后序：" << endl;
	PostOrder_0(T);

	cout << endl << endl << "非递归方法遍历：" << endl;
	cout << "先序：" << endl;
	PreOrder_1(T);
	cout << endl << "中序：" << endl;
	InOrder_1(T);
	cout << endl << "后序：" << endl;
	PostOrder_1(T);
	return 0;
}