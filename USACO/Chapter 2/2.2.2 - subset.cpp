/*
  ID   : 900831f1
  PROG : subset
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
const int N = 1600;
const char * iFileName = "subset.in";
const char * oFileName = "subset.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
LL dp[N];
int main() {
	int n;
	fscanf(fin, "%d", &n);
	int m = n * (n + 1) / 2;
	dp[0] = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = m;j >= i;j--) {
			dp[j] += dp[j - i];
		}
	}
	if(m & 1) {
		fprintf(fout, "%d\n", 0);
	} else {
		fprintf(fout, "%lld\n", dp[m / 2] / 2);
	}
	return 0;
}
