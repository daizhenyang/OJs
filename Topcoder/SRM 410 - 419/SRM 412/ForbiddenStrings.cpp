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
class ForbiddenStrings {
	public:
	static const int N = 40;
	static const int K = 27;
	LL dp[N][K];
	bool legal(int x) {
		int a[] = {x / 9, x / 3 % 3, x % 3};
		sort(a, a + 3);
		return a[0] == a[1] || a[1] == a[2];
	}
	long long countNotForbidden(int n) {
		memset(dp, 0, sizeof(dp));
		if(n == 1) return 3;
		if(n == 2) return 9;
		REP(j, 0, K) {
			if(legal(j)) dp[3][j] = 1;
		}
		REP(i, 0, n) REP(j, 0, K) {
			if(legal(j)) {
				int a[] = {j / 9, j / 3 % 3, j % 3};
				int nxt = a[1] * 9 + a[2] * 3;
				for(int k = 0;k < 3;k++) {
					dp[i + 1][nxt + k] += dp[i][j];
				}
			}
		}
		LL res = 0;
		REP(j, 0, K) if(legal(j)) res  += dp[n][j];
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ForbiddenStrings ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
