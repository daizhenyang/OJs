#line 2 "FoxPaintingBalls.cpp"
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
class FoxPaintingBalls {
	public:
	long long theMax(long long R, long long G, long long B, int N) {
		//total % 3 == 1 || total % 3 == 0
		LL total = (N + 1LL) * N / 2;
		LL each  = total / 3;
		if(N == 1) {
			return R + G + B;
		} else if(total % 3 == 0) {
			return min(R, min(G, B)) / each;
		} else {
			LL result = 0;
			LL l = 0, r = R + G + B;
			while(l <= r) {
				LL mid = (r + l) / 2;
				if(min(R, min(G, B)) / each >= mid && R + G + B - 3 * mid * each >= mid) {
					result = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			return result;
		}
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
