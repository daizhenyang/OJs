#line 2 "LeftRightDigitsGame2.cpp"
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
const int N = 51;
string dp[N][N][3][3];
bool mask[N][N][3][3];
// 0 less 1 equal 2 greater
class LeftRightDigitsGame2 {
public:
    string digit, lower;
    int n;
    string DP(int start, int end, int cmpx, int cmpy) {
        bool & used = mask[start][end][cmpx][cmpy];
        string &  res = dp[start][end][cmpx][cmpy];
        if(used) {
            return res;
        }
        used = true;
        if(cmpx == 0) {
            return res = "~";
        }
        if(start + end == n) {
            if(cmpx == 0 || (cmpx == 1 && cmpy == 0)) return res = "~";
            return res = "";
        }
        res = "~";
        string tmp;
        int pos = start + end;
        int cmpx2 = cmpx;
        if(cmpx == 1) {
            if(digit[pos] < lower[start]) cmpx2 = 0;
            if(digit[pos] > lower[start]) cmpx2 = 2;
        }
        tmp = DP(start + 1, end, cmpx2, cmpy);
        if(tmp != "~") {
            checkmin(res, digit[pos] + DP(start + 1, end, cmpx2, cmpy));
        }
        int cmpy2 = cmpy;
        if(digit[pos] < lower[n - end - 1]) cmpy2 = 0;
        if(digit[pos] > lower[n - end - 1]) cmpy2 = 2;
        tmp = DP(start, end + 1, cmpx, cmpy2);
        if(tmp != "~") {
            checkmin(res, DP(start, end + 1, cmpx, cmpy2) + digit[pos]);
        }
        return res;
    }
    string minNumber(string digits, string lowerBound) {
        digit = digits;
        reverse(digit.begin(), digit.end());
        lower = lowerBound;
        n = digit.size();
        memset(mask, 0, sizeof(mask));
        string res = DP(0, 0, 1, 1);
        if(res == "~") return "";
        return res;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "565"; string Arg1 = "556"; string Arg2 = "556"; verify_case(0, Arg2, minNumber(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "565"; string Arg1 = "566"; string Arg2 = "655"; verify_case(1, Arg2, minNumber(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "565"; string Arg1 = "656"; string Arg2 = ""; verify_case(2, Arg2, minNumber(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "9876543210"; string Arg1 = "5565565565"; string Arg2 = "5678943210"; verify_case(3, Arg2, minNumber(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "8016352"; string Arg1 = "1000000"; string Arg2 = "1086352"; verify_case(4, Arg2, minNumber(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LeftRightDigitsGame2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
