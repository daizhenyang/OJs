/*
  ID   : 900831f1
  PROG : castle
  LANG : C++
*/
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i, l, n) for(int i = l;i < n;i++)
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "castle.in";
const char * oFileName = "castle.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef long long LL;
const int SIZE      = 51;
const int DIRECTION =  4;
const int dx[DIRECTION] = {0, -1, 0, 1};
const int dy[DIRECTION] = {-1, 0, 1, 0};
bool wall[SIZE][SIZE][DIRECTION];
int check[SIZE][SIZE], area[SIZE * SIZE];
int n, m;
pair<int, int> removeWall;
char direction;

bool judge(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void get_ans(int& sum, int x, int y, int r, int c, char p) {
	if(judge(r, c) && check[x][y] != check[r][c]) {
		if(checkmax(sum, area[check[x][y]] + area[check[r][c]])) {
			direction = p;
			removeWall.first  = x;
			removeWall.second = y;
		}
	}
}

int bfs(int startX, int startY, int c) {
	int area = 1;
	check[startX][startY] = c;
	queue<pair<int, int> > q;
	q.push(make_pair(startX, startY));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int i = 0; i < DIRECTION; i++) {
			int nxtx = x + dx[i];
			int nxty = y + dy[i];
			if (!wall[x][y][i] && judge(nxtx, nxty) && !check[nxtx][nxty]) {
				area++;
				check[nxtx][nxty] = c;
				q.push(make_pair(nxtx, nxty));
			}
		}
	}
	return ::area[c] = area;
}

int main() {
	int rooms = 0, maxArea = 0, sum = 0;
	fscanf(fin, "%d %d", &m, &n);
	memset(wall, false, sizeof (wall));
	memset(check,    0, sizeof (check));
	for (int i = 0; i < n; i++) {
		for (int j = 0, mask; j < m; j++) {
			fscanf(fin, "%d", &mask);
			for (int k = 0; k < DIRECTION; k++) {
				wall[i][j][k] = mask & (1 << k);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (check[i][j] == 0) {
				checkmax(maxArea, bfs(i, j, ++rooms));
			}
	}
	// remove east(right) or north(up) wall
	for(int j = 0;j < m;j++) {
		for(int i = n - 1, r, c;i >= 0;i--){
			r = i - 1, c = j;
			get_ans(sum, i, j, r, c, 'N');
			r = i, c = j + 1;
			get_ans(sum, i, j, r, c, 'E');
		}
	}
	fprintf(fout, "%d\n%d\n%d\n%d %d %c\n", rooms, maxArea, sum, removeWall.first + 1, removeWall.second + 1, direction);
	fclose(fin);
	fclose(fout);
	return 0;
}
