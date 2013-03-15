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
class AlternateColors2 {
public:
	long long countWays(int n, int k) {
		LL res = 0;
		// min(b, g) <= r, i equal to min(b, g)
		for(int i = 0;i * 3 <= n;i++) {
			LL add = 0;
			if(i * 3 < k) {
				//min(b, g) * 3 <  k
				LL rest = k - i * 3;
				// before k (b, g) is over (with b == g)
				//rest == 1 -> r
				//rest == 2 -> rr
				//rest == 3 -> rbr | rgr | rrr
				//rest == 4 -> rbrr | rgrr | rrrr
				//rest == 5 -> rbrrr | rgrrr| rbrbr | rgrgr | rrrrr
				add += (rest - 1) / 2 * 2 + 1;
				// b or g exists after k
				if((rest & 1) == 1) {
					add += (n - k) << 1;
				}
			} else {
				//min(b, g) * 3 >= k
				if(k % 3 == 1) {
					LL rest = n - i * 3 - 1;
					// b == g
					add++;
					// b != g
					add += (rest + 1) * 2;
				}
			}
			res += add;
		}
		//min(b, g) >  r, i equal to r
		for(int i = 1;i * 3 + 2 <= n;i++) {
			LL rest = n - i * 3 - 2, add = 0;
			if(k % 3 == 1 && i * 3 > k) {
				add += (rest + 1);
			}
			res += add;
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 3LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; long long Arg2 = 9LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; long long Arg2 = 21LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 100000; long long Arg2 = 1666700000LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        AlternateColors2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
