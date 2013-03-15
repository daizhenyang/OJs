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
class RevealTriangle {
	public:
	vector<string> res;
	vector <string> calcTriangle(vector <string> question) {
		res = question;
		int n = question.size();
		while(true)
		{
			for(int i = n - 1;i > 0;i--)
			{
				int m = res[i].size();
				REP(j, 0, m)
				{
					if(res[i][j] == '?' && res[i - 1][j] != '?' && res[i - 1][j + 1] != '?')
					{
						int a = (res[i - 1][j] - '0' + res[i - 1][j + 1] - '0') % 10;
						res[i][j] = a + '0';
					}
				}
			}
			for(int i = n - 2;i >= 0;i--)
			{
				int m = res[i].size();
				REP(j, 0, m - 1)
				{
					if(res[i][j] == '?' && res[i + 1][j] != '?' && res[i][j + 1] != '?')
					{
						int a = (res[i + 1][j] - res[i][j + 1] + 10) % 10;
						res[i][j] = a + '0';
					}
				}
				REP(j, 1, m)
				{
					if(res[i][j] == '?' && res[i][j - 1] != '?' && res[i + 1][j - 1] != '?')
					{
						int a = (res[i + 1][j - 1] - res[i][j - 1] + 10) % 10;
						res[i][j] = a + '0';
					}
				}
			}
			string ret = accumulate(res.begin(), res.end(), string(""));
			int cnt = count(ret.begin(), ret.end(), '?');
			if(cnt == 0) break;
		}
		return res;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"4??", 
		"?2", 
		"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"457", "92", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcTriangle(Arg0)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcTriangle(Arg0)); }
	void test_case_2() { string Arr0[] = {"???2", "??2", "?2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0002", "002", "02", "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcTriangle(Arg0)); }
	void test_case_3() { string Arr0[] = {"??5?", "??9", "?4", "6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7054", "759", "24", "6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcTriangle(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	RevealTriangle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
