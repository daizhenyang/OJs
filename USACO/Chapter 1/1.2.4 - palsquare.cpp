/*
  ID   : 900831f1
  PROG : palsquare
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 301;
const char letter[] = "0123456789ABCDEFGHIJKLMN";
int ten2n(int base, int num, char * each) {
	int n = 0;
	while(num) {
		each[n++] = letter[num % base];
		num /= base;
	}
	reverse(each, each + n);
	each[n] = 0;
	return n;
}
bool judge(char * each, int n) {
	for(int i = 0;i < n / 2;i++) {
		if(each[i] != each[n - i - 1])
			return false;
	}
	return true;
}
int main() {
	int base;
	char each1[N], each2[N];
	FILE * fin  = fopen("palsquare.in", "r");
	FILE * fout = fopen("palsquare.out", "w");
	fscanf(fin, "%d", &base);
	for(int i = 1;i < N;i++) {
		int d = i * i;
		int n1 = ten2n(base, i, each1);
		int n2 = ten2n(base, d, each2);
		if(judge(each2, n2)) {
			fprintf(fout, "%s %s\n", each1, each2);
		}
	}
	return 0;
}
