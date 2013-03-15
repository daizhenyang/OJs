/*
  ID   : 900831f1
  PROG : ttwo
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
const char * iFileName = "ttwo.in";
const char * oFileName = "ttwo.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
struct position {
	int x, y, dir;
	position(int x = 0, int y = 0, int dir = 0)
	: x(x), y(y), dir(dir) { }
};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int N   = 10;
const int INF = 0x3f3f3f3f;
char maps[N][N];
bool check_position(int x, int y, int n) {
	return  0 <= x && x < n &&
		0 <= y && y < n && maps[x][y] != '*';
}

position next_position(const position& current, int n) {
	int tmpx = current.x + dx[current.dir];
	int tmpy = current.y + dy[current.dir];
	int dir  = current.dir;
	if(check_position(tmpx, tmpy, n)) {
		// move forwards
	} else {
		// turn clockwise
		tmpx = current.x;
		tmpy = current.y;
		dir  = (current.dir + 1) % 4;
	}
	return position(tmpx, tmpy, dir);
}

const int MAXN = 1600000;
int bfs(int cx, int cy, int fx, int fy, int n) {
	int step = 0;
	position cpos = position(cx, cy, 0);
	position fpos = position(fx, fy, 0);
	while(step < MAXN) {
		step++;
		cpos = next_position(cpos, n);
		fpos = next_position(fpos, n);
		if(fpos.x == cpos.x && fpos.y == cpos.y) {
			return step;
		}
	}
	return 0;
}

int main() {
	for(int i = 0;i < N;i++) fin >> maps[i];
	int cx, cy, fx, fy;
	for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
		if(maps[i][j] == 'C') {
			cx = i, cy = j;
		} else if(maps[i][j] == 'F') {
			fx = i, fy = j;
		}
	}
	fout << bfs(cx, cy, fx, fy, N) << endl;
	return 0;
}
