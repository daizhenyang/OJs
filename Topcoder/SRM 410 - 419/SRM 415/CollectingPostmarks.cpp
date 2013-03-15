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
typedef pair<int, int> PII;
class CollectingPostmarks {
	public:
	vector<PII> half;
	int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K) {
		int n = values.size(), res = 1 << 30;
		int a = n / 2, b = (n + 1) / 2;
		int s = 1 << a;

		half.clear();
		
		for(int i = 0;i < s;i++)
		{
			int v = 0, p = 0;
			for(int j = 0;j < a;j++)
				if(i & (1 << j)) 
					v += values[j], p += prices[j];
			half.push_back(make_pair(v, p));
		}

		sort(half.begin(), half.end());
		for(int i = s - 2;i >= 0;i--)
		{
			checkmin(half[i].second, half[i + 1].second);
		}
		for(int i = 0;i < (1 << b);i++)
		{
			int v = 0, p = 0;
			for(int j = 0;j < b;j++)
				if(i & (1 << j))
					v += values[a + j], p += prices[a + j];
			vector<PII>::iterator iter = upper_bound(half.begin(), half.end(), make_pair(K - v, -1));
			if(iter != half.end())
			{
				checkmin(res, iter->second + p);
			}
		}
		int tmp = 0;
		FOREACH(have, i)
		{
			tmp += prices[*i];
		}
		return res == (1 << 30) ? -1 : max(0, res - tmp);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,21}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; int Arg4 = 15; verify_case(0, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {9,18,7,6,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,27,10,10,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 67; int Arg4 = 22; verify_case(1, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {14,14,12,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19,23,20,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {43,33,14,31,42,37,17,42,40,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {116,71,38,77,87,106,48,107,91,41}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 811; int Arg4 = -1; verify_case(3, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CollectingPostmarks ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
