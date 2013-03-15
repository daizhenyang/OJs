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
class CrazyBot {
	public:
	double res;
	int n;
	int vst[40][40];
	int E, W, S, N;
	void dfs(int cur, int x, int y, double p) {
		if(vst[x][y]) {
			return;
		}
		if(cur == n) {
			res += p;
			return;
		}
		vst[x][y] = 1;
		if(E) dfs(cur + 1, x + 1, y, p * E / 100);
		if(W) dfs(cur + 1, x - 1, y, p * W / 100);
		if(S) dfs(cur + 1, x, y + 1, p * S / 100);
		if(N) dfs(cur + 1, x, y - 1, p * N / 100);
		vst[x][y] = 0;
	}
	double getProbability(int n, int east, int west, int south, int north) {
		res = 0;
		memset(vst, 0, sizeof(vst));
		this->n = n;
		E = east; W = west; S = south; N = north;
		dfs(0, 20, 20, 1.0);
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 1.0; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.75; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 50; int Arg2 = 0; int Arg3 = 0; int Arg4 = 50; double Arg5 = 1.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 50; int Arg2 = 50; int Arg3 = 0; int Arg4 = 0; double Arg5 = 1.220703125E-4; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 14; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.008845493197441101; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CrazyBot ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
