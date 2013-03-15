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
const int LEN = 1000;
class AllCycleLengths {
	public:
	bool find_circle(const string& res, int beg, int len)
	{
		string cir = res.substr(beg, len);
		const char* data = res.c_str();
		int tot = strlen(data);
		for(int i = beg;i + len < tot;i += len)
			if(strncmp(cir.c_str(), data + i, len) != 0)
				return false;
		return true;
	}
	string findAll(vector <string> arcs) {
		int n = arcs.size();
		vector<int> path(n), now(n);
		REP(i, 0, n)  REP(j, 0, n)
			path[i] |= (arcs[i][j] == 'Y' ? (1 << j) : 0);
		string res = "";
		REP(i, 0, n) now[i] |= (1 << i); 
		REP(k, 0, LEN)
		{
			vector<int> nxt(n);
			REP(i, 0, n) REP(j, 0, n) 
				if(now[i] & (1 << j)) nxt[i] |= path[j];
			char ch = '0';
			REP(i, 0, n) if(nxt[i] & (1 << i)) ch = '1';
			res.append(1, ch);
			now.swap(nxt);
		}
		for(int i = 0;i < LEN;i++)
		{
			for(int len = 1;len <= n;len++)
			{
				if(find_circle(res, i, len))
				{
					return res.substr(0, i) + "(" + res.substr(i, len) + ")";
				}
			}
		}
		return "";
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNNNNNNNNY", "NNNNYNNYNNN", "NNNNNNYNNNN", "NYNNNNNNNNN", "NNNNNYNNNNN", "NNNNNNNNYNN", "NNNNNNNNYNN", "NNNNNYNNNNN", "NNNNNNNNNYN", "YNNYNNNNNNN", "NNYNNNNYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(000001)"; verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(01)"; verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0(1)"; verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010(1)"; verify_case(3, Arg1, findAll(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	AllCycleLengths ___test;
	___test.run_test(0);
	return 0;
}
// END CUT HERE
