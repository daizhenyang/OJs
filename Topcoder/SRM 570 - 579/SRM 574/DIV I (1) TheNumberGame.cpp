#line 2 "TheNumberGame.cpp"
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
class TheNumberGame {
public:
    string int2string(int A) {
        char buf[1024];
        sprintf(buf, "%d", A);
        return string(buf);
    }
    bool check_sub_str(const string& A, const string& B) {
        int n = A.size();
        for(int i = 0;i < n;i++) {
            for(int j = i;j < n;j++) {
                if(B == A.substr(i, j - i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    string determineOutcome(int A, int B) {
        string strA = int2string(A);
        string strB = int2string(B);
        if(check_sub_str(strA, strB)) {
            return string("Manao wins");
        } else {
            reverse(strB.begin(), strB.end());
            if(check_sub_str(strA, strB)) {
                return string("Manao wins");
            } else {
                return string("Manao loses");
            }
        }
    } 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 45; int Arg1 = 4; string Arg2 = "Manao wins"; verify_case(0, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 45; int Arg1 = 5; string Arg2 = "Manao wins"; verify_case(1, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 123; string Arg2 = "Manao loses"; verify_case(2, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2356236; int Arg1 = 5666; string Arg2 = "Manao loses"; verify_case(3, Arg2, determineOutcome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheNumberGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
