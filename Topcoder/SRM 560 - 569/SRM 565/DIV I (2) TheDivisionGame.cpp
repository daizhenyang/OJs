#line 2 "TheDivisionGame.cpp"
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
#include <cassert>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int N = 35000;
bool tags[N] ;
vector<LL> p;

void get_prime() {
	memset(tags, 1, sizeof(tags));
	p.clear();
	for(LL i = 2;i < N;i++) {
		if(tags[i] == 1) {
			p.push_back(i);
		}
		int n = p.size();
		for(LL j = 0;j < n && p[j] * i < N;j++) {
			tags[p[j] * i] = 0;
			if(i % p[j] == 0) break;
		}
	}
}
const int M = 1100000;
LL factor[M], value[M];
class TheDivisionGame {
public:
	LL countWinningIntervals(int L, int R) {
		get_prime();
		memset(factor, 0, sizeof(factor));
		int n = R - L + 1, bit[1024] = {1, 0};
		for(int i = 0;i < n;i++) {
			factor[i] = 0;
			value[i]  = i + L;
		}
		FOREACH(p, i) {
			for(LL j = (L % *i) ? *i - L % *i : 0; j < n;j += *i) {
				while(value[j] % *i == 0) {
					value[j] /= *i;
					factor[j]++;
				}
			}
		}
		for(int i = 0;i < n;i++) factor[i] += (value[i] != 1);
		LL res = 0, before = 0;
		for(int i = 0;i < n;i++) {
			res += bit[before ^= factor[i]]++;
		}
		return (1LL * n * (n + 1)) / 2 - res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const LL &Expected, const LL &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 10; LL Arg2 = 2LL; verify_case(0, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; LL Arg2 = 9LL; verify_case(1, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; LL Arg2 = 13LL; verify_case(2, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 100; LL Arg2 = 4345LL; verify_case(3, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12566125; int Arg1 = 12567777; LL Arg2 = 1313432LL; verify_case(4, Arg2, countWinningIntervals(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TheDivisionGame ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
