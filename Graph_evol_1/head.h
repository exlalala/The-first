#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef int InfoType;
typedef int VRType;
typedef char VertexType;
#define MaxVerxNum 20
#define maxsize 100

typedef struct ArcCell {
	int weight;
}ArcCell, AdjMatrix[MaxVerxNum][MaxVerxNum];

typedef struct {
	char** vexs;
	AdjMatrix arcs;
	int vexnum, arcnum;
}UnDiGraph;

void CreateGraph(UnDiGraph& G, ifstream& fin) {
	fin >> G.vexnum >> G.arcnum;
	G.vexs = new char* [G.vexnum];
	for (int i = 0; i < G.vexnum; i++) {
		char temp[maxsize];
		fin.getline(temp, maxsize, ',');
		int len = (int)strlen(temp);
		G.vexs[i] = new char[len + 1];
		strcpy_s(G.vexs[i], len + 1, temp);
	}
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j].weight = 0;
		}
	}

	for (int i = 0; i < G.arcnum; i++) {
		int index1, index2, curr_weight;
		fin >> index1 >> index2 >> curr_weight;
		G.arcs[index1][index2].weight = curr_weight;
	}
}

typedef struct Edge {
	int begin, end;
	int weight;
}Edge;

void EdgeValue(UnDiGraph G, Edge* A) {
	int count = 0;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			if (i < j) {
				if (G.arcs[i][j].weight != 0) {
					A[count].begin = i;
					A[count].end = j;
					A[count].weight = G.arcs[i][j].weight;
					count++;
				}
			}
		}
	}
}

void EdgeSort(UnDiGraph G, Edge* A) {
	for (int i = 0;i < G.arcnum;i++) {
		for (int j = i + 1;j < G.arcnum;j++) {
			if (A[i].weight > A[j].weight) {
				Edge temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

int FindRoot(int *parent,int x) {
	if (parent[x] != x) {
		parent[x] = FindRoot(parent, parent[x]);
	}
	return parent[x];
}

void PrintMST(UnDiGraph G) {
	Edge A[maxsize];
	EdgeValue(G, A);
	EdgeSort(G, A);
	int parent[maxsize];
	for (int i = 0;i < G.vexnum;i++) {
		parent[i] = i;
	}
	int used = 0;
	for (int i = 0;i < G.arcnum && used < G.vexnum - 1 ;i++) {
		int parent1 = FindRoot(parent, A[i].begin);
		int parent2 = FindRoot(parent, A[i].end);
		if (parent1 != parent2) {
			parent[parent2] = parent1;
			cout << "(" << G.vexs[A[i].begin] << "," << G.vexs[A[i].end] << ")" << "  " << A[i].weight << endl;
			used++;
		}
	}
}