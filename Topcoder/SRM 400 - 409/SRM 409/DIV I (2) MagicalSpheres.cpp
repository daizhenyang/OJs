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
class MagicalSpheres {
	public:
	int count(int x, int p)//x! contains p^ret
	{
		int ret = 0;
		while(x)
		{
			ret += x / p;
			x /= p;
		}
		return ret;
	}
	bool isOK(int n, int m, int g)
	{
		for(int k = 2;k * k <= g;k++)
		{
			int cnt = 0;
			while(g % k == 0)
			{
				cnt++;
				g /= k;
			}
			if(cnt > count(n, k) - count(m, k) - count(n - m, k))
				return false;
		}
		if(g != 1)
		{
			return 1 <= count(n, g) - count(m, g) - count(n - m, g);
		}
		return true;
	}
	int divideWork(int spheres, int fake, int gnomes) {
		for(int res = gnomes;res > 0;res--)
		{
			if(isOK(spheres + fake, spheres, res))
				return res;
		}
		return -1;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 2; verify_case(0, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 50; int Arg3 = 20; verify_case(1, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 4; int Arg3 = 1; verify_case(2, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15634; int Arg1 = 456; int Arg2 = 5000; int Arg3 = 4990; verify_case(3, Arg3, divideWork(Arg0, Arg1, Arg2)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	MagicalSpheres ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
