#include <cstring>
#include <cstdio>
#include <cassert>
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
class CuttingBitString {
	public:
	LL v[N][N];
	int dp[N];
	LL str2long(const string& str) {
		int s = str.size();
		LL res = 0;
		for(int i = 0;i < s;i++) {
			res <<= 1;
			res += str[i] - '0';
		}
		return res;
	}
	bool judge5(LL x) {
		assert(x > 0);
		while(x % 5 == 0) {
			x /= 5;
		}
		return x == 1;
	}
	int getmin(string S) {
		int n = S.size();
		memset(v, 0, sizeof(v));
		for(int i = 1;i <= n;i++) {
			for(int j = i;j <= n;j++) {
				string sub = S.substr(i - 1, j - i + 1);
				if(sub[0] != '0') {
					LL u = str2long(sub);
					if(judge5(u)) {
						v[i][j] = true;
					}
				}
			}
		}
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < i;j++) {
				if(v[j + 1][i] && dp[j] != -1) {
					if(dp[i] == -1) {
						dp[i] = dp[j] + 1;
					} else {
						dp[i] = min(dp[i], dp[j] + 1);
					}
				}
			}
		}
		return dp[n];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "11111111111111111111111111111111111111111111111111"; int Arg1 = 50; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CuttingBitString ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
