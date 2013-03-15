// BEGIN CUT HERE

// END CUT HERE
#line 5 "HoleCakeCuts.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
template<class T> void string_reader(string s, vector<T>& vec){
    istringstream sin(s);
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int N = 300;
int mask[N][N], chk[N][N];
int edge;
void setbit(int i, int j, int bit) {
	if(i < 0 || i >= edge || j < 0 || j >= edge) return;
	mask[i][j] |= (1 << bit);
}
bool legal(int i, int j)
{
	return 0 <= i && i < edge && 0 <= j && j < edge && chk[i][j] == false;
}
typedef pair<int, int> PII;
class HoleCakeCuts
{
public:
	void bfs(int i, int j)
	{
		queue<pair<int, int> > q;
		q.push(make_pair(i, j));
		while(q.empty() == false)
		{
			PII now = q.front(); q.pop();
			int x = now.first ;
			int y = now.second;
			for(int k = 0;k < 4;k++)
			{
				int tmpx = x + dx[k];
				int tmpy = y + dy[k];
				if((mask[x][y] & (1 << k)) == 0 && legal(tmpx, tmpy))
				{
					chk[tmpx][tmpy] = true;
					q.push(make_pair(tmpx, tmpy));
				}
			}
		}
	}
	int cutTheCake(int cake, int hole, vector <int> hcut, vector <int> vcut) {
		FOREACH(hcut, i) *i += cake;
		FOREACH(vcut, i) *i += cake;
		memset(mask, 0, sizeof(mask));
		int ct = cake - hole;
		cake <<= 1, hole <<= 1;
		edge = cake;
		REP(i, 0, cake) REP(j, 0, cake)
		{
			if(i == 0       ) setbit(i, j, 0);
			if(j == 0       ) setbit(i, j, 1);
			if(i == cake - 1) setbit(i, j, 2);
			if(j == cake - 1) setbit(i, j, 3);
		}
		memset(chk, 0, sizeof(chk));
		REP(i, 0, hole) REP(j, 0, hole)
		{
			int ii = i + ct, jj = j + ct;
			chk[ii][jj] = true;
			if(i == 0       ) setbit(ii, jj, 0), setbit(ii - 1, jj, 2);
			if(j == 0       ) setbit(ii, jj, 1), setbit(ii, jj - 1, 3);
			if(i == hole - 1) setbit(ii, jj, 2), setbit(ii + 1, jj, 0);
			if(j == hole - 1) setbit(ii, jj, 3), setbit(ii, jj + 1, 1);
		}
		FOREACH(hcut, i) REP(j, 0, cake)
			setbit(*i - 1, j, 2), setbit(*i, j, 0);
		FOREACH(vcut, i) REP(j, 0, cake)
			setbit(j, *i - 1, 3), setbit(j, *i, 1);
		int res = 0;
		REP(i, 0, cake) REP(j, 0, cake)
		{
			if(chk[i][j] == false)
			{
				chk[i][j] = true;
				res++;
				bfs(i, j);
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
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1, -4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(0, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-2, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-5, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(2, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 5; int Arr2[] = {40, -40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 0, -20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 12; verify_case(3, Arg4, cutTheCake(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	HoleCakeCuts ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
