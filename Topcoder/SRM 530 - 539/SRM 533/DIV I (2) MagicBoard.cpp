// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicBoard.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
template<class T> void string_reader(string s, vector<T>& vec){
    istringstream sin(s);
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
const int N = 50;
class MagicBoard
{
public:
    int vst[N][N], graph[N][N];
    int row_dgree[N], col_dgree[N];
    void Dfs(int px, int py, int n, int m) {
        vst[px][py] = 1;
        for(int i = 0;i < n;i++) {
            if(i != px && !vst[i][py] && graph[i][py])
                Dfs(i, py, n, m);
        }
        for(int j = 0;j < m;j++) {
            if(j != py && !vst[px][j] && graph[px][j])
                Dfs(px, j, n, m);
        }
    }
	string ableToUnlock(vector <string> board) {
        int n = board.size(), m = board[0].size();
        int startx = -1, starty = -1;
        int rds = 0, cds = 0;

        memset(vst, 0, sizeof(vst));
        memset(graph, 0, sizeof(graph));
        memset(row_dgree, 0, sizeof(row_dgree));
        memset(col_dgree, 0, sizeof(col_dgree));

        REP(i, 0, n) REP(j, 0, m) {
            if(board[i][j] == '#') {
                row_dgree[i]++;
                col_dgree[j]++;
                graph[i][j] = 1;
                startx = i, starty = j;
            }
        }

        if(startx == -1) return "YES";

        Dfs(startx, starty, n, m);
        REP(i, 0, n) REP(j, 0, m) {
            if(board[i][j] == '#' && !vst[i][j])
                return "NO";
        }

        REP(j, 0, m) {
            if(col_dgree[j] & 1) cds++;
        }
        REP(i, 0, n) {
            if(row_dgree[i] & 1) rds++;
        }

        if((rds + cds != 2 && rds + cds != 0) || (rds == 2 && cds == 0)) {
            return "NO";
        }
        return "YES";
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"##",
		".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, ableToUnlock(Arg0)); }
	void test_case_1() { string Arr0[] = {"#.",
		".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, ableToUnlock(Arg0)); }
	void test_case_2() { string Arr0[] = {"##",
		"##",
		"##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, ableToUnlock(Arg0)); }
	void test_case_3() { string Arr0[] = {"###",
		"###",
		"###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, ableToUnlock(Arg0)); }
	void test_case_4() { string Arr0[] = {"###",
		"..#",
		"###",
		"#..",
		"###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, ableToUnlock(Arg0)); }
	void test_case_5() { string Arr0[] = {"................",
		".######..######.",
		".######..######.",
		".##......##..##.",
		".##......##..##.",
		".######..######.",
		".######..######.",
		".....##..##..##.",
		".....##..##..##.",
		".######..######.",
		".######..######.",
		"................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(5, Arg1, ableToUnlock(Arg0)); }
	void test_case_6() { string Arr0[] = {"#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(6, Arg1, ableToUnlock(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	MagicBoard ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
