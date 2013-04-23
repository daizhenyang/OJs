#include <cstring>
#include <cmath>
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
const int N = 51;
bool dp[N][N * N];
class KingdomAndDice {
	public:
	vector<int> all;
	vector<pair<int, int> > pp;
	double newFairness(vector <int> fd, vector <int> sd, int X) {
		all.clear();
		pp.clear();
		copy(fd.begin(), fd.end(), back_inserter(all));
		copy(sd.begin(), sd.end(), back_inserter(all));
		sort(all.begin(), all.end());
		all.push_back(X + 1);
		sort(fd.begin(), fd.end());
		sort(sd.begin(), sd.end());

		int s = all.size();
		int win = 0;
		int n = fd.size(), cnt;
		int z = count(fd.begin(), fd.end(), 0);

		for(int i = 1;i < s;i++) {
			if(all[i - 1] + 1 >= all[i]) continue;
			int p = lower_bound(sd.begin(), sd.end(), all[i] - 1) - sd.begin();
			if(p != 0) {
				pp.push_back(make_pair(p, all[i] - all[i - 1] - 1));
			}
		}
		for(int i = 0;i < n;i++) {
			cnt  = lower_bound(sd.begin(), sd.end(), fd[i]) - sd.begin();
			win += cnt;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][win] = 1;
		for(int i = 0;i < pp.size();i++) {/* bag */
			for(int k = 1;k <= z && k <= pp[i].second;k++) {/* use */
				for(int j = z - 1;j >= 0;j--) {/* cur */
					for(int w = n * n - pp[i].first;w >= win;w--) {
						if(dp[j][w]) {
							dp[j + 1][w + pp[i].first] = 1;
						}
					}
				}
			}
		}
		double res = 0;
		int delta = n * n * 2;
		for(int j = win;j <= n * n;j++) {
			for(int i = 0;i <= z;i++) {
				if(dp[i][j]) {
					if(checkmin(delta, abs(n * n  - j * 2))) {
						res = j;
					}
				}
			}
		}
		return res / n / n;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 2, 7, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; double Arg3 = 0.4375; verify_case(0, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 2, 7, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; double Arg3 = 0.375; verify_case(1, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; double Arg3 = 0.5; verify_case(2, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {19, 50, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26, 100, 37}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 0.2222222222222222; verify_case(3, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; double Arg3 = 0.49; verify_case(4, Arg3, newFairness(Arg0, Arg1, Arg2)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	KingdomAndDice ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
