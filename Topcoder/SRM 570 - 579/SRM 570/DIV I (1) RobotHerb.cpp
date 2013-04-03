#line 2 "RobotHerb.cpp"
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, -1, 0, 1};

pair<LL, LL> run_T_times(int T, const vector<int>& a) {
	LL x = 0, y = 0;
	int n = a.size(), dir = 0;
	for(int i = 0;i < T;i++) {
		for(int j = 0;j < n;j++) {
			x += DX[dir] * a[j];
			y += DY[dir] * a[j];
			dir = (dir + a[j]) % 4;
		}
	}
	return make_pair(x, y);
}

class RobotHerb {
public:
	long long getdist(int T, vector <int> a) {
		LL x = 0, y = 0;
		pair<LL, LL> f = run_T_times(4, a);
		x = f.first  * (T / 4);
		y = f.second * (T / 4);
		pair<LL, LL> s = run_T_times(T % 4, a);
		x += s.first;
		y += s.second;
		if(x < 0) x = -x;
		if(y < 0) y = -y;
		return x + y;
	}
};
// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

