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
const int N = 20;
class StrIIRec {
public:
	int cost(int i, int state) {
		int res = 0;
		REP(k, 0, i) {
			res += ((state & (1 << k)) != 0);
		}
		return res;
	}
	string get_answer(int n, int tot, int minInv, string minStr) {
		string res = "";
		bool equal = true;
		int cur = 0;
		REP(step, 0, n) {
			bool find_nxt = false;
			int maxRev = max(0, (n - step - 1) * (n - step - 2) / 2);
			REP(nxt, 0, n) {
				if((tot & (1 << nxt)) == 0) continue;
				if((equal && minStr[step] <= nxt + 'a') || !equal) {
					if(cur + cost(nxt, tot ^ (1 << nxt)) + maxRev >= minInv) {
						find_nxt = true;
						tot ^= (1 << nxt);
						cur += cost(nxt, tot);
						res.push_back(nxt + 'a');
						equal &= (minStr[step] == nxt + 'a');
						break;
					}
				}
			}
			if(find_nxt == false) return "";
		}
		return res;
	}
	string recovstr(int n, int minInv, string minStr) {
		const int tot = (1 << n);
		minStr.append(n, 'a' - 1);
		string res = get_answer(n, tot - 1, minInv, minStr);
		return res;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }

	// END CUT HERE

};

// BEGIN CUT HERE
StrIIRec ___test;
int main()
{
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
