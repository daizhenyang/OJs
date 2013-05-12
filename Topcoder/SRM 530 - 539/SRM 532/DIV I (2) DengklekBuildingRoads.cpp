// BEGIN CUT HERE

// END CUT HERE
#line 5 "DengklekBuildingRoads.cpp"
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


const int N = 51;
const int K = 8;
LL dp[N][K + 1][N][1 << K];
class DengklekBuildingRoads
{
public:
	static const int MOD = 1000000007;
	int bit[1 << K];
	void transfer(LL & a, LL b)
	{
		a = (a + b) % MOD;
	}
	int cnt_bit(int x)
	{
		if(bit[x] != -1) return bit[x];
		bit[x] = 0;
		for(int i = 0;i < 16;i++)
			if(x & (1 << i)) bit[x] ^= 1;
		return bit[x];
	}
	int numWays(int n, int m, int k)
	{
		CC(dp, 0);
		CC(bit, -1);
		dp[0][0][0][0] = 1;
		int s = (1 << k);
		REP(i, 0, n)
		{
			REP(pre, 0, k)
			{
				int p = i - k + pre;
				//transform to this edge && a  new edge
				REP(j, 0, m)
					REP(now, 0, s)
						if(p >= 0 && p < i && dp[i][pre][j][now] != 0)
							transfer(dp[i][pre][j + 1][now ^ (1 << pre)], dp[i][pre][j][now]);
				//transform to next edge && no new edge
				REP(j, 0, m + 1)
					REP(now, 0, s)
						if(pre != k - 1 && dp[i][pre][j][now] != 0)
							transfer(dp[i][pre + 1][j][now], dp[i][pre][j][now]);
			}
			//transfrom to next point
			REP(j, 0, m + 1)
				REP(now, 0, s)
				{
					int newS = (now >> 1) | (cnt_bit(now) << (k - 1)), pre = k - 1;
					if(dp[i][pre][j][now] == 0 || (now & 1)) continue;
					transfer(dp[i + 1][0][j][newS], dp[i][pre][j][now]);	
				}
		}
		return dp[n - 1][k - 1][m][0];
	}
	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 5; int Arg3 = 26964424; verify_case(4, Arg3, numWays(Arg0, Arg1, Arg2)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	DengklekBuildingRoads ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE

