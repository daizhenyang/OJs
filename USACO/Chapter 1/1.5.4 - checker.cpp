/*
  ID   : 900831f1
  PROG : checker
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "checker.in";
const char * oFileName = "checker.out";
typedef long long LL;
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
const int ROW = 13 * 13, COL = 13 * 6;
const int INF = 100000000;
const int N = ROW * COL;

inline int rowID(int i, int j, int n) {
	return i;
}
inline int colID(int i, int j, int n) {
	return j;
}
inline int rightID(int i, int j, int n) {
	return (i - j + n - 1);
}
inline int leftID(int i, int j, int n) {
	return i + j;
}

vector<vector<int> > result;
int ans[N], n, totsize = 0;
void dfs(int curDepth, int maxDepth, int row, int col, int lt, int rt) {
	if(curDepth == maxDepth) {
		totsize++;
		if(totsize < 4) {
			result.push_back(vector<int>(ans, ans + maxDepth));
		}
		return;
	}
	for(int i = 0;i < n;i++) {
		int addRow = 1 << rowID(curDepth, i, n);
		int addCol = 1 << colID(curDepth, i, n);
		int addLt  = 1 << leftID(curDepth, i, n);
		int addRt  = 1 << rightID(curDepth, i, n);
		if((row & addRow) || (col & addCol) || (lt & addLt) || (rt & addRt)) continue;
		ans[curDepth] = i + 1;
		dfs(curDepth + 1, maxDepth, addRow | row, addCol | col, addLt | lt, addRt | rt);
	}
}
int main() {
	fscanf(fin, "%d", &n);
	dfs(0, n, 0, 0, 0, 0);
	sort(result.begin(), result.end());
	for(int i = 0;i < int(result.size());i++) {
		for(int j = 0;j < n;j++) {
			fprintf(fout, "%d%c", result[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	fprintf(fout, "%u\n", totsize);
	return 0;
}
