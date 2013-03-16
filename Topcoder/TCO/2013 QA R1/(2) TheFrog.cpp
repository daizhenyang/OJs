#line 2 "TheFrog.cpp"
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
#include <cmath>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int N = 30000;
const double INF = 1e10;
class TheFrog {
	public:
	double minStep(LL D, const vector<int>& L, const vector<int>& R) {
		if(D == 0) return INF;
		int n = L.size();
		double result = INF;
		for(int step = N;step >= 1;step--) {
			bool can = true;
			for(int i = 0;i < n;i++) {
				if(L[i] * step / D * D + D < R[i] * step) {
					can = false;
					break;
				}
			}
			if(can) result = min(result, D * 1.0 / step);
		}
		return result;
	}
	double getMinimum(int D, vector <int> L, vector <int> R) {
		double result = minStep(D, L, R);
		for(int i = 0;i < int(L.size());i++) {
			checkmin(result, min(minStep(L[i], L, R), minStep(R[i], L, R)));
		}
		return result;
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
