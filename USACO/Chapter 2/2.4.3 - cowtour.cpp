/*
  ID   : 900831f1
  PROG : cowtour
  LANG : C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
const char * iFileName = "cowtour.in";
const char * oFileName = "cowtour.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef pair<int, int> PII;

const int N    = 210;
const int INF  = 0x3f3f3f3f;
int px[N], py[N];
double dist[N][N];

double __distance(int i, int j) {
	int dx = px[i] - px[j];
	int dy = py[i] - py[j];
	return sqrt(double(dx * dx + dy * dy));
}
void build_graph(int maps[N][N], int n) {
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			dist[i][j] = maps[i][j] ? __distance(i, j) : INF;
		}
		dist[i][i] = 0;
	}
}

int maps[N][N];
int father[N], _rank[N];

int find_set(int x) {
	return father[x] = father[x] == x ? x : find_set(father[x]);
}

bool union_set(int x,int y) {
	if(x != y) {
		if(_rank[x] < _rank[y]) father[x] = y;
		else {
			_rank[x] += _rank[x] == _rank[y];
			father[y] = x;
		}
		return false;
	}
	return true;
}

bool link_set(int x, int y) {
	return union_set(find_set(x), find_set(y));
}

void initialize(int n) {
	for(int i = 0;i < n;i++) {
		_rank[i] = 0;
		father[i] = i;
	}
}
double maxdis[N];

double diameter(int root, int n) {
	double result = 0;
	for(int i = 0;i < n;i++) {
		if(find_set(i) == root) result = max(result, maxdis[i]);
	}
	return result;
}
int main() {
	int n;
	fscanf(fin, "%d", &n);
	initialize(n);
	for(int i = 0;i < n;i++) fscanf(fin, "%d %d", px + i, py + i);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			fscanf(fin, "%1d", &maps[i][j]);
			if(maps[i][j])  link_set(i, j);
		}
	}
	build_graph(maps, n);
	for(int k = 0;k < n;k++) for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for(int i = 0;i < n;i++) {
		maxdis[i] = 0;
		for(int j = 0;j < n;j++) {
			if(dist[i][j] != INF) maxdis[i] = max(maxdis[i], dist[i][j]);
		}
	}
	double result = INF;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			int fa = find_set(i), fb = find_set(j);
			if(fa == fb) continue;
			result = min(result, max(max(diameter(fa, n), diameter(fb, n)), maxdis[i] + maxdis[j] + __distance(i, j)));
		}
	}
	fprintf(fout, "%.6lf\n", result);
	return 0;
}
