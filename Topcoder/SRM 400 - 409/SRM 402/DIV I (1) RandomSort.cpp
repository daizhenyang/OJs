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
const int N = 10; // 0! to (n - 1)!
const int fac[N] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(const int *a, const int n)//from 0 to n - 1
{
	int ans = 0, i, j, r;
	char p[N] = {0};
	for (i = 0; i < n; i++)
	{
		for (j = 0, r = 0; j <= a[i]; j++)
			if (p[j] == 0) r++;
		ans += (r - 1) * fac[n - 1 - i];
		p[a[i]] = 1;
	}
	return ans;
}

const int S = 40320;
double dp[S];
bool  chk[S];
class RandomSort {
public:
	int a[N];
	double DP(const int s, const int n)
	{
		if(chk[s]) return dp[s];
		chk[s] = true;
		dp[s] = 0;
		int cnt = 0;
		REP(i, 0, n) REP(j, i + 1, n)
			if(a[i] > a[j]) cnt++;
		REP(i, 0, n) REP(j, i + 1, n)
			if(a[i] > a[j])
			{
				swap(a[i], a[j]);
				int news = cantor(a, n);
				dp[s] += 1.0 / cnt * (DP(news, n) + 1);
				swap(a[i], a[j]);
			}
		return dp[s];
	}
	double getExpected(vector <int> p) {
		memset(chk, 0, sizeof(chk));
		chk[0] = 1;
		copy(p.begin(), p.end(), a);
		sort(p.begin(), p.end());
		int n = p.size();
		REP(i, 0, n) a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
		int s = cantor(a, n);
		return DP(s, n);
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }

	// END CUT HERE
};

// BEGIN CUT HERE
int main()
{
	RandomSort ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
