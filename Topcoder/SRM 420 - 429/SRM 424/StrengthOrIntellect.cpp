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

const int N = 1001;
int dp[N][N];
class StrengthOrIntellect {
	public:
	vector<int> S, I, P;
	int numberOfMissions(vector <int> strength, vector <int> intellect, vector <int> points) {
		S = strength;
		I = intellect;
		P = points;
		int n = points.size();
		memset(dp, 0, sizeof(dp));
		int res = 0;
		REP(i, 1, N) REP(j, 1, N) {
			int cnt = 0,rest = 0;
			REP(k, 0, n) {
				if(strength[k] <= i || intellect[k] <= j) {
					cnt++;
					rest += points[k];
				}
			}
			rest -= i + j - 2;
			dp[i][j] = (i == 1 && j == 1) || dp[i - 1][j] || dp[i][j - 1];
			if(dp[i][j]) {
				checkmax(res, cnt);
			}
			dp[i][j] &= rest > 0;
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {396, 314, 389, 48, 21, 9, 236, 80, 640, 244, 25, 412, 193, 161, 345, 618, 215, 89, 589, 52, 320, 140, 271, 643, 296, 265, 434, 679, 42, 194, 240, 336, 325, 185, 311, 262, 2, 278, 115, 238, 97, 302, 593, 530, 480, 627, 126, 516}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {308, 304, 489, 73, 133, 258, 602, 27, 802, 635, 597, 700, 262, 219, 54, 249, 248, 341, 28, 63, 773, 646, 586, 251, 392, 564, 502, 810, 648, 699, 429, 793, 753, 129, 500, 165, 576, 707, 151, 123, 275, 676, 780, 256, 422, 132, 760, 321}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 21, 7, 8, 21, 13, 1, 13, 6, 19, 14, 16, 17, 10, 3, 13, 14, 6, 12, 7, 7, 12, 11, 14, 12, 21, 11, 6, 3, 13, 7, 5, 3, 9, 6, 5, 6, 20, 14, 20, 7, 11, 6, 2, 21, 13, 13, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(0, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 3, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 3, 20, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 1, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 100, 5, 100, 10, 100, 17, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 100, 3, 100, 7, 100, 13, 100, 21}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(3, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1, 10, 1, 2, 16, 12, 13, 19, 12, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 1, 8, 3, 5, 3, 16, 19, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 2, 1, 1, 2, 3, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(4, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        StrengthOrIntellect ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
