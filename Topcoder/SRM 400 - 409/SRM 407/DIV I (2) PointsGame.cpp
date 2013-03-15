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
#include <cmath>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
const int N = 540000;
map<vector<int>, double> dp;
class PointsGame {
	public:
	vector<int> x, y;
	double square(double x) {
		return x * x;
	}
	double result(vector<PII>& a, vector<PII>& b) {
		double res = 0;
		FOREACH(a, i) FOREACH(b, j) {
			res += sqrt(square(i->first - j->first) + square(i->second - j->second));
		}
		return res;
	}
	double DP(const vector<int>& mask, int depth, const int n) {
		map<vector<int>, double>::iterator iter = dp.find(mask);
		if(iter != dp.end()) {
			return iter->second;
		} else if(depth == n) {
			vector<PII> a, b;
			for(int i = 0;i < n;i++) {
				vector<PII>& ref = mask[i] == 2 ? b : a;
				ref.push_back(make_pair(x[i], y[i]));
			}
			return dp[mask] = result(a, b);
		}
		vector<int> next = mask;
		double _dp;
		if(depth & 1) {
			_dp = 1e10;
			for(int i = 0;i < n;i++) {
				if(next[i] == 0) {
					next[i] = 2;
					checkmin(_dp, DP(next, depth + 1, n));
					next[i] = 0;
				}
			}
		} else {
			_dp = 0;
			for(int i = 0;i < n;i++) {
				if(next[i] == 0) {
					next[i] = 1;
					checkmax(_dp, DP(next, depth + 1, n));
					next[i] = 0;
				}
			}
		}
		return dp[mask] = _dp;
	}
	double gameValue(vector <int> pointsX, vector <int> pointsY) {
		x.swap(pointsX);
		y.swap(pointsY);
		int n = x.size();
		vector<int> mask(n);
		dp.clear();
		return DP(mask, 0, n);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, gameValue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.198039027185569; verify_case(1, Arg2, gameValue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.0; verify_case(2, Arg2, gameValue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(3, Arg2, gameValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PointsGame ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
