/*
  ID   : 900831f1
  PROG : hamming
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "hamming.in";
const char * oFileName = "hamming.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef long long LL;
const int N = 1 << 8;
const int M = 64;
int dist[N][N], result[M];
int lowbit(int x) {
	return x & (-x);
}

int countbit(int x) {
	int result = 0;
	while(x != 0) {
		x ^= lowbit(x);
		result++;
	}
	return result;
}
int n, b, d;
bool judge(int val, int depth) {
	for(int i = 0;i < depth;i++) {
		if(dist[val][result[i]] < d) {
			return false;
		}	
	}
	return true;
}
bool dfs(int val, int maxn, int depth) {
	if(depth == n) {
		for(int i = 0;i < n;i++) {
			fprintf(fout, "%d%c", result[i], i % 10 == 9 || i == n - 1 ? '\n' : ' ');
		}
		return true;
	}
	for(int i = val;i < maxn;i++) {
		result[depth] = i;
		if(judge(i, depth) && dfs(i + 1, maxn, depth + 1)) {
			return true;
		}
	}

	return false;
}
int main() {
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			dist[i][j] = countbit(i ^ j);
		}
	}
	fscanf(fin, "%d%d%d", &n, &b, &d);
	dfs(0, 1 << b, 0);
	return 0;
}
