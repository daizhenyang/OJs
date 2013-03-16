#line 2 "ColorfulChocolates.cpp"
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
class ColorfulChocolates {
	public:
	int maximumSpread(string chocolates, int maxSwaps) {
		int result = 0, n = chocolates.size();
		for(char ch = 'A';ch <= 'Z';ch++) {
			for(int i = 0;i < n;i++) {
				vector<int> cost;
				if(chocolates[i] != ch) continue;
				for(int j = i - 1, pos = i - 1;j >= 0;j--) {
					if(chocolates[j] == ch) {
						cost.push_back(pos - j);
						pos--;
					}
				}
				for(int j = i + 1, pos = i + 1;j < n;j++) {
					if(chocolates[j] == ch) {
						cost.push_back(j - pos);
						pos++;
					}
				}
				sort(cost.begin(), cost.end());
				int length = 1, used = 0;
				for(int i = 0;i < int(cost.size()) && used + cost[i] <= maxSwaps;i++) {
					used += cost[i];
					length++;
				}
				checkmax(result, length);
			}
		}
		return result;
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
