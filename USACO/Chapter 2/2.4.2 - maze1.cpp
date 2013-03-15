/*
  ID   : 900831f1
  PROG : maze1
  LANG : C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
const char * iFileName = "maze1.in";
const char * oFileName = "maze1.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef pair<int, int> PII;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int N    = 210;
const int INF  = 0x3f3f3f3f;
char maps[N][N];
int can[N][N][4], mask[N][N];

int pos(int x) {
	return (x << 1) + 1;
}

int main() {
	int w, h;
	fscanf(fin, "%d %d\n", &w, &h);
	for(int i = 0;i < (h << 1) + 1;i++) {
		fgets(maps[i], N, fin);
	}
	memset(can, 0, sizeof(can));
	for(int i = 0;i < h;i++) for(int j = 0;j < w;j++) {
		for(int k = 0;k < 4;k++) {
			int x = pos(i) + dx[k];
			int y = pos(j) + dy[k];
			if(maps[x][y] == ' ') can[i][j][k] = 1;
		}
	}
	queue<PII> q;
	memset(mask, 0x3f, sizeof(mask));
	// left & right
	for(int i = 0;i < h;i++) {
		if(maps[pos(i)][pos(0) - 1] == ' ') q.push(make_pair(i, 0)), mask[i][0] = 0;
		if(maps[pos(i)][pos(w - 1) + 1] == ' ') q.push(make_pair(i, w - 1)), mask[i][w - 1] = 0;
	}
	// up & down
	for(int i = 0;i < w;i++) {
		if(maps[pos(0) - 1][pos(i)] == ' ') q.push(make_pair(0, i)), mask[0][i] = 0;
		if(maps[pos(h - 1) + 1][pos(i)] == ' ') q.push(make_pair(h - 1, i)), mask[h - 1][i] = 0;
	} 
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k = 0;k < 4;k++) {
			int tmpx = x + dx[k];
			int tmpy = y + dy[k];
			if(can[x][y][k] && mask[tmpx][tmpy] == INF) {
				q.push(make_pair(tmpx, tmpy));
				mask[tmpx][tmpy] = mask[x][y] + 1;
			}
		}
	}
	int res = 0;
	for(int i = 0;i < h;i++) for(int j = 0;j < w;j++) {
		res = max(res, mask[i][j]);
	}
	fprintf(fout, "%d\n", res + 1);
	return 0;
}
