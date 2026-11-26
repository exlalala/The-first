#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

typedef int InfoType;
typedef int VRType;
typedef char VertexType;
#define MaxVerxNum 20
#define maxsize 100

typedef struct ArcCell {
	VRType adj;
	InfoType* info;
}ArcCell,AdjMatrix[MaxVerxNum][MaxVerxNum];

typedef struct {
	VertexType vexs[MaxVerxNum];
	AdjMatrix arcs;
	int vexnum, arcnum;
}MGraph;

int Locate_in_MGraph(MGraph G, VertexType v) {
	for (int i = 0;i < G.vexnum;i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

void CreateMGraph(MGraph &G,ifstream& fin) {
	cout << "请输入该图的顶点数和边数：" << endl;
	fin >> G.vexnum >> G.arcnum;
	cout << "顶点数：" << G.vexnum << "    " << "边数：" << G.arcnum;
	cout << endl<< "图的顶点分别是：";
	for (int i = 0;i < G.vexnum;i++) {
		fin >> G.vexs[i];
		cout << G.vexs[i] << "   ";
	}
	cout << endl;

	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
			G.arcs[i][j].adj  = 0;
			G.arcs[i][j].info = NULL;
		}
	}

	cout << "输入存在边的两个顶点：" << endl;
	for (int i = 0;i < G.arcnum;i++) {
		VertexType v1, v2;
		fin >> v1 >> v2;
		int index1 = Locate_in_MGraph(G, v1);
		int index2 = Locate_in_MGraph(G, v2);

		if (index1 == -1 || index2 == -1) {
			cout << "ERROR!!!" << endl;
			continue;
		}

		G.arcs[index1][index2].adj = 1;
	}
}

void coutMatrix_of_MGraph(MGraph G) {
	cout << "该图对应的邻接矩阵为：" << endl;
	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
			cout << G.arcs[i][j].adj << "  ";
		}
		cout << endl;
	}
}

void BFS_Traverse(MGraph G) {
	cout << "按广度优先非递归遍历：" << endl;
	int* visited;
	visited = new int[G.vexnum];
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = 0;
	}

	queue<VertexType> Q;
	int tree_count = 0;
	for (int i = 0;i < G.vexnum;i++) {
		if (visited[i] == 0) {
			tree_count++;
			visited[i] = 1;
			Q.push(G.vexs[i]);
			while (!Q.empty()) {
				int index = Locate_in_MGraph(G, Q.front());
				cout << Q.front() << "  ";
				Q.pop();
				for (int j = 0;j < G.vexnum;j++) {
					if (G.arcs[index][j].adj == 1&&visited[j]==0) {
						visited[j] = 1;
						Q.push(G.vexs[j]);
					}
				}
			}
		}
	}
	delete[] visited;
	cout << endl << "有向树的个数为：" << tree_count << endl;
}

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	InfoType* info;
}ArcNode;

typedef struct VNode {
	VertexType data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVerxNum];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int Locate_in_ALGraph(ALGraph T, VertexType v) {
	for (int i = 0;i < T.vexnum;i++) {
		if (T.vertices[i].data == v)	return i;
	}
	return -1;
}

void CreateALGraph(ALGraph& T, ifstream& fin) {
	cout << "请输入该图的顶点数和边数：" << endl;
	fin >> T.vexnum >> T.arcnum;
	cout << "顶点数：" << T.vexnum << "    " << "边数：" << T.arcnum;
	cout << endl << "图的顶点分别是：";
	for (int i = 0;i < T.vexnum;i++) {
		fin >> T.vertices[i].data;
		T.vertices[i].firstarc = NULL;
		cout << T.vertices[i].data << "   ";
	}
	cout << endl;

	ArcNode* p;
	cout << "输入存在边的两个顶点：" << endl;
	for (int i = 0;i < T.arcnum;i++) {
		VertexType v1, v2;
		fin >> v1 >> v2;
		int index1 = Locate_in_ALGraph(T, v1);
		int index2 = Locate_in_ALGraph(T, v2);

		if (index1 == -1 || index2 == -1) {
			cout << "ERROR!!!" << endl;
			continue;
		}

		p = new struct ArcNode;
		p->adjvex = index2;
		p->info = NULL;
		p->nextarc = T.vertices[index1].firstarc;
		T.vertices[index1].firstarc = p;
	}
}

void DFSTraverse_0(ALGraph T) {
	cout << "按深度优先非递归遍历：" << endl;
	stack<int> s;
	int tree_count = 0;

	int* visited = new int[T.vexnum];
	for (int i = 0;i < T.vexnum;i++) {
		visited[i] = 0;
	}

	for (int i = 0;i < T.vexnum;i++) {
		if (visited[i] == 0) {
			tree_count++;
			s.push(i);
			visited[i] = 1; 

			while (!s.empty()) {
				int temp = s.top();
				s.pop();
				cout << T.vertices[temp].data << "  ";
				int arr[MaxVerxNum], cnt = 0;
				ArcNode* p = T.vertices[temp].firstarc;
				while (p != NULL) {
					if (visited[p->adjvex] == 0) {
						arr[cnt++] = p->adjvex;
					}
					p = p->nextarc;
				}
				for (int j = cnt - 1; j >= 0; j--) {
					if (visited[arr[j]] == 0) {
						s.push(arr[j]);
						visited[arr[j]] = 1;
					}
				}
			}
		}
	}
	cout << endl << "有向树的个数为: " << tree_count << endl << endl;
	delete[] visited;
}

void DFS(ALGraph T, int v, int visited[]) {
	visited[v] = 1;
	cout << T.vertices[v].data << "  ";
	for (ArcNode* p = T.vertices[v].firstarc; p != NULL; p = p->nextarc) {
		if (visited[p->adjvex] == 0) {
			DFS(T, p->adjvex, visited);
		}
	}
}

void DFSTraverse_1(ALGraph T) {
	cout << "按深度优先递归遍历：" << endl;
	int visited[MaxVerxNum];
	for (int i = 0; i < T.vexnum; i++) visited[i] = 0;
	int tree_count = 0;
	for (int i = 0; i < T.vexnum; i++) {
		if (visited[i] == 0) {
			tree_count++;
			DFS(T, i, visited);
		}
	}
	cout << endl << "有向树的个数为: " << tree_count << endl;
}

void DestroyALGraph(ALGraph& T) {
	for (int i = 0; i < T.vexnum; i++) {
		ArcNode* p = T.vertices[i].firstarc;
		while (p != NULL) {
			ArcNode* next = p->nextarc;
			delete p;
			p = next;
		}
		T.vertices[i].firstarc = NULL;
	}
}