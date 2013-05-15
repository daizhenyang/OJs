#line 2 "SafeReturn.cpp"
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
#include <iterator>
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int N = 50;
const int INF = 1 << 20;
class SafeReturn {
public:
    vector<vector<int> > g;
    int v[N][N];
    int ym[N], chk[N];
        bool find_path(int x) {
            FOREACH(g[x], i) {
                if (chk[*i]) continue;
                    chk[*i] = true;
                        if (ym[*i] == -1 || find_path(ym[*i])) {
                            ym[*i] = x;
                                return true;
                        }
            }
            return false;
        }
        int solve(int n) {
            memset(ym, -1, sizeof(ym));
            int res = 0;
            for (int i = 0; i < n; i++) {
                memset(chk, 0, sizeof (chk));
                if (find_path(i)) res++;
            }
            return res;
        }
        int minRisk(int N, vector <string> streets) {
            g = vector<vector<int> >(N);
            int n = streets.size();
            REP(i, 0, n) REP(j, 0, n) {
                char ch = streets[i][j];
                v[i][j] = (ch == '-') ? INF : ch - '0';
            }
            REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) {
                checkmin(v[i][j], v[i][k] + v[k][j]);
            }
            for(int i = 0;i < N;i++) {
                for(int j = 0;j < N;j++) {
                    int a = i + 1, b = j + 1;
                    if(v[0][a] + v[a][b] == v[0][b]) {
                        g[i].push_back(j);
                    }
                }
            }
            return N - solve(N);
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"-234",
 "2---",
 "3---",
 "4---"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"-12",
 "1-1",
 "21-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; string Arr1[] = {"-11",
 "1-1",
 "11-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minRisk(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SafeReturn ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
