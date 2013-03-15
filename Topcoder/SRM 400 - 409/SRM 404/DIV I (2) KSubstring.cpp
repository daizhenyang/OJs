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
const LL INF = 10000000000000LL;
const int N = 3001;
LL a[N];
LL s[N][2];
class KSubstring {
	public:
		vector <int> maxSubstring(int A0, int X, int Y, int M, int n) {
			a[0] = A0;
			REP(i, 1, n) a[i] = (a[i - 1] * X + Y) % M;
			int now = 0, pre = 1;
			LL val = INF, h = 0;
			memset(s, 0, sizeof(s));
			for(int k = 1;k <= n;k++)
			{
				now ^= 1, pre ^= 1;
				for(int i = 0;i + k <= n;i++)
				{
					s[i][now] = s[i + 1][pre] + a[i];
				}
				multiset<LL> sets;
				for(int i = k;i + k <= n;i++)
					sets.insert(s[i][now]);
				for(int i = 0;i + (k << 1) <= n;i++)
				{
					multiset<LL>::iterator up = sets.upper_bound(s[i][now]);
					LL tv = INF;
					if(up != sets.end())
						checkmin(tv, abs(s[i][now] - *up));
					if(up != sets.begin())
						checkmin(tv, abs(s[i][now] - *--up));
					if(val == tv || checkmin(val, tv)) h = k;
					multiset<LL>::iterator key = sets.lower_bound(s[i + k][now]);
					sets.erase(key);
				}
			}
			int tmpres[] = {int(h), int(val)};
			vector<int> res(tmpres, tmpres + 2);
			return res;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
		void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; int Arg3 = 25; int Arg4 = 5; int Arr5[] = {2, 1 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }
		void test_case_1() { int Arg0 = 8; int Arg1 = 19; int Arg2 = 17; int Arg3 = 2093; int Arg4 = 12; int Arr5[] = {5, 161 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }
		void test_case_2() { int Arg0 = 53; int Arg1 = 13; int Arg2 = 9; int Arg3 = 65535; int Arg4 = 500; int Arr5[] = {244, 0 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }
		void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arg2 = 55; int Arg3 = 7890; int Arg4 = 123; int Arr5[] = {35, 4 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }

		// END CUT HERE

};

// BEGIN CUT HERE
KSubstring ___test;
int main()
{
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
