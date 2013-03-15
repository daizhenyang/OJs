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
typedef pair<int, int> PII;
class IngredientProportions {
	public:
	vector <int> getMasses(vector <string> proportions) {
		map<PII, PII> ingredient;
		int n = proportions.size();
		for(int i = 0;i < n;i++) {
			int a = proportions[i][1] - '0';
			int b = proportions[i][8] - '0';
			int p = proportions[i][13] - '0';
			int q = proportions[i][15] - '0';
			int gcd =__gcd(p, q);
			p /= gcd, q /= gcd;
			ingredient[make_pair(a, b)] = make_pair(p, q);
		}
		vector<LL> res(n + 1, 1);
		bool flag = false;
		do {
			flag = false;
			FOREACH(ingredient, i) {
				LL& a = res[i->first.first];
				LL& b = res[i->first.second];
				int p = i->second.first;
				int q = i->second.second;
				if(a * q != b * p) {
					flag = true;
					LL x = p * b, y = q * a;
					LL gcd = __gcd(x, y);
					x /= gcd, y /= gcd;
					a *= x, b *= y;
				}
			}
		}while(flag);
		vector<int> ret(n + 1);
		LL gcd = __gcd(res[0], res[1]);
		for(int i = 2;i <= n;i++) {
			gcd = __gcd(res[i], gcd);
		}
		for(int i = 0;i <= n;i++) ret[i] = res[i] / gcd;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#0 and #1 as 6:4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMasses(Arg0)); }
	void test_case_1() { string Arr0[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {81, 72, 64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMasses(Arg0)); }
	void test_case_2() { string Arr0[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105, 35, 21, 15, 105 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMasses(Arg0)); }
	void test_case_3() { string Arr0[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60, 20, 63, 84 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMasses(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        IngredientProportions ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
