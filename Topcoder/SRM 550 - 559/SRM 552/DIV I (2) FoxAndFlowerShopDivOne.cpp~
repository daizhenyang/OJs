#line 2 "FoxAndFlowerShopDivOne.cpp"
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
#include <cassert>
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int NUM = 31;
const int DIF = 1801;
const int HLF = 900;
int diff[DIF << 2], ll[DIF << 2], rr[DIF << 2];
void build(int l, int r, int n) {
	int mid = (l + r) / 2;
	diff[n] = -1;
	ll[n]   = l;
       	rr[n]   = r;
	if(l == r) {
		return;
	}
	build(l, mid, n << 1);
	build(mid + 1, r, (n << 1) | 1);
}
void insert(int pos, int v, int n) {
	int mid = (ll[n] + rr[n]) / 2;
	if(ll[n] == rr[n]) {
		checkmax(diff[n], v);
		return ;
	}
	if(pos <= mid) {
		insert(pos, v, n << 1);
	} else {
		insert(pos, v, (n << 1) | 1);
	}
	diff[n] = max(diff[n << 1], diff[(n << 1) | 1]);
}
int query(int l, int r, int n) {
	int mid = (ll[n] + rr[n]) / 2;
	if(ll[n] == l && rr[n] == r) {
		return diff[n];
	}
	if(r <= mid) {
		return query(l, r, n << 1);
	} else if(mid < l) {
		return query(l, r, (n << 1) | 1);
	} else {
		return max(query(l, mid, (n << 1)), query(mid + 1, r, (n << 1) | 1));
	}
}
class FoxAndFlowerShopDivOne {
	public:
	int suml[NUM][NUM], sump[NUM][NUM];
	void update(int r, int value) {
		r = min(DIF - 1, r + HLF);
		insert(r, value, 1);
	}
	int queryDiff(int l, int r) {
		l = max(0, l + HLF);
		r = min(DIF - 1, r + HLF);
		return query(l, r, 1);
	}
	int solve(const vector<string>& flowers, int maxDiff) {
		int n = flowers.size(), m = flowers[0].size();
		int result = -1;
		build(0, DIF - 1, 1);
		memset(suml, 0, sizeof(suml));
		memset(sump, 0, sizeof(sump));
		REP(i, 0, n) REP(j, 0, m) {
			suml[i + 1][j + 1] = suml[i + 1][j] + suml[i][j + 1] - suml[i][j] + (flowers[i][j] == 'L');
			sump[i + 1][j + 1] = sump[i + 1][j] + sump[i][j + 1] - sump[i][j] + (flowers[i][j] == 'P');
		}
		memset(diff, -1, sizeof(diff));
		// -maxDiff <= ll - pp <= maxDiff
		for(int i = 1;i < n;i++) {
			for(int j = 1;j <= m;j++) {
				for(int a = 1;a <= i;a++) for(int b = 1;b <= j;b++) {
					//(a, b) -> (i, j)
					int ll = suml[i][j] - suml[i][b - 1] - suml[a - 1][j] + suml[a - 1][b - 1];
					int pp = sump[i][j] - sump[i][b - 1] - sump[a - 1][j] + sump[a - 1][b - 1];
					update(ll - pp, pp + ll);
				}
			}
			for(int j = 1;j <= m;j++) {
				for(int a = i + 1;a <= n;a++) for(int b = j;b <= m;b++) {
					//(i + 1, j) -> (a, b);
					int ll = suml[a][b] - suml[a][j - 1] - suml[i][b] + suml[i][j - 1];
					int pp = sump[a][b] - sump[a][j - 1] - sump[i][b] + sump[i][j - 1];
					int tp = queryDiff(pp - ll - maxDiff, pp - ll + maxDiff);
					if(tp != -1) checkmax(result, tp + ll + pp);
				}
			}
		}
		return result;
	}
	int theMaxFlowers(vector <string> flowers, int maxDiff) {
		int n = flowers.size(), m = flowers[0].size();
		vector<string> flips;
		REP(j, 0, m) {
			string t;
			REP(i, 0, n) t.append(1, flowers[i][j]);
			flips.push_back(t);
		}
		return max(solve(flowers, maxDiff), solve(flips, maxDiff));
	}


};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
