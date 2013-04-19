#line 2 "TheExperiment.cpp"
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
const int N = 310;
const int M = 1000000009;
int dp[N][N][3], sum[N];
void trans(int& a, int add) {
    a += add;
    if(a >= M) a -= M;
}
class TheExperiment {
public:
    int countPlacements(vector <string> intensity, int m, int L, int A, int B) {
        string r = accumulate(intensity.begin(), intensity.end(), string(""));
        int n = r.size();
        REP(i, 0, n) sum[i + 1] = sum[i] + r[i] - '0';
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j <= m;j++) {
                trans(dp[i + 1][j][0], dp[i][j][0]);
                trans(dp[i + 1][j][0], dp[i][j][2]);
                for(int l = 1;l <= L && i + l <= n && j < m;l++) {
                    int v = sum[i + l] - sum[i];
                    if(A <= v && v <= B) {
                        trans(dp[i + l][j + 1][2], dp[i][j][2]);
                        if(l == L) {
                            trans(dp[i + l][j + 1][2], dp[i][j][0]);
                            trans(dp[i + l][j + 1][2], dp[i][j][1]);
                        } else {
                            trans(dp[i + l][j + 1][1], dp[i][j][0]);
                            trans(dp[i + l][j + 1][1], dp[i][j][1]);
                        }
                    }
                }
            }
        }
        return (dp[n][m][0] + dp[n][m][2]) % M;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"341156"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 6; int Arg4 = 10; int Arg5 = 2; verify_case(0, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"999112999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 21; int Arg4 = 30; int Arg5 = 2; verify_case(1, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; verify_case(2, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"59059", "110", "1132230231"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 20; int Arg5 = 6; verify_case(3, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 8; int Arg3 = 4; int Arg4 = 2700; int Arg5 = 418629948; verify_case(4, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheExperiment ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
