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
template<class T> void string_reader(string s, vector<T>& vec){
	istringstream sin(s);
	copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
typedef long long LL;
const int N = 51;
class StampsCollection {
public:
	int n, m;
	vector<int> adj[N];
	LL bit[N];
	bool check[N];
	void dfs(int x, vector<int>& pt) 
	{
		check[x] = true;
		pt.push_back(x);
		FOREACH(adj[x], i)
		{
			if(!check[*i]) dfs(*i, pt);
		}
	}
	int DP(const vector<int>& p, int beg)
	{
		int dp[N] = {0};
		int n = p.size();
		REP(i, 0, n)
		{
			dp[i] = p[i];
			REP(j, beg, i - 1) checkmax(dp[i], dp[j] + p[i]);
		}
		return *max_element(dp, dp + n);
	}
	int sell(int N, vector <string> demand, vector <int> price) 
	{
		n = N, m = demand.size();
		REP(i, 0, m)
		{
			vector<int> s;
			adj[i].clear();
			bit[i] = 0;
			string_reader(demand[i], s);
			FOREACH(s, j) 
				bit[i] |= (1LL << *j);
		}
		REP(i, 0, m) 
		{
			REP(j, i + 1, m)
			{
				if((bit[i] & bit[j]) == 0) continue;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		CC(check, 0);
		int res = 0;
		REP(i, 0, m) 
		{
			if(!check[i] && adj[i].size() == 1)
			{
				vector<int> pt, p;
				dfs(i, pt);
				FOREACH(pt, j)
					p.push_back(price[*j]);
				res += DP(p, 0);
			}
			else if(adj[i].size() == 0)
			{
				check[i] = true;
				res += price[i];
			}
		}
		REP(i, 0, m)
		{
			if(!check[i]) 
			{
				vector<int> pt, p;
				dfs(i, pt);
				FOREACH(pt, j)
					p.push_back(price[*j]);
				int tmpres = 0;
				REP(rot, 0, p.size())
				{
					checkmax(tmpres, DP(p, 1));
					rotate(p.begin(), p.begin() + 1, p.end());
				}
				res += tmpres;
			}
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arr1[] = {"0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"1 0","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1","0 2","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"0","1 0","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,9,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 20; string Arr1[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(4, Arg3, sell(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        StampsCollection ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
