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
const int N = 19;
double dp[N][N][N];
class PrimeSoccer {
	public:
	bool is_prime(int x) {
		if(x == 0 || x == 1) return false; 
		for(int i = 2;i * i <= x;i++) {
			if(x % i == 0) return false;
		}
		return true;
	}
	double getProbability(int skillOfTeamA, int skillOfTeamB) {
		memset(dp, 0, sizeof(dp));
		double winA = 1.0 * skillOfTeamA / 100;
		double winB = 1.0 * skillOfTeamB / 100;
		dp[0][0][0] = 1;
		int n = N - 1;
		REP(k, 0, n) {
			REP(i, 0, n) {
				REP(j, 0, n) {
					dp[k + 1][i + 1][j] += dp[k][i][j] * winA * (1 - winB);
					dp[k + 1][i][j + 1] += dp[k][i][j] * (1 - winA) * winB;
					dp[k + 1][i][j] += dp[k][i][j] * (1 - winA) * (1 - winB);
					dp[k + 1][i + 1][j + 1] += dp[k][i][j] * winA * winB;
				}
			}
		}
		double res = 0;
		REP(i, 0, N) REP(j, 0, N) {
			res += (is_prime(i) || is_prime(j)) ? dp[N - 1][i][j] : 0;
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PrimeSoccer ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
