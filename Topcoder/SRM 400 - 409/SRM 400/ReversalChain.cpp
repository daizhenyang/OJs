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
class ReversalChain {
	public:
	static const int INF = 1000000;
	map<string, int> dp;
	int solve(string init, string goal)
	{
		if(init == goal) return 0;
		string key = init + " " + goal;
		map<string, int>::iterator iter = dp.find(key);
		if(iter != dp.end()) return iter->second;
		dp[key] = INF;
		int sz = init.size();
		if(init[0] == goal[0])
			checkmin(dp[key], solve(init.substr(1, string::npos), goal.substr(1, string::npos)));
		if(init[sz - 1] == goal[sz - 1])
			checkmin(dp[key], solve(init.substr(0, sz - 1), goal.substr(0, sz - 1)));
		reverse(init.begin(), init.end());
		if(init[0] == goal[0])
			checkmin(dp[key], solve(init.substr(1, string::npos), goal.substr(1, string::npos)) + 1);
		if(init[sz - 1] == goal[sz - 1])
			checkmin(dp[key], solve(init.substr(0, sz - 1), goal.substr(0, sz - 1)) + 1);
		return dp[key];
	}
	int minReversal(string init, string goal) {
		dp.clear();
		int res = solve(init, goal);
		return res == INF ? -1 : res;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ""; string Arg1 = ""; int Arg2 = 0; verify_case(0, Arg2, minReversal(Arg0, Arg1)); }
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
// END CUT HERE

