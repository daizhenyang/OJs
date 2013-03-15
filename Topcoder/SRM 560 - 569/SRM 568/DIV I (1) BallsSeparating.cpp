#line 2 "BallsSeparating.cpp"
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
#define REP(i, l, n) for(int i = l;i < int(n);++i)
typedef long long LL;
 
const int INF = 2e9;
class BallsSeparating {
	public:
	vector<int> RED, BLUE, GREEN;
	int choose(int select) {
		return min(RED[select] + BLUE[select], 
				min(RED[select] + GREEN[select], 
					BLUE[select] + GREEN[select]));
	}
	int move2Target(int i, int j, int k) {
		int result = 0, n = RED.size();
		for(int select = 0;select < n;select++) {
			if(i == select) {
				result += BLUE[select] + GREEN[select];
			} else if(j == select) {
				result += RED[select] + GREEN[select];
			} else if(k == select) {
				result += RED[select] + BLUE[select];
			} else {
				result += choose(select);
			}
		}
		return result;
	}
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		RED   = red;
		GREEN = green;
		BLUE  = blue;
		int n = red.size(), result = INF;
		REP(i, 0, n) REP(j, 0, n) REP(k, 0, n) {
			if(i == k || j == k || i == j) continue;
			result = min(result, move2Target(i, j, k));
		}
		return result == INF ? -1 : result;
	}
};
// BEGIN CUT HERE
int main()
{
	for(int i = 0;i < 50;i++) {
		printf("%d ", 1000000);
	}
	BallsSeparating ___test;
	return 0;
}
// END CUT HERE
