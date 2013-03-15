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
const LL MOD = 1234567891;
const int maxn = 50;
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
    return (x % MOD + MOD) % MOD;
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
Matrix operator-(Matrix m1, Matrix m2)
{
    Matrix ret;
    ret.size = m1.size;
    for (int i = 0; i < ret.size; ++i)
        for (int j = 0; j < ret.size; ++j)
            ret.A[i][j] = mymod(m1.A[i][j] - m2.A[i][j]);
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
            for (int k = 0; k < ret.size; ++k)
	    {
                ret.A[i][j] += m1.A[i][k] * m2.A[k][j];
		ret.A[i][j] %= MOD;
	    }
            ret.A[i][j] = mymod(ret.A[i][j]);
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
bool pred(int x)
{
	while(x)
	{
		if(x % 10 != 4 && x % 10 != 7)
			return false;
		x /= 10;
	}
	return true;
}
class TheLuckySequence {
	public:
		vector<int> luck;
		int count(vector <int> numbers, int length) {
			luck.clear();
			sort(numbers.begin(), numbers.end());
			numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
			FOREACH(numbers, i) if(pred(*i)) luck.push_back(*i);
			int n = luck.size();
			Matrix m;
			m.size = n;
			REP(i, 0, n) REP(j, 0, n)
			{
				char beg[100], end[100];
				sprintf(beg, "%d", luck[i]);
				sprintf(end, "%d", luck[j]);
				int li = strlen(beg);
				if(beg[li - 1] == end[0])
				{
					m.A[i][j] = 1;
				}
			}
			m = mypower(m, length - 1);
			LL res = 0;
			REP(i, 0, n) REP(j, 0, n) res = (res + m.A[i][j]) % MOD;
			return res;
		}
		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {47, 74, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, count(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {100, 4774, 200, 747, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {44, 47, 74, 77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(3, Arg2, count(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TheLuckySequence ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
