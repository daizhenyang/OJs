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
#include <iterator>
#include <sstream>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
template<class T> void string_reader(string s, vector<T>& vec){
	istringstream sin(s);
	copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
typedef long long LL;
const int N = 13;
const static int INF = 10000000;
int state[1 << N];
vector<vector<int> > v;
class FoldThePaper {
	public:
	void getMask(const vector<int>& vec) {
		FOREACH(vec, i) state[*i] = true;
		int s = vec.size();
		for(int i = 1;i < s;i++) {
			vector<int> mask(max(s - i, i));
			for(int j = 0;j < s;j++) {
				if(j >= i) {
					mask[j - i] |= vec[j];
				} else {
					mask[i - j - 1] |= vec[j];
				}
			}
			getMask(mask);
		}
	}
	int getValue(vector <string> paper) {
		int n = paper.size();
		v = vector<vector<int> >(n);
		REP(i, 0, n) string_reader(paper[i], v[i]);
		int m =  v[0].size();
		vector<int> row, col;
		memset(state, 0, sizeof(state));
		REP(i, 0, n) row.push_back(1 << i);
		getMask(row);
		row.clear();
		REP(i, 0, 1 << n) if(state[i]) row.push_back(i);

		memset(state, 0, sizeof(state));
		REP(i, 0, m) col.push_back(1 << i);
		getMask(col);
		col.clear();
		REP(i, 0, 1 << m) if(state[i]) col.push_back(i);

		int res = -INF;
		FOREACH(row, i) FOREACH(col, j) {
			int value = 0;
			REP(ii, 0, n) REP(jj, 0, m) {
				if((*i & (1 << ii)) && (*j & (1 << jj))) {
					value += v[ii][jj];
				}
			}
			checkmax(res, value);
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"1 1 1",
"1 1 1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getValue(Arg0)); }
	void test_case_1() { string Arr0[] = {
"1 -1",
"1 -1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getValue(Arg0)); }
	void test_case_2() { string Arr0[] = {
"1 -1 -1 1",
"-1 -1 -1 -1",
"-1 -1 -1 -1",
"1 -1 -1 1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, getValue(Arg0)); }
	void test_case_3() { string Arr0[] = {
"20 13 -2 100",
"-12 0 4 -3",
"4 1 -36 21"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 131; verify_case(3, Arg1, getValue(Arg0)); }
	void test_case_4() { string Arr0[] = {
"0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        FoldThePaper ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
