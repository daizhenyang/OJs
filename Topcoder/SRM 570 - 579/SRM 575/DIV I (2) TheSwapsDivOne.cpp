#line 2 "TheSwapsDivOne.cpp"
#include <cstring>
#include <cstdio>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class TheSwapsDivOne {
public:
    double find(vector <string> sequence, int k) {
        string s = accumulate(sequence.begin(), sequence.end(), string());
        int n = s.size();
        //a no move, b move
        double a = 1.0 * (n - 2) / n, b = 2.0 / n / (n - 1);
        double p = 1;
        for(int i = 0;i < k;i++) {
            p = p * a + (1 - p) * b;
        }
        double result = 0;
        for(int i = 0;i < n;i++) {
            double add = 0;
            for(int j = 0;j < n;j++) {
                double used = (j + 1) * (n - j);
                if(i == j) {
                    add += used * p * (s[i] - '0');
                } else {
                    add += used * (1 - p) / (n - 1) * (s[i] - '0');
                }
            }
            result += add;
        }
        return result / ((n + 1) * n / 2);
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 10.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; double Arg2 = 10.0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1", "1", "1", "1", "1", "1", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; double Arg2 = 3.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 98.3238536775161; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheSwapsDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
