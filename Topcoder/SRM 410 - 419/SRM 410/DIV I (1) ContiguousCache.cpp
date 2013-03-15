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
const int N = 128;
const LL  INF = 1LL << 60;
class ContiguousCache {
	public:
	LL dp[N][N];
	bool is_in(int x, int k, int now) {
		return x <= now && now < x + k;
	}
	int _abs(int x) {
		return x < 0 ? -x : x;
	}
	LL cost(int l, int r, int k) {
		if(is_in(l, k, r) || is_in(r, k, l)) {
			return _abs(r - l);
		} else {
			return k;
		}
	}
	long long minimumReads(int n, int k, vector <int> addr) {
		vector<int> endp;
		endp.push_back(-k);
		endp.push_back(n - k + 1);
		FOREACH(addr, i) {
			if(*i + k - 1 <= n) endp.push_back(*i);
			if(1 <= *i - k + 1) endp.push_back(*i - k + 1);
		}
		REP(i, 0, N) fill(dp[i], dp[i] + N, INF);
		sort(endp.begin(), endp.end());
		endp.erase(unique(endp.begin(), endp.end()), endp.end());
		dp[0][0] = 0;
		int s = addr.size(), m = endp.size();
		REP(i, 0, s) {
			REP(j, 0, m) {
				if(dp[i][j] == INF) continue;
				REP(nxt, 0, m) {
					if(is_in(endp[nxt], k, addr[i]) == false) continue; 
					checkmin(dp[i + 1][nxt], dp[i][j] + cost(endp[j], endp[nxt], k));
				}
			}
		}
		return *min_element(dp[s], dp[s] + m);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 3; int Arr2[] = {0, 2, 16, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 10; int Arr2[] = {1,10,19,28,30,37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 29LL; verify_case(1, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000000; int Arg1 = 500000000; int Arr2[] = {0, 999999999, 1, 500000000, 500000001, 987654321}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1987654320LL; verify_case(2, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 2; int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(3, Arg3, minimumReads(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ContiguousCache ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
