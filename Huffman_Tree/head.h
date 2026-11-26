#pragma once
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

typedef struct {
	int weight;
	char data;
	int parent, lchild, rchild;
}HTNode;

typedef HTNode *HuffmanTree;
typedef char** HuffmanCode;

void Select(HuffmanTree HT, int n, int& min1, int& min2) {
	if (!HT) return;
	int i = 1;
	min1 = min2=0;
	for (;i <= n;i++) {
		if (HT[i].parent)	continue;
		else {
			if (HT[i].weight < HT[min1].weight) {
				min2 = min1;
				min1 = i;
			}
			else if (HT[i].weight < HT[min2].weight) {
				min2 = i;
			}
		}
	}
}

void Create(HuffmanTree& HT, int n, int w[], char ch[]) {
	if (n <= 1) return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	HT[0] = { INT_MAX, '\0', 1, 0, 0 };
	for (int i = 1;i <= n;i++) {
		HT[i] = { w[i - 1],ch[i - 1],0,0,0 };
	}
	for (int i = n+1;i <= m;i++) {
		HT[i] = { 0,0,0,0,0 };
	}
	int min1, min2;
	for (int i = n + 1;i <= m;i++) {
		Select(HT, i-1, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC,int n) {
	if (!HT) return;
	HC = new char*[n + 1];
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1;i <= n;i++) {
		int start = n - 1;
		for (int c = i, f = HT[i].parent;f != 0;c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = new char[n - start + 1];
		strcpy_s(HC[i], n - start + 1, &cd[start]);
	}
	delete[] cd;
}

void Decoding(HuffmanTree HT, int n, char* cd) {
	if (!HT) return;
	int m = 2 * n - 1;
	int p = m;
	if (p == 0)	return;
	for (int i = 0;cd[i] != '\0';i++) {
		if (cd[i] == '0') p = HT[p].lchild;
		else p = HT[p].rchild;
		if (HT[p].lchild == 0 && HT[p].rchild == 0) {
			cout << HT[p].data;
			p = m;
		}
	}
}

void PrintCode(HuffmanCode HC, char ch[],int n) {
	cout << "各字符的编码:" << endl;
	for (int i = 1;i <= n;i++) {
		cout << ch[i - 1] << ":" << HC[i] << endl;
	}
}

void PrintDecode(HuffmanTree HT,int n,char cd[]) {
	cout << endl << "指定编码的译码为：" << endl;
	Decoding(HT, n, cd);
	cout << endl;
}