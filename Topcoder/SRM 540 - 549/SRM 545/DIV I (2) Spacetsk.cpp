#line 2 "Spacetsk.cpp"
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
const int N = 2100;
const int M = 1000000007;
LL dp[N][N], len[N];
class Spacetsk {
public:
    int countsets(int L, int H, int K) {
        if(K == 1) return (L + 1) * (H + 1);
        memset(dp,  0, sizeof(dp));
        memset(len, 0, sizeof(len));
        dp[0][0] = 1;
        for(int i = 1;i < N;i++) {
            dp[i][i] = dp[i][0] = 1;
            for(int j = 1;j < i;j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % M;
            }
        }
        for(int dx = 0;dx <= L;dx++) {
            for(int dy = 1;dy <= H;dy++) {
                if(__gcd(dx, dy) == 1) {
                    int ty = H / dy + 1;
                    if(dx == 0) {
                        len[ty] += L + 1;
                    } else {
                        for(int tx = 1;;tx++) {
                            int low  = dx * (tx - 1);
                            int high = min(L + 1, dx * tx);
                            if(low >= high) break;
                            len[min(ty, tx)] += (high - low) << 1;
                        }
                    }
                }
            }
        }
        LL res = 0;
        for(int i = 0;i < N;i++) {
//            printf("%lld%c", len[i], i == N ? '\n' : ' ');
            res = (res + (len[i] * dp[i][K]) % M) % M;
        }
        return res;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; verify_case(1, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 9; verify_case(2, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 23; verify_case(3, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 202; verify_case(4, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 561; int Arg1 = 394; int Arg2 = 20; int Arg3 = 786097180; verify_case(5, Arg3, countsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Spacetsk ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
