#line 2 "Stamp.cpp"
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
const int V = 100;
const int INF = 1 << 29;
class Stamp {
public:
    int solve(const string& color, int n, int length, int cost) {
        int dp[V][3];
        for(int i = 0;i < V;i++) for(int j = 0;j < 3;j++) dp[i][j] = INF;
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i = length;i <= n;i++) {
            int r = 0, g = 0, b = 0;
            for(int j = i - length;j < i;j++) {
                if(color[j] == 'R') r = 1;
                if(color[j] == 'G') g = 1;
                if(color[j] == 'B') b = 1;
            }
            int each[3] = {r, g, b};
            for(int k = 0;k < 3;k++) {
                if(each[k] == r + g + b) {
                    checkmin(dp[i][k], dp[i - length][0] + cost);
                    checkmin(dp[i][k], dp[i - length][1] + cost);
                    checkmin(dp[i][k], dp[i - length][2] + cost);
                    for(int j = i - length;j < i;j++) {
                        checkmin(dp[i][k], dp[j][k] + cost);
                    }
                }
            }
        }
        return *min_element(dp[n], dp[n] + 3);
    }
    int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
        int minCost = 1 << 30, n = desiredColor.size();
        for(int length = 1;length <= n;length++) {
            int dp = solve(desiredColor, n, length, pushCost) + stampCost * length;
            checkmin(minCost, dp);
        }
        return minCost;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Stamp ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
