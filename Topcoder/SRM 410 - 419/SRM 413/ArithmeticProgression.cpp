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
const double EPS = 1e-6;
class ArithmeticProgression {
	public:
	double minCommonDifference(int a0, vector <int> seq) {
		LL a = 0, b = 1;
		// (seq[i] - a0) / (i + 1) > a / b
		int n = seq.size();
		REP(i, 0, n) 
			if((seq[i] - a0) * b > a * (i + 1)) {
				a = seq[i] - a0;
				b = i + 1;
			}
		REP(i, 0, n)
			if(seq[i] != floor(a0 + a * (i + 1) / b))
				return -1;
		return a * 1.0 / b;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arr1[] = {6, 13, 20, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.75; verify_case(0, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {3, 3, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.2; verify_case(3, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(4, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {6, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(5, Arg2, minCommonDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ArithmeticProgression ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
