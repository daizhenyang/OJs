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
#include <utility>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const LL MOD =1234567891;
const int maxn = 27;
struct Matrix
{
    LL A[maxn][maxn];
    int size;

    Matrix()
    {
        memset(this, 0, sizeof (*this));
    }
};
LL mymod(LL x)
{
    return x % MOD;
}
Matrix operator+(Matrix m1, Matrix m2)
{
    Matrix ret;
    ret.size = m1.size;
    for (int i = 0; i < ret.size; ++i)
        for (int j = 0; j < ret.size; ++j)
            ret.A[i][j] = mymod(m1.A[i][j] + m2.A[i][j]);
    return ret;
}
Matrix operator*(Matrix m1, Matrix m2)
{
    Matrix ret;
    ret.size = m1.size;
    for (int i = 0; i < ret.size; ++i)
        for (int j = 0; j < ret.size; ++j)
        {
            ret.A[i][j] = 0;
            for (int k = 0; k < ret.size; ++k) {
                ret.A[i][j] += mymod(m1.A[i][k] * m2.A[k][j]);
		ret.A[i][j] = mymod(ret.A[i][j]);
	    }
        }
    return ret;
}
Matrix mypower(Matrix m, int n)
{
    Matrix ret, tmp;
    ret.size = m.size;
    if (n == 0)
    {
        for (int i = 0; i < ret.size; ++i)
            ret.A[i][i] = 1;
        return ret;
    }
    tmp = mypower(m, n / 2);
    if (n & 1)
        return tmp * tmp * m;
    else return tmp * tmp;
}
Matrix sumpower(const Matrix& m, int n)
{
	Matrix tmp;
	if(n == 0) {
		tmp.size = m.size;
		for(int i = 0;i < tmp.size;i++)
			tmp.A[i][i] = 1;
		return tmp;
	}
	if (n == 1) return m;
	tmp = sumpower(m, n / 2);
	if (n & 1)
		return mypower(m, n / 2) * tmp + tmp + mypower(m, n);
	return mypower(m, n / 2) * tmp + tmp;
}
class TheLongPalindrome {
	public:
		int count(int n, int k) {
			LL res = 0;
			Matrix m;
			m.size = maxn;
			m.A[0][1] = 26;
			for(int i = 1;i < maxn;i++) {
				m.A[i][i] = i;
				if(i + 1 < maxn) m.A[i][i + 1] = 26 - i;
			}
			if(n > 1) {
				Matrix half = sumpower(m, n / 2);
				for(int i = 1;i <= k;i++) {
					res = (res + half.A[0][i]) % MOD;
				}
			}
			res = (res * 2) % MOD;
			if(n & 1) {
				Matrix b = mypower(m, (n + 1) / 2);
				for(int i = 1;i <= k;i++) {
					res = (res + b.A[0][i]) % MOD;
				}
			}
			return res;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 26; verify_case(0, Arg2, count(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 52; verify_case(1, Arg2, count(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 728; verify_case(2, Arg2, count(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 44; int Arg1 = 7; int Arg2 = 240249781; verify_case(3, Arg2, count(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TheLongPalindrome ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE

