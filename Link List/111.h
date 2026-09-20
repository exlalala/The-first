#pragma once
#include <iostream>
using namespace std;
#include <iomanip>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}; LNode;
typedef LNode* LinkList;

int InitList_L(LinkList& L) {
	L = new LNode;
	if (!L)	return ERROR;
	L->next = NULL;
	return OK;
}

int CreateList(LinkList& L, ElemType A[], int n) {
	if (!L || n < 0)	return ERROR;
	if (n == 0)	return OK;
	for (n--; n >= 0; n--) {
		LinkList s = new LNode;
		s->data = A[n];
		s->next = L->next;
		L->next = s;
	}
	return OK;
}

void OutputList(LinkList L) {
	if (!L)	return;
	while (L->next) {
		cout << L->next->data << "  ";
		L = L->next;
	}
	cout << endl;
}

int Insert(LinkList& L, ElemType e, int i) {
	if (!L || i < 1)	return ERROR;
	LinkList s = new LNode;
	s->data = e;
	int count = 1;
	LinkList L2 = L;
	while (L2->next && count < i) {
		L2 = L2->next;
		count++;
	}
	s->next = L2->next;
	L2->next = s;
	return OK;
}

int Delete(LinkList& L, int i) {
	if (!L || i < 0)	return ERROR;
	int count = 1;
	LinkList L2 = L;
	while (L2->next && count < i) {
		L2 = L2->next;
		count++;
	}
	if (!L2->next)	return ERROR;
	ElemType e = L2->next->data;
	L2->next = L2->next->next;
	return e;
}

LNode* SearchNode(LinkList L, ElemType e) {
	if (!L)	return nullptr;
	LNode* p = L->next;
	while (p) {
		if (p->data == e)	return p;
		p = p->next;
	}
	return nullptr;

}

void Merge(LinkList& La, LinkList& Lb) {
	if (!La || !Lb)	return;
	LNode* pa , * pb = Lb->next;
	while (pb) {
		pa = La->next;
		LNode* pre_pa = La;
		while (pa && pb->data != pa->data) {
			pre_pa = pa;
			pa = pa->next;
		}
		if (!pa) {
			LNode* temp = pb;
			pb = pb->next;      //位置很重要！！
			temp->next = pre_pa->next;
			pre_pa->next = temp;
		}
		else {
			LNode* del_pb = pb;
			pb = pb->next;
			delete del_pb;
		}
	}
	delete Lb;
	Lb = nullptr;
}

void Reverse(LinkList& L) {
	if (!L->next || !L->next->next)	return;
	LNode* s, * p;
	p = L->next->next;
	L->next->next = NULL;
	while (p) {
		s = p;
		p = p->next;
		s->next = L->next;
		L->next = s;
	}
}

void Destroy(LinkList& L)
{
	LNode* p = L, * q;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	L = nullptr;
}