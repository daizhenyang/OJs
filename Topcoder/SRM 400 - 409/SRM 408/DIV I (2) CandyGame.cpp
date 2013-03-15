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
class CandyGame {
	public:
	static const int N = 50;
	int dep[N], man[N], n;
	vector<string> g;
	void dfs(int now, int pre, int depth)
	{
		man[now] = dep[now] = depth;
		REP(i, 0, n)
		{
			if(i != pre && g[now][i] == 'Y')
			{
				dfs(i, now, depth + 1);
				checkmax(man[now], man[i]);
			}
		}
	}
	int maximumCandy(vector<string> graph, int target) {
		g = graph;
		n = g.size();
		memset(dep, -1, sizeof(dep));
		memset(man, -1, sizeof(man));
		dfs(target, -1, 0);
		LL res = 0;
		for(int i = 0;i < n;i++)
		{
			if(i == target) continue;
			if(dep[i] == -1) return -1;
			res += 1LL << (man[i] - dep[i]);
		}
		if(res > 2000000000LL) return -1;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN", "YNY", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYN", "YNY", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYYY", "YNNN", "YNNN", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(2, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYYY", "YNNN", "YNNN", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(3, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNYN",
 "YNYNYNN",
 "NYNYNNN",
 "NNYNNNN",
 "NYNNNNN",
 "YNNNNNY",
 "NNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 11; verify_case(4, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(5, Arg2, maximumCandy(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CandyGame ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
