// BEGIN CUT HERE

// END CUT HERE
#line 5 "TurtleSpy.cpp"
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
const double PI = acos(-1.0);

class TurtleSpy
{
        public:
	static const int N = 36000;
	int dp[N], x;
	void DP(vector<int>& rr, vector<int>& x)
	{
		CC(dp, 0);
		dp[0] = 1;
		REP(i, 0, rr.size())
		{
			for(int j = N - 1;j >= rr[i];j--)
				dp[j] |= dp[j - rr[i]];
		}
		REP(i, 0, N)
			if(dp[i]) x.push_back(i);
	}
	vector<int> forw, back;
	vector<int> rr, ll;
	char cmd[100];
	double maxDistance(vector <string> com)
	{
		forw.clear();back.clear();
		rr.clear(); ll.clear();
		FOREACH(com, i)
		{
			sscanf(i->c_str(), "%s %d", cmd, &x);
			if(strcmp(cmd, "right") == 0)
			{
				rr.push_back(x);
			}
			else if(strcmp(cmd, "left") == 0)
			{
				ll.push_back(x);
			}
			else if(strcmp(cmd, "forward") == 0)
			{
				forw.push_back(x);
			}
			else if(strcmp(cmd, "backward") == 0)
			{
				back.push_back(x);
			}
		}
		vector<int> x, y;
		DP(rr, x);DP(ll, y);
		int n = x.size(), m = y.size();
		double res = 0;
		double f = accumulate(forw.begin(), forw.end(), 0.00);
		double b = accumulate(back.begin(), back.end(), 0.00);
		REP(i, 0, n) REP(j, 0, m)
		{
			int tmp = ((x[i] - y[j]) % 360 + 360) % 360;
			if(tmp > 180) tmp = 360 - tmp;
			double _res = f * f + b * b - 2 * f * b * cos(tmp / 180.0 * PI);
			checkmax(res, _res);
		}
		return sqrt(res);
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TurtleSpy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
