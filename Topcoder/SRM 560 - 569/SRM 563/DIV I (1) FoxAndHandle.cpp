#line 2 "FoxAndHandle.cpp"
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
const int N = 256;
class FoxAndHandle {
	public:
	int total[N], currB[N], currA[N];
	bool check[N];
	bool canPut(const string& S, char ch, int pos) {
		int newB[N] = {0, };
		REP(i, 0, pos) {
			newB[int(S[i])] += !check[i];
		}
		REP(i, 0, N) {
			if(newB[i] + currB[i] > total[i]) {
				return false;
			}
		}
		REP(i, 0, N)   currB[i] += newB[i];
		REP(i, 0, pos) check[i] = true;
		return true;
	}
	string lexSmallestName(string S) {
		memset(total, 0, sizeof(total));
		memset(currB, 0, sizeof(currB));
		memset(currA, 0, sizeof(currA));
		memset(check, 0, sizeof(check));
		int n = S.size();
		REP(i, 0, n) total[int(S[i])]++;
		REP(i, 0, N) total[i] /= 2;
		string result = "";
		REP(j, 0, n / 2) {
			for(char ch = 'a';ch <= 'z';ch++) {
				int pos = -1;
				REP(i, 0, n) {
					if(!check[i] && ch == S[i]) {
						pos = i;
						break;
					}
				}
				if(pos != -1 && currA[ch] < total[ch] && canPut(S, ch, pos)) {
					result.push_back(ch);
					check[pos] = 1;
					currA[ch] += 1;
					break;
				}
			}
		}
		return result;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "foxfox"; string Arg1 = "fox"; verify_case(0, Arg1, lexSmallestName(Arg0)); }
	void test_case_1() { string Arg0 = "ccieliel"; string Arg1 = "ceil"; verify_case(1, Arg1, lexSmallestName(Arg0)); }
	void test_case_2() { string Arg0 = "abaabbab"; string Arg1 = "aabb"; verify_case(2, Arg1, lexSmallestName(Arg0)); }
	void test_case_3() { string Arg0 = "bbbbaaaa"; string Arg1 = "bbaa"; verify_case(3, Arg1, lexSmallestName(Arg0)); }
	void test_case_4() { string Arg0 = "fedcbafedcba"; string Arg1 = "afedcb"; verify_case(4, Arg1, lexSmallestName(Arg0)); }
	void test_case_5() { string Arg0 = "nodevillivedon"; string Arg1 = "deilvon"; verify_case(5, Arg1, lexSmallestName(Arg0)); }

	// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	FoxAndHandle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
