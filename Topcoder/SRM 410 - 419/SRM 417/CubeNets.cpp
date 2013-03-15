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
class CubeNets {
	public:
	char pat[100][100];
	int n, m;
	bool isOK(int i, int j) {
		return 0 <= i && i < n && 0 <= j && j < m && pat[i][j] == '#';
	}
	template<class T>
	bool check(int i, int j, int cnt, T op) {
		bool res = isOK(i, j);
		for(int k = 1;k < cnt;k++)
			res = op(res, isOK(i, j += 1));
		return res;
	}
	bool solve() {
		logical_or<bool>  or_op;
		logical_and<bool> and_op;
		REP(i, 0, n) REP(j, 0, m)
		{
			/* 141 pattern */
			if(check(i, j, 4, and_op) && check(i + 1, j, 4, or_op) && check(i - 1, j, 4, or_op))
				return true;
			/* step 2 pattern */
			if(check(i, j, 2, and_op) && check(i + 1, j + 1, 2, and_op) && check(i + 2, j + 2, 2, and_op))
				return true;
			if(check(i, j, 2, and_op) && check(i + 1, j - 1, 2, and_op) && check(i + 2, j - 2, 2, and_op))
				return true;
			/* 231 pattern */
			if(check(i, j, 2, and_op) && check(i + 1, j + 1, 3, and_op) && check(i + 2, j + 1, 3, or_op))
				return true;
			if(check(i, j, 2, and_op) && check(i - 1, j + 1, 3, and_op) && check(i - 2, j + 1, 3, or_op))
				return true;
			if(check(i, j, 2, and_op) && check(i + 1, j - 2, 3, and_op) && check(i + 2, j - 2, 3, or_op))
				return true;
			if(check(i, j, 2, and_op) && check(i - 1, j - 2, 3, and_op) && check(i - 2, j - 2, 3, or_op))
				return true;
			/* 33 pattern */
			if(check(i, j, 3, and_op) && check(i + 1, j + 2, 3, and_op))
				return true;
			if(check(i, j, 3, and_op) && check(i + 1, j - 2, 3, and_op))
				return true;
		}
		return false;
	}
	string isCubeNet(vector <string> fig) {
		n = fig.size(), m = fig[0].size();
		REP(i, 0, n) REP(j, 0, m) pat[i][j] = fig[i][j];
		if(solve()) {
			return "YES";
		}
		REP(i, 0, n) REP(j, 0, m) pat[j][i] = fig[i][j];
		swap(n, m);
		if(solve()) {
			return "YES";
		}
		return "NO";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..#.",
 "####",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isCubeNet(Arg0)); }
	void test_case_1() { string Arr0[] = {"###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isCubeNet(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
"####",
".#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isCubeNet(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..",
 ".##.",
 "..##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, isCubeNet(Arg0)); }
	void test_case_4() { string Arr0[] = {"..##",
 ".##.",
 "##.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, isCubeNet(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CubeNets ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
