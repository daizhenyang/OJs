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
const int N = 1600;
const int M = N + 10;
const int MOD = 555555555;
LL even[N + 10][N + 10], odd[N + 10][N + 10], c[N + 10][N + 10];
class XorBoard {
	public:
	void DP_odd(LL dp[M][M], int n, int m) {/*n row m paint make 1*/
		dp[0][0] = 1;
		for(int i = 0;i < n;i++) {
			LL sum = 0;
			for(int j = i + 1;j <= m;j += 2) {
				sum += dp[i][j - 1];
				sum %= MOD;
				dp[i + 1][j] += sum;
				dp[i + 1][j] %= MOD;
			}
		}
	}
	void DP_even(LL dp[M][M], int n, int m) {/*0*/
		dp[0][0] = 1;
		for(int i = 0;i < n;i++) {
			LL sum = 0;
			for(int j = 0;j <= m;j += 2) {
				sum += dp[i][j];
				sum %= MOD;
				dp[i + 1][j] += sum;
				dp[i + 1][j] %= MOD;
			}
		}
	}
	LL dp[2][M];
	int count(int H, int W, int Rcount, int Ccount, int S) {
		c[0][0] = 1;
		for(int i = 1;i < N;i++) {
			c[i][0] = c[i][i] = 1;
			for(int j = 1;j < i;j++) {
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
			}
		}
		memset(even, 0, sizeof(even));
		memset(odd,  0, sizeof(odd));
		DP_even(even, N, N);
		DP_odd(odd, N, N);
		memset(dp, 0, sizeof(dp));
		for(int i = 0;i <= H;i++) {
			dp[0][i] = 0;
			for(int j = 0;j <= Rcount;j++) {
				dp[0][i] += odd[i][j] * even[H - i][Rcount - j] % MOD;
				dp[0][i] %= MOD;
			}
		}
		for(int i = 0;i <= W;i++) {
			dp[1][i] = 0;
			for(int j = 0;j <= Ccount;j++) {
				dp[1][i] += odd[i][j] * even[W - i][Ccount - j] % MOD;
				dp[1][i] %= MOD;
			}
		}
		LL res = 0;
		for(int i = 0;i <= H;i++) {
			for(int j = 0;j <= W;j++) {
				if(1LL * i * (W - j) + 1LL * (H - i) * j == S) {
					res += (dp[0][i] * dp[1][j] % MOD) * (c[H][i] * c[W][j] % MOD)% MOD;
					res %= MOD;
				}
			}
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 4; verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 50; int Arg3 = 40; int Arg4 = 200; int Arg5 = 333759825; verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1200; int Arg1 = 1000; int Arg2 = 800; int Arg3 = 600; int Arg4 = 4000; int Arg5 = 96859710; verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 555; int Arg1 = 555; int Arg2 = 555; int Arg3 = 555; int Arg4 = 5550; int Arg5 = 549361755; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        XorBoard ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

