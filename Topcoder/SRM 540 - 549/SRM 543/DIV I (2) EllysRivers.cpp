#line 2 "EllysRivers.cpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <utility>
using namespace std;
typedef long long LL;
const int M = 110000;
const double INF = 1e20;
double dp[2][M];
class EllysRivers {
public:
    double getMin(int length, int walk, vector <int> width, vector <int> speed) {
        int prev = 0, next = 1, n = width.size();
        for(int i = 0;i <= length;i++) {
            dp[next][i] = (length - i) * 1.0 / double(walk);
        }
        for(int i = n - 1;i >= 0;i--) {
            prev ^= 1;
            next ^= 1;
            int pos = length;
            double w = 1.0 * width[i] * width[i];
            for(int j = length;j >= 0;j--) {
                dp[next][j] = INF;
                while(pos >= j) {
                    double dist = dp[prev][pos] + sqrt(w + 1.0 * (j - pos) * (j - pos)) / speed[i];
                    if(dist > dp[next][j]) break;
                    dp[next][j] = dist;
                    pos--;
                }
                pos++;
            }
        }
        return dp[next][0];
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {5, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 2, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.231651964071508; verify_case(0, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 10000; int Arg1 = 211; int Arr2[] = {911}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {207}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 48.24623664712219; verify_case(1, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 1337; int Arg1 = 2; int Arr2[] = {100, 200, 300, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11, 12, 13, 14}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 128.57830549575695; verify_case(2, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 77; int Arg1 = 119; int Arr2[] = {11, 12, 13, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100, 200, 300, 400}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.3842077071089629; verify_case(3, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arg0 = 7134; int Arg1 = 1525; int Arr2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 214.6509731258811; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EllysRivers ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
