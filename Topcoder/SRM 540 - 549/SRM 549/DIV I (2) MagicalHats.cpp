#line 2 "MagicalHats.cpp"
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
const int N = 14;
const int M = 1600000;
const int INF = 0x3f3f3f3f;

int dp[M];
int encode(const int * a, int n) {
    int mask = 0, bit = 1;
    for(int i = 0;i < n;i++) {
        mask += a[i] * bit;
        bit *= 3;
    }
    return mask;
}

void decode(int mask, int * a, int n) {
    for(int i = 0;i < n;i++) {
        a[i] = mask % 3;
        mask /= 3;
    }
}

class MagicalHats {
public:
    int n_row, n_col, h, g;
    vector<int> coins;
    vector<pair<int, int> > hats;
    int pow3[N + 1];

    bool is_valid(int * mask, int s) {
        static int col[N], row[N];
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        for(int i = 0;i < s;i++) {
            if(mask[i] == 1) {
                row[hats[i].first ]++;
                col[hats[i].second]++;
            } else if(mask[i] == 2) {
                row[hats[i].first ] += 2;
                col[hats[i].second] += 2;
            }
        }
//        REP(i, 0, s) printf("%d%c", mask[i], i == s - 1 ? '\n' : ' ');
//        REP(i, 0, n_row) printf("%d%c", row[i], i == n_row - 1 ? '\n' : ' ');
//        REP(i, 0, n_row) printf("%d%c", col[i], i == n_col - 1 ? '\n' : ' ');
//        printf("%d %d\n", count(mask, mask + s, 2), int(coins.size()));
        REP(i, 0, n_row) if(row[i] & 1) return false;
        REP(i, 0, n_col) if(col[i] & 1) return false;
        return count(mask, mask + s, 2) == int(coins.size());
    }
    int DP(int num, int mask) {
        int &res = dp[mask], code[N];
        if(res != -1) return res;
        decode(mask, code, h);
        if(num == h) {
            return (res = is_valid(code, h) ? 0 : -INF);
        }
        res = -INF;
        int two = count(code, code + h, 2);
        for(int j = 0;j < h;j++) {
            if(code[j] != 0) continue;
            int t1 = -INF, t2 = -INF;
            {
                code[j] = 1;
                int new_mask = encode(code, h);
                checkmax(t1, DP(num + 1, new_mask));
            }
            if(two < int(coins.size())) {
                code[j] = 2;
                int new_mask = encode(code, h);
                checkmax(t2, DP(num + 1, new_mask) + (num < g));
            }
            if(t1 < 0) checkmax(res, t2);
            if(t2 < 0) checkmax(res, t1);
            if(t1 >= 0 && t2 >= 0) checkmax(res, min(t1, t2));
            code[j] = 0;
        }
        return res;
    }
    int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
        n_row = board.size();
        n_col = board[0].size();
        g = numGuesses;
        sort(coins.begin(), coins.end());
        this->coins = coins;
        hats.clear();
        REP(i, 0, n_row) REP(j, 0, n_col) {
            if(board[i][j] == 'H') hats.push_back(make_pair(i, j));
        }
        h = hats.size();
        for(int i = 1;i <= h;i++) pow3[i] = pow3[i - 1] * 3;

        memset(dp, -1, sizeof(dp));
        int res = DP(0, 0);
        return res < 0 ? -1 : accumulate(coins.begin(), coins.begin() + res, 0);
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"HHH",
 "H.H",
 "HH."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 9; verify_case(1, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"HH",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 13; verify_case(3, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 26; verify_case(4, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"H.H.",
 ".H.H",
 "H.H."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = -1; verify_case(5, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,337,1007,2403,5601,6003,9999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 1377; verify_case(6, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 22; verify_case(7, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MagicalHats ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
