#line 2 "DirectionBoard.cpp"
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
using namespace std;
typedef int USETYPE;
const USETYPE INF = numeric_limits<USETYPE>::max();//<limits>
template<typename T = int>
class mincost {
private:
    const static int N = 1000;
    const static int E = 100000;
    struct edge {
        int u, v;
        T cost, cap;
        edge *nxt;
    } pool[E], *g[N], *pp, *pree[N];
    T dist[N];

    bool SPFA(int n,int s, int t) {
        fill(dist, dist + n, INF);
        int tail = 0, q[N] = {s};
        dist[s] = 0;
        bool vst[N] = {false};
        vst[s] = true;
        for(int i = 0; i <= tail; i++) {
            int u = q[i % n];
            for(edge *j = g[u]; j != NULL; j= j->nxt) {
                int v = j->v;
                if(j->cap && dist[u] != INF && dist[v] > dist[u] + j->cost) {
                    dist[v] = dist[u] + j->cost;
                    pree[v] = j;
                    if(!vst[v]) {
                        tail++;
                        q[tail % n] = v;
                        vst[v] = true;
                    }
                }
            }
            vst[u] = false;
        }
        return dist[t] < INF;
    }
public:
#define OP(i) (((i) - pool) ^ 1)
    void addedge(int u, int v, T cap, T cost) {
        pp->u = u, pp->v = v;
        pp->cost = cost, pp->cap = cap;
        pp->nxt = g[u],g[u] = pp++;
    }
    void initialize() {
        CC(g, 0);
        pp = pool;
    }
    pair<T, T> mincostflow(int n, int s, int t) {
        T flow = 0, cost = 0;
        while(SPFA(n, s, t)) {
            T minf = INF;
            for(int i = t; i != s; i = pree[i]->u)
                minf = min(minf, pree[i]->cap);
            for(int i = t; i != s; i = pree[i]->u) {
                pree[i]->cap -= minf;
                pool[OP(pree[i])].cap += minf;
                cost += minf * pree[i]->cost;
            }
            flow += minf;
        }
        return make_pair(flow, cost);
    }
};
mincost<int> flow;
const int COST[] = {0, 1, 1, 1};
//URDL
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
class DirectionBoard {
	int identifier(char ch) {
		switch(ch) {
			case 'U' : return 0;
			case 'R' : return 1;
			case 'D' : return 2;
			case 'L' : return 3;
		}
		return -1;
	}
	public:
	int getMinimum(vector <string> board) {
		int n = board.size(), m = board[0].size();
		int s = 0, t = n * m * 2 + 1;
		flow.initialize();
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				int v = i * m + j + 1, cur = identifier(board[i][j]);
				flow.addedge(s, v, 1, 0);
				flow.addedge(v, s, 0, 0);
				flow.addedge(v + m * n, t, 1, 0);
				flow.addedge(t, v + m * n, 0, 0);
				for(int k = 0;k < 4;k++) {
					int nxt = (cur + k) % 4;
					int x = (i + dx[nxt] + n) % n;
					int y = (j + dy[nxt] + m) % m;
					int u = x * m + y + 1 + m * n;
					flow.addedge(v, u, 1, COST[k]);
					flow.addedge(u, v, 0,-COST[k]);
				}
			}
		}
		return flow.mincostflow(t + 1, s, t).second;
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
