#line 2 "KingXNewCurrency.cpp"
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
class KingXNewCurrency {
public:
    static const int N = 50000; 
    bool dp[N]; 
    int howMany(int A, int B, int X) 
    { 
        int maxn = A * B; 
        vector<int> vec; 
        for(int i = 0;i * A <= maxn;i++) 
        { 
            for(int j = 0; i * A + j * B <= maxn;j++) 
            { 
                vec.push_back(i * A + j * B); 
            } 
        } 
        int res = 0; 
        CC(dp, 0); 
        dp[0] = 1; 
        for(int j = X;j <= maxn;j++) 
            dp[j] |= dp[j - X]; 
        bool neg = true; 
        FOREACH(vec, i) 
        { 
            if(dp[*i] == false) 
            { 
                neg = false; 
                break; 
            } 
        } 
        if(neg) return -1; 
        for(int i = 1;i <= 2000;i++) 
        { 
            if(i == X) continue; 
            CC(dp, 0); 
            dp[0] = 1; 
            for(int j = X;j <= maxn;j++) 
                dp[j] |= dp[j - X]; 
            for(int j = i;j <= maxn;j++) 
                dp[j] |= dp[j - i]; 
            bool flag = true; 
            FOREACH(vec, j) 
            { 
                if(dp[*j] == false) 
                { 
                    flag = false; 
                    break; 
                } 
            } 
            res += flag; 
        } 
        return res; 
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 5; int Arg3 = 5; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 13; int Arg3 = 1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 44; int Arg3 = 2; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 96; int Arg2 = 3; int Arg3 = 65; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    KingXNewCurrency ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
