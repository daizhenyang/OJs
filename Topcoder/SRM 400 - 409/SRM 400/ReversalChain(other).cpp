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
const int N = 51;
int dp[N][N][N][2];
bool chk[N][N][N][2];
class ReversalChain {
	public:
	const static int INF = 10000;
	string s, t;
	int DP(int len, int i, int j, int rev)
	{
		int& res = dp[len][i][j][rev];
		if(res != INF || chk[len][i][j][rev]) return res;
		chk[len][i][j][rev] = true;
		if(rev == 0)
		{
			if(s[i] == t[j]) checkmin(res, DP(len - 1, i + 1, j + 1, 0));
			if(s[i + len - 1] == t[j + len - 1]) checkmin(res, DP(len - 1, i, j, 0));
			if(s[i] == t[j + len - 1]) checkmin(res, DP(len - 1, i + 1, j, 1) + 1);
			if(s[i + len - 1] == t[j]) checkmin(res, DP(len - 1, i, j + 1, 1) + 1);
		}
		else
		{
			if(s[i] == t[j]) checkmin(res, DP(len - 1, i + 1, j + 1, 0) + 1);
			if(s[i + len - 1] == t[j + len - 1]) checkmin(res, DP(len - 1, i, j, 0) + 1);
			if(s[i + len - 1] == t[j]) checkmin(res, DP(len - 1, i, j + 1, 1));
			if(s[i] == t[j + len - 1]) checkmin(res, DP(len - 1, i + 1, j, 1));
		}
		//printf("dp[%d][%d][%d][%d] = %d\n", len ,i, j, rev, res);
		return res;
	}
	int minReversal(string init, string goal) {
		REP(i, 0, N) REP(j, 0, N) REP(k, 0, N) dp[i][j][k][0] = dp[i][j][k][1] = INF;
		memset(chk, 0, sizeof(chk));
		s = init, t = goal;
		int n = init.size();
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) dp[0][i][j][0] = dp[0][i][j][1] = 0;
		int res = DP(n, 0, 0, 0);
		return res == INF ? -1 : res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "11111111111111111100000000000000001111111111111111"; string Arg1 = "11111111110000000011111111111111110000000011111111"; int Arg2 = 2; verify_case(0, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "111000"; string Arg1 = "101010"; int Arg2 = 2; verify_case(1, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; string Arg1 = "1"; int Arg2 = -1; verify_case(2, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "10101"; string Arg1 = "10101"; int Arg2 = 0; verify_case(3, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "111000111000"; string Arg1 = "001100110011"; int Arg2 = 4; verify_case(4, Arg2, minReversal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ReversalChain ___test;
        ___test.run_test(-1);
        return 0;
}
//END CUT HERE
