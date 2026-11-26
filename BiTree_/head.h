#pragma once
#include <iostream>
#include <stack>

#define Elemtype char

using namespace std;

typedef struct BiTNode {
	Elemtype data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

void CreateBiTree(BiTree& T, char*& prs) {
	if (*prs == '\0') {
		T = NULL;
		return;
	}
	if (*prs == '#') {
		T = NULL;
		prs++;
		return;
	}
	else {
		T = new BiTNode;
		T->data = *prs++;
		CreateBiTree(T->lchild, prs);
		CreateBiTree(T->rchild, prs);
	}
}

void PreOrder_0(BiTree T) {
	if (!T)	return;
	else {
		cout << T->data << "  ";
		PreOrder_0(T->lchild);
		PreOrder_0(T->rchild);
	}
}

void InOrder_0(BiTree T) {
	if (!T)	return;
	else {
		InOrder_0(T->lchild);
		cout << T->data << "  ";
		InOrder_0(T->rchild);
	}
}

void PostOrder_0(BiTree T) {
	if (!T)	return;
	else {
		PostOrder_0(T->lchild);
		PostOrder_0(T->rchild);
		cout << T->data << "  ";
	}
}

void PreOrder_1(BiTNode* T) {
	if (!T)	return;
	stack<BiTNode*> s;
	BiTNode* p = T;
	while (p != nullptr || !s.empty()) {
		if (p != nullptr) {
			cout << p->data << "  ";
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void InOrder_1(BiTNode* T) {
	if (!T)	return;
	stack<BiTNode*> s;
	BiTNode* p = T;
	while (p != nullptr || !s.empty()) {
		if (p != nullptr) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			s.pop();
			cout << p->data << "  ";
			p = p->rchild;
		}
	}
}

void PostOrder_1(BiTNode* T) {
	if (!T)	return;
	stack<BiTNode*> s;
	BiTNode* p = T;
	BiTNode* pre = nullptr;
	while (p != nullptr || !s.empty()) {
		while (p != nullptr) {
			s.push(p);
			p = p->lchild;
		}
		BiTNode* TopNode = s.top();
		if (TopNode->rchild != nullptr && TopNode->rchild!=pre) {
			p = TopNode->rchild;
		}
		else {
			cout << TopNode->data << "  ";
			s.pop();
			pre = TopNode;
			TopNode = NULL;
		}
	}
}
