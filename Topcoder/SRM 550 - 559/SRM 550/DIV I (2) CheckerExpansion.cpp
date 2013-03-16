#line 2 "CheckerExpansion.cpp"
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
#include <cassert>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const string unit[2] = {"A.B", ".B."};
//return pair<w, h>
pair<LL, LL> getBound(LL x, LL y) {
	LL w = 3, h = 2;
	while(w <= x || h <= y) {
		h <<= 1;
		w <<= 1;
		w  += 1;
	}
	return make_pair(w, h);
}
char query(LL w, LL h, LL x, LL y) {
	printf("%lld(%lld), %lld(%lld)\n", w, x, h, y);
	if(w == 3 && h == 2) {
		return unit[y][x];
	} else if(y >= 0 && x - y >= 0 && x + y < w / 2) {
		return query(w / 2, h / 2, x, y);
	} else if(y >= 0 && x - y > w / 2 && x + y <  w) {
		return query(w / 2, h / 2, x - w / 2 - 1, y);
	} else if(y >= h / 2 && x - y >= 0 && x + y < w) {
		return query(w / 2, h / 2, x - w / 2 / 2 - 1, y - h / 2);
	} else {
		return '.';
	}
}
class CheckerExpansion {
	public:
	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) {
		vector<string> grid(h, string(w, '.'));
		for(LL i = 0;i < h;i++) {
			for(LL j = 0;j < w;j++) {
				if((i + j + x0 + y0) / 2 < t) {
					cout << x0 + j << " " << y0 + i << endl;
					LL inw = getBound(j + x0, i + y0).first;
					LL inh = getBound(j + x0, i + y0).second;
					grid[i][j] = query(inw, inh, j + x0, i + y0);
				}
			}
		}
		reverse(grid.begin(), grid.end());
		return grid;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
