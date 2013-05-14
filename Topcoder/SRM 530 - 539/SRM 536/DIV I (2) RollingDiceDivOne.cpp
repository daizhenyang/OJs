// BEGIN CUT HERE

// END CUT HERE
#line 5 "RollingDiceDivOne.cpp"
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


class RollingDiceDivOne
{
        public:
        long long mostLikely(vector <int> dice)
        {
		sort(dice.begin(), dice.end());
		LL lo = 1, hi = *dice.rbegin();
		for(vector<int>::reverse_iterator ri = dice.rbegin() + 1;ri != dice.rend();++ri)
		{
			LL d = *ri;
			if(d > hi - lo + 1)
			{
				d -= hi - lo + 1;
				lo = hi + d / 2 + 1;
				hi = hi + (d + 1) / 2 + 1;
			}
			else
			{
				lo = lo + d;
				hi = hi + 1;
			}
		}
		return lo;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 6, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 11LL; verify_case(0, Arg1, mostLikely(Arg0)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, mostLikely(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(2, Arg1, mostLikely(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 10, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(3, Arg1, mostLikely(Arg0)); }
	void test_case_4() { int Arr0[] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4366828428LL; verify_case(4, Arg1, mostLikely(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RollingDiceDivOne ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

