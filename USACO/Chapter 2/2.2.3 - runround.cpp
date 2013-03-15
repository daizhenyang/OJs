/*
  ID   : 900831f1
  PROG : runround
  LANG : C++
*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
typedef long long LL;
const int N = 256;
const char * iFileName = "runround.in";
const char * oFileName = "runround.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
char buf[N];
bool unique(int n) {
	sprintf(buf, "%d", n);
	int length = strlen(buf);
	sort(buf, buf + length);
	for(int i = 1;i < length;i++) {
		if(buf[i] == buf[i - 1]) {
			return false;
		}
	}
	return true;
}
bool around(int n) {
	sprintf(buf, "%d", n);
	int length = strlen(buf);
	string str = "";
	for(int i = 0;i < 10;i++) {
		str.append(buf);
	}
	int cnt[N] = {0, };
	for(int i = 0, pos = 0;i < length;i++) {
		pos += str[pos] - '0';
		cnt[str[pos]]++;
		if(cnt[str[pos]] != 1) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	fscanf(fin, "%d", &n);
	do {
		n++;
	} while(!(unique(n) && around(n)));
	fprintf(fout, "%d\n", n);
	return 0;
}
