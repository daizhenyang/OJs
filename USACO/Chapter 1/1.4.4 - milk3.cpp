/*
  ID   : 900831f1
  PROG : milk3
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cctype>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "milk3.in";
const char * oFileName = "milk3.out";
const int N = 21;
int dp[N][N][N];

void dfs(int A, int B, int C, int maxA, int maxB, int maxC) {
	if(dp[A][B][C]) {
		return ;
	}
	dp[A][B][C] = 1;
	int curV[3] = {A, B, C};
	int maxV[3] = {maxA, maxB, maxC};
	for(int i = 0;i < 3;i++) { // from
		for(int j = 0;j < 3;j++) { // to
			if(i == j) continue;
			int nxtV[3] = {A, B, C};
			int maxMove = min(maxV[j] - curV[j], curV[i]);
			nxtV[i]    -= maxMove;
			nxtV[j]    += maxMove;
			if(maxMove) {
				dfs(nxtV[0], nxtV[1], nxtV[2], maxA, maxB, maxC);
			}
		}
	}
}
int main() {
	FILE * fin  = fopen(iFileName, "r");
	FILE * fout = fopen(oFileName, "w");
	int A, B, C;
	fscanf(fin, "%d %d %d", &A, &B, &C);
	memset(dp, 0, sizeof(dp));
	dfs(0, 0, C, A, B, C);
	vector<int> res;
	for(int i = 0;i <= C;i++) {
		if(dp[0][C - i][i]) res.push_back(i);
	}
	int n = res.size();
	for(int i = 0;i < n;i++) {
		fprintf(fout, "%d%c", res[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
