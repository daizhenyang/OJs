#line 2 "WolfInZooDivOne.cpp"
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
const int N = 310;
const int MOD = 1000000007;
int dp[2][N][N];
const int INF = 100000000;
template<class T> 
void addMod(T& a, const T& b) {
    a += b;
    a %= MOD;
}
vector<int> reader(const string& str) {
    istringstream sin(str);
    vector<int> t;
    int v;
    while(sin >> v) t.push_back(v);
    return t;
}
class WolfInZooDivOne {
public:
    vector<int> g;
    int count(int n, vector <string> L, vector <string> R) {
        vector<int> l = reader(accumulate(L.begin(), L.end(), string("")));
        vector<int> r = reader(accumulate(R.begin(), R.end(), string("")));
        g = vector<int>(n + 1, INF);
        int m = l.size();
        REP(i, 0, m) l[i]++;
        REP(i, 0, m) r[i]++;
        for(int i = 0;i < m;i++) {
            for(int j = l[i];j <= r[i];j++) {
                checkmin(g[j], l[i]);
            }
        }
        int next = 0, prev = 1;
        memset(dp, 0, sizeof(dp));
        dp[next][0][0] = 1;
        for(int i = 0;i < n;i++) {
            next ^= 1;
            prev ^= 1;
            memset(dp[next], 0, sizeof(dp[next]));
            for(int j = 0;j <= i;j++) {
                for(int k = j;k <= i;k++) {
                    if(dp[prev][j][k]) {
                        addMod(dp[next][j][k], dp[prev][j][k]);
                        if(j < g[i + 1]) {
                            addMod(dp[next][k][i + 1], dp[prev][j][k]);
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int j = 0;j <= n;j++) {
            for(int k = j;k <= n;k++) {
                addMod(res, dp[next][j][k]);
            }
        }
        return res;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 5; string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 5; string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 10; string Arr1[] = {"0 4 2 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 9 5 9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 225; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 100; string Arr1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6419882; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WolfInZooDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

