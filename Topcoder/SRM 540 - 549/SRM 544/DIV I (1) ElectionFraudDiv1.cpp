#line 2 "ElectionFraudDiv1.cpp"
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
const int N = 2000;
class ElectionFraudDiv1 {
public:
    int min_sat(int p, int n) {
        int l = 0, r = n, res = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int v   = (100 * mid + n / 2) / n;
            if(v == p) {
                res = mid;
                r = mid - 1;
            } else if(v < p) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
    int max_sat(int p, int n) {
        int l = 0, r = n, res = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int v   = (100 * mid + n / 2) / n;
            if(v == p) {
                res = mid;
                l = mid + 1;
            } else if(v < p) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
    int MinimumVoters(vector <int> p) {
        int n = p.size();
        for(int res = 1;res <= N;res++) {
            bool is_valid = true;
            int minn = 0, maxn = 0;
            for(int j = 0;j < n;j++) {
                int min_ = min_sat(p[j], res);
                int max_ = max_sat(p[j], res);
                if(min_ == -1 || max_ == -1) {
                    is_valid = false;
                    break;
                }
                minn += min_;
                maxn += max_;
            }
            if(is_valid && minn <= res && res <= maxn) {
                return res;
            } 
        }
        return -1;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {33, 33, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, MinimumVoters(Arg0)); }
    void test_case_1() { int Arr0[] = {29, 29, 43}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, MinimumVoters(Arg0)); }
    void test_case_2() { int Arr0[] = {12, 12, 12, 12, 12, 12, 12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, MinimumVoters(Arg0)); }
    void test_case_3() { int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, MinimumVoters(Arg0)); }
    void test_case_4() { int Arr0[] = {0, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; verify_case(4, Arg1, MinimumVoters(Arg0)); }
    void test_case_5() { int Arr0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 97; verify_case(5, Arg1, MinimumVoters(Arg0)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ElectionFraudDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
