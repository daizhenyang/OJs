#line 2 "DeerInZooDivOne.cpp"
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
#include <iterator>
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
using namespace std;
typedef int USETYPE;
const USETYPE INF = numeric_limits<USETYPE>::max();//<limits>
template<typename T = int>
class mincost {
private:
    const static int N = 60;
    const static int E = 3600;
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
    void _addedge(int u, int v, T cap, T cost) {
        pp->u = u, pp->v = v;
        pp->cost = cost, pp->cap = cap;
        pp->nxt = g[u],g[u] = pp++;
    }
    void addedge(int u, int v, T cap, T cost) {
        _addedge(u, v, cap, cost);
        _addedge(v, u, 0,  -cost);
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
const int N = 60;
class DeerInZooDivOne {
public:
    vector<vector<int> > g;
    int dp[N][N];
    int solve(int x, int fx, int y, int fy) {
        int & res = dp[x][y];
        if(res != -1) return res;
        res = 1;

        vector<int> mx, my;
        FOREACH(g[x], i) if(*i != fx) mx.push_back(*i);
        FOREACH(g[y], i) if(*i != fy) my.push_back(*i);

        int sx = mx.size(), sy = my.size();
        if(sx == 0 || sy == 0) return res;
        int s = 0, t = sx + sy + 1;

        mincost<int> flow;
        flow.initialize();
        REP(i, 0, sx) flow.addedge(s, i + 1, 1, 0);
        REP(i, 0, sy) flow.addedge(i + 1 + sx, t, 1, 0);
        REP(i, 0, sx) REP(j, 0, sy) {
            int a = i + 1, b = sx + j + 1;
            int v = solve(mx[i], x, my[j], y);
            flow.addedge(a, b, 1, -v);
        }
//        printf("s : %d, t : %d\n", s, t);
//        FOREACH(mx, i) printf("%d ", *i); puts("");
//        FOREACH(my, i) printf("%d ", *i); puts("");
        res -= flow.mincostflow(t + 1, s, t).second;
        return res;
    }

    void dfs(int root, int prev, vector<int>& vst) {
        vst[root] = 1;
        FOREACH(g[root], i) {
            if(*i != prev) dfs(*i, root, vst);
        }
    }

    int getmax(vector <int> a, vector <int> b) {
        int n = a.size() + 1;
        g = vector<vector<int> >(n);
        for(int i = 0;i < n - 1;i++) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
        int res = 0;
        for(int i = 0;i < n - 1;i++) {
            vector<int> vst(n);
            int x = a[i], y = b[i];
            g[x].erase(find(g[x].begin(), g[x].end(), y));
            g[y].erase(find(g[y].begin(), g[y].end(), x));
            dfs(x, n, vst);
            for(int k = 0;k < n;k++) if(vst[k] == 1) {
                memset(dp, -1, sizeof(dp));
                checkmax(res, solve(k, n, y, n));
            }
            for(int k = 0;k < n;k++) if(vst[k] == 0) {
                memset(dp, -1, sizeof(dp));
                checkmax(res, solve(x, n, k, n));
            }
            g[x].push_back(y);
            g[y].push_back(x);
        }
        return res;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {1, 8, 1, 7, 4, 2, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 3, 6, 8, 2, 6, 8, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {0, 11, 10, 10, 19, 17, 6, 17, 19, 10, 10, 11, 9, 9, 14, 2, 13, 11, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 5, 2, 12, 8, 9, 16, 8, 4, 18, 8, 13, 15, 13, 17, 16, 3, 1, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {14, 13, 28, 15, 20, 4, 9, 6, 1, 23, 19, 25, 25, 8, 14, 16, 2, 8, 15, 25, 22, 22, 28, 10, 10, 14, 24, 27, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21, 5, 12, 13, 27, 1, 24, 17, 27, 17, 23, 14, 18, 26, 7, 26, 11, 0, 25, 23, 3, 29, 22, 11, 22, 29, 15, 28, 29}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DeerInZooDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
