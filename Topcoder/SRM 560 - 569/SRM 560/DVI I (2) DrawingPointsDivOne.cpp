#line 2 "DrawingPointsDivOne.cpp"
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
const int N = 500;
int sum[N][N], A[N][N];
class DrawingPointsDivOne {
	public:
	bool checkStep(int step, const vector<int>& x, const vector<int>& y) {
		step++;
		memset(A, 0, sizeof(A));
		memset(sum, 0, sizeof(sum));
		REP(i, 0, x.size()) {
			int cx = x[i], cy = y[i];
			A[cx][cy]++, A[cx + step][cy + step]++;
			A[cx + step][cy]--, A[cx][cy + step]--;
		}
		REP(i, 1, N) REP(j, 1, N) {
			sum[i][j] = A[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
		REP(i, 1, N) REP(j, 1, N) {
			A[i][j] = (sum[i][j] >= 1);
		}
		REP(i, 1, N) REP(j, 1, N) {
			sum[i][j] = A[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
		int final = 0;
		//query a step * step square
		REP(i, step, N) REP(j, step, N) {
			int total = sum[i][j] - sum[i - step][j] - sum[i][j - step] + sum[i - step][j - step];
			if(total == step * step) final++;
		}
		return final == int(x.size());
	}
	int maxSteps(vector <int> x, vector <int> y) {
		int dx = *min_element(x.begin(), x.end());
		int dy = *min_element(y.begin(), y.end());
		REP(i, 0, x.size()) x[i] -= dx - 1, y[i] -= dy - 1;
		if(checkStep(N / 2, x, y)) return -1;
		int l = 1, r = N / 2, res = 0;
		while(l <= r) {
			int step = (l + r) / 2;
			if(checkStep(step, x, y)) {
				l   = step + 1;
				res = step;
			} else {
				r   = step - 1;
			}
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {39, 39}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50, 26}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(0, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
 -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
 -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(3, Arg2, maxSteps(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        DrawingPointsDivOne ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
