#include "head.h"

int main() {
	UnDiGraph G;
	ifstream fin("D:\\作业\\数据结构\\实验11-图进阶？\\Kruskal.txt");
	CreateGraph(G, fin);
	PrintMST(G);

	return 0;
}