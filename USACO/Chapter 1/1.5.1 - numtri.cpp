/*
  ID   : 900831f1
  PROG : numtri
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cctype>
#include <map>
#include <cassert>
#include <queue>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "numtri.in";
const char * oFileName = "numtri.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
const int N = 1000;
int num[N][N], dp[N][N];
int main() {
	int n;
	fscanf(fin, "%d", &n);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j <= i;j++) {
			fscanf(fin, "%d", &num[i][j]);
		}
	}
	for(int i = n - 1;i >= 0;i--) {
		for(int j = 0;j <= i;j++) {
			dp[i][j] = num[i][j];
			if(i + 1 < n)
				dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	fprintf(fout, "%d\n", dp[0][0]);
	return 0;
}
