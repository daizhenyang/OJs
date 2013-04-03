#line 2 "PolygonTraversal.cpp"
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
const int M = 18;
LL dp[M][1 << M];
class PolygonTraversal {
public:
    long long count(int N, vector <int> points) {
        memset(dp, 0, sizeof(dp));
        int n = points.size(), start = 0;
        REP(i, 0, n) {
            points[i]--;
            start |= (1 << points[i]);
        }
        dp[points[n - 1]][start] = 1;
        for(int mask = start;mask < (1 << N);mask++) {
            int sum[M], tot = 0;
            memset(sum, 0, sizeof(sum));
            for(int j = 0;j < N;j++) {
                if(mask & (1 << j)) sum[j] = 1, tot++;
                if(j) sum[j] += sum[j - 1];
            }
            for(int j = 0;j < N;j++) {
                if((mask & (1 << j)) == 0 || dp[j][mask] == 0) continue;
                for(int i = 0;i < N;i++) {
                    if((mask & (1 << i))) continue;
                    int mid = 0;
                    if(j < i) {
                        mid = sum[i] - sum[j];
                    } else {
                        mid = sum[j] - sum[i] - 1;
                    }
                    if(mid != 0 && mid != tot - 1) {
                        dp[i][mask | (1 << i)] += dp[j][mask];
                    }
                }
            }
        }
        LL res = 0;
        for(int i = 0;i < N;i++) {
            if((i + 1) % N != points[0] && (i + N - 1) % N != points[0]) {
                res += dp[i][(1 << N) - 1];
            }
        }
        return res;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 18; int Arr1[] = {1, 7, 18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4374612736LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PolygonTraversal ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
