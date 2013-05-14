// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysCheckers.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
template<class T> void string_reader(string s, vector<T>& vec){
    istringstream sin(s);
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
const int N = 19;
int state[1 << N];
class EllysCheckers
{
public:
	int n, beg, maxn;
	string get_str(int now)
	{
		string ret = "";
		REP(i, 0, n)
			if((now & (1 << i)) != 0)
				ret.append(1, '1');
			else
				ret.append(1, '0');
		ret.append(2, '0');
		return ret;
	}
	int DP(int now)
	{
		if(state[now] != -1) return state[now];
		state[now] = 0;
		string bit = get_str(now);
		for(int i = 0;i < n;i++)
		{
			if(bit[i] == '0') continue;
			int tmp = (now ^ (1 << i));
			int nxt = (1 << (i + 1));
			tmp = (tmp | nxt) & maxn;
			if(bit[i + 1] == '0')
				state[now] |= (DP(tmp) == 0);
			if(i + 3 <= n)
			{
				int cnt = bit[i + 1] == '1' && bit[i + 2] == '1';
				tmp = (now ^ (1 << i));
				nxt = (1 << (i + 3));
				tmp = (tmp | nxt) & maxn;
				if(bit[i + 3] == '0' && cnt == 2)
				{
					state[now] |= (DP(tmp) == 0);
				}
			}
		}
		return state[now];
	}
	string getWinner(string board)
	{
		CC(state, -1);
		n = board.size() - 1;
		beg = 0;
		maxn = (1 << n) - 1;
		REP(i, 0, n)
		{
			beg |= ((board[i] == 'o') << i);
		}
		return DP(beg) ? "YES" : "NO";
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	EllysCheckers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE

