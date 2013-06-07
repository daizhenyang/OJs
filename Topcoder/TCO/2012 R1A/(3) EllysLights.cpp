#line 2 "EllysLights.cpp"
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
const int N = 128;
int graph[N][N], used[N], seach[N][2];
class EllysLights {
public:
    int getMinimum(string initial, vector <string> switches) {
        memset(graph, 0, sizeof(graph));
        memset(seach,-1, sizeof(seach));
        memset(used,  0, sizeof(used));
        int N = initial.size();
        int M = switches.size();
        REP(i, 0, N) REP(j, 0, M) {
            if(switches[j][i] == 'Y') {
                if(seach[i][0] == -1) {
                    seach[i][0] = j << 1;
                } else {
                    seach[i][1] = j << 1;
                }
            }
        }
        REP(i, 0, (2 * M)) graph[i][i] = 1;
        REP(i, 0, N) {
            int len = (seach[i][0] != -1) + (seach[i][1] != -1);
            if(len == 0 && initial[i] == 'Y') return -1;
            if(len == 1) {
                used[seach[i][0] + (initial[i] != 'Y')] = 1;
            } else if(len == 2) {
                if(initial[i] == 'Y') {
                    graph[seach[i][0] + 1][seach[i][1]] = graph[seach[i][0]][seach[i][1] + 1] = 1;
                    graph[seach[i][1] + 1][seach[i][0]] = graph[seach[i][1]][seach[i][0] + 1] = 1;
                } else {
                    graph[seach[i][0] + 1][seach[i][1] + 1] = graph[seach[i][0]][seach[i][1]] = 1;
                    graph[seach[i][1] + 1][seach[i][0] + 1] = graph[seach[i][1]][seach[i][0]] = 1;
                }
            }
        }
        REP(k, 0, (2 * M)) REP(i, 0, (2 * M)) REP(j, 0, (2 * M)) {
            graph[i][j] |= (graph[i][k] && graph[k][j]);
        }
        REP(i, 0, (2 * M)) {
            if(used[i]) REP(j, 0, (2 * M)) {
                if(graph[i][j]) used[j] = 1;
            }
        }
        REP(i, 0, (2 * M)) if(graph[i][i ^ 1] && graph[i ^ 1][i]) return -1;
        REP(i, 0, (2 * M)) if(used[i] == 1 && used[i ^ 1] == 1) return -1;
        for(int i = 0;i < 2 * M;i += 2) {
            if(used[i] == 0 && used[i ^ 1] == 0) {
                int cnt0 = 0, cnt1 = 0;
                for(int j = 0;j < 2 * M;j += 2) {
                    if(graph[i][j]) cnt0++;
                    if(graph[i ^ 1][j]) cnt1++;
                }
                for(int j = 0;j < 2 * M;j++) {
                    if(cnt0 <  cnt1 && graph[i][j])     used[j] = 1;
                    if(cnt0 >= cnt1 && graph[i ^ 1][j]) used[j] = 1;
                }
            }
        }
        int res = 0;
        for(int i = 0;i < 2 * M;i += 2) {
            res += used[i];
        }
        return res;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYNNN"; string Arr1[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "YNYNYN"; string Arr1[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "YYN"; string Arr1[] = {"YNY", "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "NNYNYNYYYNNYYYYN"; string Arr1[] = {"NYNYNYNYNYNYNYNY",
 "YNYNYNYNYNYNYNYN",
 "NNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNN",
 "NNNNYNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNN",
 "NNNNNNYNNNNNNNNN",
 "NNNNNNNYNNNNNNNN",
 "NNNNNNNNYNNNNNNN",
 "NNNNNNNNNYNNNNNN",
 "NNNNNNNNNNYNNNNN",
 "NNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNYN",
 "NNNNNNNNNNNNNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
 "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
 "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
 "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
 "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
 "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
 "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
 "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EllysLights ___test;

    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
