/*
  ID   : 900831f1
  PROG : holstein
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "holstein.in";
const char * oFileName = "holstein.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef long long LL;
const int N = 25;
int vitamins[N], feed[N][N];
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
bool enough(int V, int mask, int G) {
	int total[N] = {0, };
	for(int i = 0;i < G;i++) {
		if(mask & (1 << i)) {
			for(int j = 0;j < V;j++) {
				total[j] += feed[i][j];
			}
		}
	}
	for(int i = 0;i < V;i++) {
		if(total[i] < vitamins[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int V, G;
	fscanf(fin, "%d", &V);
	for(int i = 0;i < V;i++) fscanf(fin, "%d", &vitamins[i]);
	fscanf(fin, "%d", &G);
	for(int i = 0;i < G;i++) {
		for(int j = 0;j < V;j++) {
			fscanf(fin, "%d", &feed[i][j]);
		}
	}
	int result = V + 1, answer;
	for(int mask = 1;mask < (1 << G);mask++) {
		int bit = countbit(mask);
		if(result > bit && enough(V, mask, G)) {
			result = bit;
			answer = mask;
		}
	}
	fprintf(fout, "%d", result);
	for(int i = 0;i < G;i++) {
		if(answer & (1 << i)) {
			fprintf(fout, " %d", i + 1);
		}
	}
	fprintf(fout, "\n");
	return 0;
}
