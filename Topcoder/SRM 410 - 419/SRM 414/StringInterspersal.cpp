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
class StringInterspersal {
	public:
	string minimum(vector <string> W) {
		string res = "";
		int n = accumulate(W.begin(), W.end(), string()).size();
		int m = W.size();
		FOREACH(W, i) i->append(1, 'Z' + 1);
		REP(i, 0, n) 
		{
			string* ptr = NULL;
			for(int j = 0;j < m;j++)
			{
				if(ptr == NULL || *ptr > W[j])
					ptr = &W[j];
			}
			res.append(1, *ptr->begin());
			ptr->erase(ptr->begin());
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"DESIGN","ALGORITHM","MARATHON"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ADELGMAORARISIGNTHMTHON"; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"TOMEK","PETR","ACRUSH","BURUNDUK","KRIJGERTJE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCKPERIJGERRTJETOMEKTRURUNDUKUSH"; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"CCCA","CCCB","CCCD","CCCE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCACCCBCCCCCCDE"; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"BKSDSOPTDD","DDODEVNKL","XX","PODEEE","LQQWRT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX"; verify_case(3, Arg1, minimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"TOPCODER","BETFAIR","NSA","BT","LILLY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBELILLNSATFAIRTOPCODERTY"; verify_case(4, Arg1, minimum(Arg0)); }
	void test_case_5() { string Arr0[] = {"QITHSQARQV","BYLHVGMLRY","LKMAQTJEAM","AQYICVNIKK","HKGZZFFEWC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC"; verify_case(5, Arg1, minimum(Arg0)); }
	void test_case_6() { string Arr0[] = {"XHCYBTUQUW","EKBISADSSN","LOOISPOFAK","MIXBDHPJUQ","BNMNDHMOTC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW"; verify_case(6, Arg1, minimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        StringInterspersal ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
