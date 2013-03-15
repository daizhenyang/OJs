#line 2 "PenguinEmperor.cpp"
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
const int N  = 350;
const int MOD = 1e9 + 7;
class PenguinEmperor {
	public:
	vector<int> Move(const vector<int>& current, const vector<int>& movement, int n) {
		vector<int> result(n);
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				result[(i + j) % n] += (1LL * current[i] * movement[j]) % MOD;
				result[(i + j) % n] %= MOD;
			}
		}
		return result;
	}
	vector<int> power(const vector<int>& current, LL x, int n) {
		vector<int> result(n), A = current;
		result[0] = 1;
		while(x > 0) {
			if((x & 1) != 0) {
				result = Move(result, A, n);
			}
			A = Move(A, A, n);
			x >>= 1;
		}
		return result;
	}
	int countJourneys(int n, LL daysPassed) {
		vector<int> current(n), rest(n), result(n);
		rest[0] = current[0] = 1;
		for(int i = 1;i <= n;i++) {
			vector<int> movement(n);
			movement[i % n] = 1;
			movement[n - i] = 1;
			current = Move(current, movement, n);
			if(i == daysPassed % n) {
				rest = current;
			}
		}
		result = power(current, daysPassed / n, n);
		result = Move(result, rest, n);
		return result[0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 2LL; int Arg2 = 2; verify_case(0, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 3LL; int Arg2 = 2; verify_case(1, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 36LL; int Arg2 = 107374182; verify_case(2, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 300; long long Arg1 = 751LL; int Arg2 = 413521250; verify_case(3, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 300; long long Arg1 = 750LL; int Arg2 = 0; verify_case(4, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 350; long long Arg1 = 1000000000000000000LL; int Arg2 = 667009739; verify_case(5, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5; long long Arg1 = 7LL; int Arg2 = 12; verify_case(6, Arg2, countJourneys(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        PenguinEmperor ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
