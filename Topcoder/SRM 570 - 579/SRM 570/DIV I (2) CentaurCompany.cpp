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
const int N = 38;
double dp[N][2][N][N];
vector<vector<int> > g;
void DP(int root, int prev, int n) {
	double f[2][2][N][N];
        int cur = 0, nxt = 1;
	memset(f[cur], 0, sizeof(f[cur]));
	// not chosed
	f[cur][0][0][0] = 0.5;
	// chosed
	f[cur][1][1][1] = 0.5;
	FOREACH(g[root], i) {
		if(*i == prev) continue;
		DP(*i, root, n);
		memset(f[nxt], 0, sizeof(f[nxt]));
		for(int curGroup = 0;curGroup <= n;curGroup++) for(int curServer = curGroup;curServer <= n;curServer++) {
			for(int group = 0;group + curGroup <= n;group++) for(int server = group;server + curServer <= n;server++) {
				// not chosed
				if(f[cur][0][curGroup][curServer] != 0) {
					f[nxt][0][curGroup + group][curServer + server] += 
						f[cur][0][curGroup][curServer] * dp[*i][0][group][server];
					f[nxt][0][curGroup + group][curServer + server] += 
						f[cur][0][curGroup][curServer] * dp[*i][1][group][server];
				}
				// chosed
				if(f[cur][1][curGroup][curServer] != 0 && curGroup + group - 1 >= 0) {
					f[nxt][1][curGroup + group][curServer + server] += 
						f[cur][1][curGroup][curServer] * dp[*i][0][group][server];
					f[nxt][1][curGroup + group - 1][curServer + server] += 
						f[cur][1][curGroup][curServer] * dp[*i][1][group][server];
				}
			}
		}
		cur ^= 1;
		nxt ^= 1;
	}
	for(int group = 0;group <= n;group++) for(int server = group;server <= n;server++) {
		dp[root][0][group][server] = f[cur][0][group][server];
		dp[root][1][group][server] = f[cur][1][group][server];
	}
}
int cost(int server, int group) {
	return max(0, (group - 1) * 2 - server);
}
class CentaurCompany {
	public:
		double getvalue(vector <int> a, vector <int> b) {
			int n = a.size() + 1;
			g.assign(n, vector<int>());
			for(int i = 0;i < n - 1;i++) {
				a[i]--, b[i]--;
				g[a[i]].push_back(b[i]);
				g[b[i]].push_back(a[i]);
			}
			memset(dp, 0, sizeof(dp));
			DP(0, -1, n);
			double res = 0;
			for(int group = 0;group <= n;group++) for(int server = 0;server <= n;server++) {
				res += cost(server, group) * dp[0][1][group][server];
				res += cost(server, group) * dp[0][0][group][server];
			}
			return res * 2;
		}
};
// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
