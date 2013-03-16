#line 2 "RotatingBot.cpp"
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int N = 200;
const int S = 100;
int pos[N][N];
class RotatingBot {
	public:
	int minx, miny, maxx, maxy;
	bool judge(int posx, int posy) {
		return  minx <= posx && posx <= maxx &&
			miny <= posy && posy <= maxy;
	}
	bool turn(int dir, int posx, int posy) {
		posx += dx[dir];
		posy += dy[dir];
		if(judge(posx, posy) == false || pos[posx][posy] != -1) {
			return true;
		}
		return false;
	}
	void bfs(int startx, int starty) {
		int dir = 0, count = 0, used = 0;
		memset(pos, -1, sizeof(pos));
		do {
			pos[startx][starty] = count++;
			used = 0;
			while(turn(dir, startx, starty) && used < 4) {
				dir = (dir + 1) % 4;
				used++;
			}
			if(used < 4) {
				startx += dx[dir];
				starty += dy[dir];
			}
		} while(used < 4);
	}
	int minArea(vector <int> moves) {
		set<PII>    hash;
		vector<PII> path;
		int x = S, y = S, k = 0;
		hash.insert(make_pair(x, y));
		path.push_back(make_pair(x, y));
		minx = S, miny = S;
		maxx = S, maxy = S;
		FOREACH(moves, i) {
			for(int j = 0;j < *i;j++) {
				x += dx[k % 4];
				y += dy[k % 4];
				if(hash.find(make_pair(x, y)) != hash.end()) {
					return -1;
				}
				path.push_back(make_pair(x, y));
				hash.insert(make_pair(x, y));
			}
			switch(k) {
				case 0 : checkmax(maxy, y);break;
				case 1 : checkmin(minx, x);break;
				case 2 : checkmin(miny, y);break;
				case 3 : checkmax(maxx, x);break;
			}
			k++;
		}
		bfs(S, S);
		for(int i = 0;i < int(path.size());i++) {
			if(pos[path[i].first][path[i].second] != i) {
				return -1;
			}
		}
		return (maxx - minx + 1) * (maxy - miny + 1);
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
