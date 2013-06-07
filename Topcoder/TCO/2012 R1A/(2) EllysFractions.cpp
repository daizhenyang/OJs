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
class EllysFractions {
public:
	static const int N = 251;
	bool isPrime(int x)
	{
		for(int j = 2;j * j <= x;j++)
			if(x % j == 0) return false;
		return true;
	}
	int cnt[N];
	long long getCount(int n) {
		vector<int> p;
		CC(cnt, 0);
		REP(i, 2, N) if(isPrime(i)) p.push_back(i);
		LL res = 0;
		for(int i = 2;i <= n;i++)
		{
			REP(j, 0, p.size()) if(i % p[j] == 0) cnt[j] = 1;
			int ret = count(cnt, cnt + N, 1);
			res += (1LL << (ret - 1));
		}
		return res;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 1LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 3LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arg0 = 5; long long Arg1 = 9LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { int Arg0 = 100; long long Arg1 = 177431885LL; verify_case(4, Arg1, getCount(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	EllysFractions ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
