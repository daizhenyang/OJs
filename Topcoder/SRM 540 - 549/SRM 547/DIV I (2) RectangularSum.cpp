#line 2 "RectangularSum.cpp"
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
#include <iterator>
#include <climits>
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int N = 1500000;
const LL INF = 1LL << 50;
bool solve(LL S, LL p, LL q, LL height, LL width) {
    if(S % (p * q) != 0 || p > height || q > width) return false;
    S -= (p * q * (q - 1)) + (p * (p - 1) * width * q);
    if(S >= 0 && S % (p * q * 2) == 0) {
        LL a = S / (p * q * 2);
        if(a % width + q <= width && a / width + p <= height) {
            return true;
        }
    }
    return false;
}
class RectangularSum {
public:
    long long minimalArea(int height, int width, long long S) {
        vector<LL> f;
        S <<= 1;
        for(int i = 1;i < N;i++) {
            if(S % i == 0) f.push_back(i);
        }
        LL res = INF;
        for(int i = 0;i < int(f.size());i++) {
            for(int j = 0;j < int(f.size());j++) {
                if(solve(S, f[i], f[j], height, width)) {
                    checkmin(res, f[i] * f[j]);
                }
            }
        }
        return res == INF ? -1 : res;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; long long Arg2 = 8LL; long long Arg3 = 4LL; verify_case(0, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 10LL; long long Arg3 = -1LL; verify_case(1, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 36LL; long long Arg3 = 9LL; verify_case(2, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 25; long long Arg2 = 16000LL; long long Arg3 = 32LL; verify_case(3, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; long long Arg2 = 1000000000000LL; long long Arg3 = 2LL; verify_case(4, Arg3, minimalArea(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RectangularSum ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
