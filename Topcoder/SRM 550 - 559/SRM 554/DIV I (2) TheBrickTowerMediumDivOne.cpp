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
class TheBrickTowerMediumDivOne {
	public:
	vector <int> find(vector <int> heights) {
		size_t n = heights.size();
		int min_ele = *min_element(heights.begin(), heights.end());
		size_t pos = std::find(heights.begin(), heights.end(), min_ele) - heights.begin();
		vector<int> res(n), check(n);
		int pre = 1e9, cur = 0;
		for(size_t i = 0, j;i < n;i++) {
			for(j = 0;j < pos;j++) {
				if(heights[j] <= pre && check[j] == 0) {
					break;
				}
			}
			if(j == pos) {
				break;
			}
			pre = heights[j];
			check[j] = 1;
			res[cur++] = j;
		}
		pre = heights[pos];
		for(size_t i = 0, j;i < n;i++) {
			int minn = 1e9, index = -1;
			for(j = 0;j < n;j++) {
				if(check[j] == 0 && checkmin(minn, heights[j])) {
					index = j;
				}
			}
			if(index == -1) {
				break;
			}
			pre = heights[index];
			check[index] = 1;
			res[cur++] = index;
		}
		return res;
	}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
