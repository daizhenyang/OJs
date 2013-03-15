#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <cassert>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
int dp[2][1 << 13];
int cost[1 << 13];
const int INF = 1 << 20;
class CavePassage {
public:
	struct state {
		int s, mask, dst;
		state(){}
		state(int s, int mask, int dst) : s(s), mask(mask), dst(dst){}
		bool operator < (const state& a) const {
			return this->dst > a.dst;
		}
	};
	/* DP is wrong, circle state */
	int DP(const int state, const int mask, const int n) {
		if(dp[state][mask] != -1) return dp[state][mask];
		int full = (1 << n) - 1;
		if(state == 1 && mask == full)  return 0;
		dp[state][mask] = INF;
		int tot = state == 0 ? full - mask : mask;
		for(int nxt = tot;nxt != 0;nxt = tot & (nxt - 1)) {
			if(cost[nxt] != -1) {
				checkmin(dp[state][mask], (DP(1 ^ state, mask ^ nxt, n) + cost[nxt]));
			}
		}
		return dp[state][mask];
	}

	priority_queue<state> pq;
	int solve(int n) {
		pq.push(state(0, 0, 0));
		REP(i, 0, (1 << n)) {
			dp[0][i] = dp[1][i] = INF;
		}
		dp[0][0] = 0;
		int full = (1 << n) - 1;
		while(!pq.empty()) {
			state now = pq.top();pq.pop();
			int tot = (now.s == 0 ? (full - now.mask) : now.mask);
			if(dp[now.s][now.mask] < now.dst) {
				continue;
			}
			for(int nxt = tot;nxt != 0; nxt = (nxt - 1) & tot) {
				if(cost[nxt] != -1 && dp[1 ^ now.s][now.mask ^ nxt] > now.dst + cost[nxt]) {
					pq.push(state(1 ^ now.s, now.mask ^ nxt, now.dst + cost[nxt]));
					dp[1 ^ now.s][now.mask ^ nxt] = now.dst + cost[nxt];
				}
			}
		}
		return dp[1][full];
	}
	bool check(vector<string>& trust, int nxt, int n) {
		vector<int> pass;
		REP(i, 0, n) {
			if(nxt & (1 << i)) {
				pass.push_back(i);
			}
		}
		if(pass.size() == 1) return true;
		FOREACH(pass, i) {
			bool found = 0;
			FOREACH(pass, j) {
				if(*i == *j) continue;
				found = found || (trust[*i][*j] == 'Y');
			}
			if(found == false)
				return false;
		}
		return true;
	}
	int minimalTime(vector<int> travelersWeights, vector<int> travelersTimes, vector<string> trustTable, int bridgeStrength) {
		memset(dp,   -1, sizeof(dp));
		memset(cost, -1, sizeof(cost));
		int n      = travelersWeights.size();
		REP(i, 1, (1 << n)) {
			int totw = 0, sp = 0;
			REP(j, 0, n) {
				if(i & (1 << j)) {
					totw += travelersWeights[j];
					checkmax(sp, travelersTimes[j]);
				}
			}
			if(check(trustTable, i, n) && totw <= bridgeStrength) {
				cost[i] = sp;
			}
		}
		int res = DP(0, 0, n);
		return res == INF ? -1 : res;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "YYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 9; verify_case(0, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "NYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 10; verify_case(1, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 3, 3, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "YYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 5; verify_case(2, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {891, 23, 673, 923, 983, 867, 348, 945, 120, 23, 24, 999, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {891, 23, 673, 923, 983, 867, 348, 945, 120, 23, 24, 999, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YNYYYNYNYNYNY", "YYYYYNYNYYYNY", "YNYYYNYNYNYNY", "YNYYYNYYYNNNY", "YNYYYNYNYNYYY", "YNYYYYYNYNYNY", "YNYYYNYNYNYNY", "NNNYYNYYYNYNY", "YNYYYNYNYNYYY", "YNYYYNYNYYYNY", "YNYNYNYNYNYNY", "YNYYNNYNYNYYY", "YNNYYNYNYNYNY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3000; int Arg4 = 2858; verify_case(3, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	CavePassage ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
