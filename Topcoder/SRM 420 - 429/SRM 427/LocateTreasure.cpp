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
class LocateTreasure {
	public:
	int dig(int x) {
		return x % 9 == 0 ? 9 : x % 9;
	}
	int deal(int beg, int n, int multi) {
		vector<int> res;
		int ret = 0, s = min(n, N);
		REP(i, 0, s) {
			res.push_back(dig(beg));
			beg = (beg % 9 * multi) % 9;
		}
		if(n <= N) {
			FOREACH(res, i) {
				ret += *i;
			}
		} else {
			printf("%d\n", n);
			REP(i, 0, s) printf("%d%c", res[i], i == s - 1 ? '\n' : ' ');
			REP(i, 0, s) {
				const vector<int>::iterator _end = res.begin() + i;
				vector<int>::iterator iter = find(res.begin(), _end, res[i]);
				if(iter == _end) continue;
				int cnt = 0;
				for(vector<int>::iterator j = res.begin();j != iter;j++) {
					cnt++;
					ret += *j;
				}
				int cur = i - (iter - res.begin());
				int nn = n - cnt, cir = accumulate(iter, _end, 0);
				ret += cir * (nn / cur) + accumulate(iter, iter + nn % cur, 0);
				break;
			}
		}
		cout << ret << endl;
		return ret;
	}
	string location(int K, int multi) {
		int beg = 1, db = 1;
		REP(i, 0 , 4) {
			db = db * multi % 9;
		}
		int d[4] = {};
		REP(i, 0, 4) {
			int n = K / 4 + (K % 4 > i);
			d[i] = deal(beg, n, db);
			beg = beg * multi % 9;
		}
		char buf[100];
		sprintf(buf, "%d %d", d[1] - d[3], d[0] - d[2]);
		return string(buf);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; string Arg2 = "-6 4"; verify_case(0, Arg2, location(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 99; int Arg1 = 1; string Arg2 = "1 0"; verify_case(1, Arg2, location(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5226; int Arg1 = 4; string Arg2 = "10 -2"; verify_case(2, Arg2, location(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        LocateTreasure ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
