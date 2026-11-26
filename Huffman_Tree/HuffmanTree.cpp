#include "head.h"

int main() {
	int n = 8;
	int w[] = { 5,29,7,8,14,23,3,11 };
	char ch[] = { 'a','b','c','d','e','f','g','h' };
	char cd[] = "000110000111001";

	HuffmanTree HT;
	HuffmanCode HC;
	Create(HT,n,w,ch);
	HuffmanCoding(HT, HC, n);

	PrintCode(HC, ch, n);
	PrintDecode(HT, n, cd);

	return 0;
}
