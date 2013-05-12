#line 2 "StrangeDictionary2.cpp"
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
const int N = 16;
const int M = 60;
double dp[1 << N];
int gless[M], gequal[M];

double DP(int cur, int L, int n) {
    dp[1 << cur] = 1.0;
    int total = 1 << n;
    for(int mask = (1 << cur) + 1;mask < total;mask++) {
        int C = 0;
        for(int l = 0;l < L;l++) {
            if(gless[l] & mask) {
                C++;
            } else if((gequal[l] & mask) != mask) {
                C++;
                dp[mask] += dp[mask & gequal[l]];
            }
        }
        dp[mask] /= C;
    }
    return dp[total - 1];
}
class StrangeDictionary2 {
public:
    vector <double> getProbabilities(vector <string> words) {
        int n = static_cast<int>(words.size());
        int L = static_cast<int>(words[0].size());
        vector<double> p;
        for(int i = 0;i < n;i++) {
            memset(gless,  0, sizeof(gless));
            memset(gequal, 0, sizeof(gequal));
            memset(dp, 0, sizeof(dp));
            for(int j = 0;j < n;j++) {
                for(int l = 0;l < L;l++) {
                    if(words[i][l] >  words[j][l]) {
                        gless[l] |= 1 << j;
                    }
                    if(words[i][l] == words[j][l]) {
                        gequal[l] |= 1 << j;
                    }
                }
            }
//            for(int l = 0;l < L;l++) printf("%d%c", gless[l] , l == L - 1 ? '\n' : ' ');
//            for(int l = 0;l < L;l++) printf("%d%c", gequal[l], l == L - 1 ? '\n' : ' ');
            p.push_back(DP(i, L, n));
        }
        return p;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"hardesttestever"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getProbabilities(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.5, 0.5 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getProbabilities(Arg0)); }
	void test_case_2() { string Arr0[] = {"aza", "aab", "bba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.3333333333333333, 0.5, 0.16666666666666666 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getProbabilities(Arg0)); }
	void test_case_3() { string Arr0[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getProbabilities(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    StrangeDictionary2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
