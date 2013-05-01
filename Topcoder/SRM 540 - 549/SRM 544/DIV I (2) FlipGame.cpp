#line 2 "FlipGame.cpp"
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
class FlipGame {
public:
    int minOperations(vector <string> board) {
        int res = 0, n = board.size(), m = board[0].size();
        while(true) {
            int col = 0;
            for(int i = 0;i < n;i++) {
                for(int j = col;j < m;j++) {
                    if(board[i][j] == '1') col = j + 1;
                }
                for(int j = 0;j < col;j++) board[i][j] ^= 1;
            }
            if(col == 0) break;
            res++;
        }
        return res;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1000",
 "1110",
 "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minOperations(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111",
 "1111",
 "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minOperations(Arg0)); }
	void test_case_2() { string Arr0[] = {"00",
 "00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minOperations(Arg0)); }
	void test_case_3() { string Arr0[] = {"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minOperations(Arg0)); }
	void test_case_4() { string Arr0[] = {"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 29; verify_case(4, Arg1, minOperations(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FlipGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
