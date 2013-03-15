/*
  ID   : 900831f1
  PROG : lamps
  LANG : C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 256;
const char * iFileName = "lamps.in";
const char * oFileName = "lamps.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
int finalConfig[N], config[N];
void flip(int a[], int beg, int add, int n) {
	for(int i = beg;i < n;i += add) {
		a[i] ^= 1;
	}
}
bool equal(int a[], int b[], int n) {
	for(int i = 0;i < n;i++) {
		if(a[i] != b[i] && a[i] != -1 && b[i] != -1)
			return false;
	}
	return true;
}
void print(const vector<int>& config) {
	for(int i = 0;i < int(config.size());i++) {
		fprintf(fout, "%d", config[i]);
	}
	fprintf(fout, "\n");
}
vector<vector<int> > result;
int n, c, v;
int ADD[] = {1, 2, 2, 3};
int BEG[] = {0, 0, 1, 0};
void dfs(int depth, int used, int maxUsed) {
	if(used > maxUsed) return;
	if(depth == 4) {
		if((maxUsed - used) % 2 == 0 && equal(config, finalConfig, n)) {
			result.push_back(vector<int>(config, config + n));
		}
		return;
	}
	flip(config, BEG[depth], ADD[depth], n);
	dfs(depth + 1, used + 1, maxUsed);
	flip(config, BEG[depth], ADD[depth], n);
	dfs(depth + 1, used, maxUsed);
}
int main() {
	memset(finalConfig, -1, sizeof(finalConfig));
	fscanf(fin, "%d %d", &n, &c);
	for(int i = 0;i < n;i++) config[i] = 1;
	while(fscanf(fin, "%d", &v) == 1 && v != -1) {
		finalConfig[v - 1] = 1;
	}
	while(fscanf(fin, "%d", &v) == 1 && v != -1) {
		finalConfig[v - 1] = 0;
	}
	dfs(0, 0, c);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	if(result.size() == 0) {
		fprintf(fout, "IMPOSSIBLE\n");
	}
	for(int i = 0;i < int(result.size());i++) {
		print(result[i]);
	}
	return 0;
}
