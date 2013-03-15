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
const int N = 6001000;
int dp[2][N];
class CustomDice {
	public:
	static const int MOD = 1000000007;
	int countDice(int M) {
		int m = M * 6 - 21;
		if(m < 0) return 0;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 30;
		int now = 0, pre = 1;
		for(int i = 0;i < 6;i++)
		{
			now ^= 1;pre ^= 1;
			for(int j = 0;j <= m;j++)
			{
				dp[now][j] = dp[pre][j] % MOD;
				if(j > i) dp[now][j] = (dp[now][j] + dp[now][j - i - 1]) % MOD;
			}
		}
		int res = 0;
		for(int i = 0;i <= m;i++) res = (res + dp[now][i]) % MOD;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; verify_case(0, Arg1, countDice(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 210; verify_case(1, Arg1, countDice(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 863010; verify_case(2, Arg1, countDice(Arg0)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 375588112; verify_case(3, Arg1, countDice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CustomDice ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
