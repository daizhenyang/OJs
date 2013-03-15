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
const int INF = 1e9;
class CakesEqualization {
	public:
	vector<int> w, x;
	double get_delta(int n) {
		double minn =  INF;
		double maxn = -INF;
		REP(i, 0, n) {
			checkmax(maxn, w[i] * 1.0 / x[i]);
			checkmin(minn, w[i] * 1.0 / x[i]);
		}
		return maxn - minn;
	}
	double fairDivision(vector <int> weights, int maxCuts) {
		int n = weights.size();
		w = weights;
		x.assign(n, 1);
		double res = get_delta(n);
		for(int i = 0;i <  maxCuts;i++) {
			double maxn = -INF;
			int idx = -1;
			REP(j, 0, n) {
				if(checkmax(maxn, w[j] * 1.0 / x[j]))
					idx = j;
			}
			x[idx]++;
			checkmin(res, get_delta(n));
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.0; verify_case(0, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.0; verify_case(1, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.5; verify_case(2, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7, 11, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arg2 = 0.3999999999999999; verify_case(3, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13, 69, 41, 37, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; double Arg2 = 1.4666666666666668; verify_case(4, Arg2, fairDivision(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CakesEqualization ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
