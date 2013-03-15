/*
  ID   : 900831f1
  PROG : dualpal
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
	int n, s, cnt = 0;
	char each[N];
	FILE * fin  = fopen("dualpal.in", "r");
	FILE * fout = fopen("dualpal.out", "w");
	fscanf(fin, "%d %d", &n, &s);
	for(int i = s + 1;cnt < n;i++) {
		int valid = 0;
		for(int base = 2;base <= 10;base++) {
			int length = ten2n(base, i, each);
			valid += judge(each, length);
		}
		if(valid >= 2) {
			cnt++;
			fprintf(fout, "%d\n", i);
		}
	}
	return 0;
}
