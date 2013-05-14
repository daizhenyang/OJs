#line 2 "KingXMagicSpells.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <iterator>
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
#define LT(i) ((i) << 1)
#define RT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
template<class T> void string_reader(string s, vector<T>& vec){
	istringstream sin(s);
	copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
class KingXMagicSpells 
{
	public:
	const static int N = 51;
	double DP(int k, vector<bool>& ducks, vector<bool>& _sp1, vector<int>& _sp2)
	{
		double dp[N][N][2];
		CC(dp, 0);
		int n = ducks.size();
		REP(i, 0, n)
		{
			dp[0][i][ducks[i]] = 1;
		}
		REP(i, 0, k)
		{
			REP(j, 0, n)
			{
				dp[i + 1][j][0 ^ _sp1[j]] += dp[i][j][0] * 0.5;
				dp[i + 1][_sp2[j]][0] += dp[i][j][0] * 0.5;
				dp[i + 1][j][1 ^ _sp1[j]] += dp[i][j][1] * 0.5;
				dp[i + 1][_sp2[j]][1] += dp[i][j][1] * 0.5;
			}
		}
		return dp[k][0][1];
	}
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int k) 
	{
		double ans = 0, bit = 1;
		int n = ducks.size();
		REP(i, 0, 30)
		{
			vector<bool> d, _sp1;
			REP(j, 0, n) 
			{
				d.push_back(ducks[j] & 1);
				_sp1.push_back(spellOne[j] & 1);
			}
			ans += DP(k, d, _sp1, spellTwo) * bit;
			bit *= 2;
			REP(j, 0, n)
			{
				ducks[j] >>= 1;
				spellOne[j] >>= 1;
			}
		}
		return ans;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 3.5; verify_case(0, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {53, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 21.5; verify_case(1, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {123, 456, 789, 1234, 56789}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; double Arg4 = 123.0; verify_case(2, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 37, 44, 66, 72, 19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 1, 5, 4, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; double Arg4 = 2.888186784716797E7; verify_case(3, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	KingXMagicSpells ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
