#line 2 "EllysChessboard.cpp"
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
const int N = 20;
const int INF = 1000000;
int dp[N][N][N][N];

int cost(int x, int minx, int maxx) {
    return max(abs(x - minx), abs(maxx - x));
}

class EllysChessboard {
public:
    int n;
    vector<pair<int, int> > pts;
    int DP(int minx, int miny, int maxx, int maxy) {
        int & res = dp[minx][miny][maxx][maxy];
        if(res != -1) return res;
        res = INF;
        int in_box = 1;
        for(int i = 0;i < n;i++) {
            int x = pts[i].first;
            int y = pts[i].second;
            if(!(minx <= x && x <= maxx) || !(miny <= y && y <= maxy)) {
                in_box = 0;
                int dx = cost(x, minx, maxx), dy = cost(y, miny, maxy);
                int nminx = min(x, minx), nminy = min(y, miny);
                int nmaxx = max(x, maxx), nmaxy = max(y, maxy);
                int c = max(dx, dy);

                for(int j = 0;j < n;j++) {
                    int tx = pts[j].first;
                    int ty = pts[j].second;
                    if(i != j && nminx <= tx && tx <= nmaxx && nminy <= ty && ty <= nmaxy
                            && !(minx <= tx && tx <= maxx && miny <= ty && ty <= maxy)) {
                        c += max(max(tx - nminx, nmaxx - tx), max(ty - nminy, nmaxy - ty));
                    }
                }
                res = min(res, c + DP(nminx, nminy, nmaxx, nmaxy));
            }
        }
        if(in_box) res = 0;
        return res;
    }
    int minCost(vector <string> board) {
        pts.clear();
        REP(i, 0, 8) REP(j, 0, 8) {
            if(board[i][j] == '#') pts.push_back(make_pair(i + j, i - j + 10));
        }
        n = pts.size();
        if(n == 0) {
            return 0;
        }
        int res = INF;
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i < n;i++) {
            int x = pts[i].first;
            int y = pts[i].second;
            checkmin(res, DP(x, y, x, y));
        }
        return res;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"........",
        "........",
        "...#....",
        ".#......",
        ".......#",
        "........",
        "........",
        "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, minCost(Arg0)); }
    void test_case_1() { string Arr0[] = {"........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minCost(Arg0)); }
    void test_case_2() { string Arr0[] = {".#......",
        "........",
        "..#..#.#",
        "...#..#.",
        "........",
        "...#...#",
        "...#...#",
        "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(2, Arg1, minCost(Arg0)); }
    void test_case_3() { string Arr0[] = {"##..####",
        "#####..#",
        "..#.#...",
        "#..##.##",
        ".#.###.#",
        "####.###",
        "#.#...#.",
        "##....#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 275; verify_case(3, Arg1, minCost(Arg0)); }
    void test_case_4() { string Arr0[] = {"########",
        "########",
        "########",
        "########",
        "########",
        "########",
        "########",
        "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 476; verify_case(4, Arg1, minCost(Arg0)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EllysChessboard ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
