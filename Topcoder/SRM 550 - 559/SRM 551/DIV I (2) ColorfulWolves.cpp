#line 2 "ColorfulWolves.cpp"
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
#include <queue>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
const int kNUM = 50;
const int kINF = 0X3f3f3f3f;
int trans[kNUM][kNUM];
int dp[kNUM + 1][kNUM + 1];
class ColorfulWolves {
	public:
	int getmin(vector <string> colormap) {
		int n = colormap.size();
		memset(trans, 0, sizeof(trans));
		memset(dp, 0x3f, sizeof(dp));
		REP(i, 0, n) REP(j, 0, n) {
			trans[i][j] = (colormap[i][j] == 'Y');
		}
		REP(i, 0, n) dp[i][i] = 0;
		REP(i, 0, n) {
			int erase_ = 0;
			REP(j, 0, n) {
				if(trans[i][j])
					dp[i][j] = min(dp[i][j], erase_);
				erase_ += trans[i][j];
			}
		}
		REP(k, 0, n) {
			REP(i, 0, n) REP(j, 0, n)
				checkmin(dp[i][j], dp[i][k] + dp[k][j]);
		}
		return dp[0][n - 1] == kINF ? -1 : dp[0][n - 1];
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
