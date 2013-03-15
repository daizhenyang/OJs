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
class TemplateMatching {
	public:
	int max_prefix(const string& text, const string& prefix) {
		string::size_type len = min(text.size(), prefix.size()), i;
		for(i = len;i != 0;i--) {
			if(text.substr(0, i) == prefix.substr(prefix.size() - i, i)) {
				return i;
			}
		}
		return 0;
	}
	string bestMatch(string text, string prefix, string suffix) {
		reverse(suffix.begin(), suffix.end());
		pair<int, int> res = make_pair(0, 0);
		string ret = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		for(string::size_type i = 0;i!= text.size();i++) {
			for(string::size_type len = 1;len <= text.size() - i;len++) {
				string t = text.substr(i, len);
				int pre = max_prefix(t, prefix);
				reverse(t.begin(), t.end());
				int suf = max_prefix(t, suffix);
				reverse(t.begin(), t.end());
				pair<int, int> tmp = make_pair(pre + suf, pre);
				if(tmp == res) {
					checkmin(ret, t);
				} else if(checkmax(res, tmp)) {
					ret = t;
				}
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "something"; string Arg1 = "awesome"; string Arg2 = "ingenious"; string Arg3 = "something"; verify_case(0, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "havka"; string Arg1 = "eto"; string Arg2 = "papstvo"; string Arg3 = "a"; verify_case(1, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abracadabra"; string Arg1 = "habrahabr"; string Arg2 = "bracket"; string Arg3 = "abrac"; verify_case(2, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "mississippi"; string Arg1 = "promise"; string Arg2 = "piccolo"; string Arg3 = "ippi"; verify_case(3, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "a a a a a a"; string Arg1 = "a a"; string Arg2 = "a"; string Arg3 = "a a"; verify_case(4, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "ab"; string Arg1 = "b"; string Arg2 = "a"; string Arg3 = "b"; verify_case(5, Arg3, bestMatch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TemplateMatching ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
