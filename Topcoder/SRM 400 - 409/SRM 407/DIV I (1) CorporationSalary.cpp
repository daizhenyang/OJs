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
class CorporationSalary {
	public:
	const static int N = 50;
	LL dp[N];
	LL DP(int x, const int n, vector<string>& r) {
		if(dp[x]) return dp[x];
		REP(i, 0, n) {
			if(r[x][i] == 'Y' && i != x) dp[x] += DP(i, n, r);
		}
		checkmax(dp[x], 1LL);
		return dp[x];
	}
	long long totalSalary(vector <string> r) {
		int n = r.size();
		memset(dp, 0, sizeof(dp));
		REP(i, 0, n) DP(i, n, r);
		return accumulate(dp, dp + n, 0LL);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalSalary(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(1, Arg1, totalSalary(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17LL; verify_case(2, Arg1, totalSalary(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(3, Arg1, totalSalary(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(4, Arg1, totalSalary(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CorporationSalary ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
