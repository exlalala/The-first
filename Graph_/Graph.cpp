#include "head.h"

int main() {
	MGraph G;
	ifstream fin1("test.txt");
	CreateMGraph(G, fin1);
	fin1.close();
	coutMatrix_of_MGraph(G);
	BFS_Traverse(G);

	ALGraph T;
	ifstream fin2("test.txt");
	cout << endl;
	CreateALGraph(T, fin2);
	fin2.close();
	DFSTraverse_0(T);
	DFSTraverse_1(T);
	DestroyALGraph(T);

	return 0;
}
