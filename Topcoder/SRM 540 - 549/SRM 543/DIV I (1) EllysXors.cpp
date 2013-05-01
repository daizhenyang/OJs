#line 2 "EllysXors.cpp"
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
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int N = 60;
LL count_one(LL v, LL bit) {
    LL turn = ((v) / (bit << 1)), rest = (v) % (bit << 1);
    LL num_count = turn * bit;
    if(rest >= bit) {
        num_count += rest % bit;
    }
    return num_count;
}
class EllysXors {
public:
    long long getXor(long long L, long long R) {
        R++;
        LL res = 0;
        for(int i = 0;i < N;i++) {
            LL b = 1LL << i;
            LL r_count = count_one(R, b);
            LL l_count = count_one(L, b);
            if((r_count + l_count) & 1) {
                res |= b;
            }
        }
        return res;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 10LL; long long Arg2 = 8LL; verify_case(0, Arg2, getXor(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 5LL; long long Arg2 = 5LL; verify_case(1, Arg2, getXor(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 42LL; long long Arg2 = 39LL; verify_case(2, Arg2, getXor(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 666LL; long long Arg1 = 1337LL; long long Arg2 = 0LL; verify_case(3, Arg2, getXor(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1234567LL; long long Arg1 = 89101112LL; long long Arg2 = 89998783LL; verify_case(4, Arg2, getXor(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EllysXors ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
