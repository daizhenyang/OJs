// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysNumbers.cpp"
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
#define DEBUG(con) cout << #con << " " << con << endl;
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
template<class T> void string_reader(string s, vector<T>& vec){
    istringstream sin(s);
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}


const int N = 501;
LL dp[2][1 << 17], nn;
vector<LL> counter, cnt_n, prime;
void get_factor(LL n)
{
	int lmt = sqrt(n * 1.0) + 1;
	for(int i = 2;i <= lmt;i++)
		if(n % i == 0)
		{
			prime.push_back(i);
			while(n % i == 0) n /= i;
		}
	if(n != 1) prime.push_back(n);
}
bool is_not_gcd(LL x)
{
	if(nn % x == 0 && __gcd(nn / x, x) == 1)
		return false;
	return true;
}
bool get_count(LL n, vector<LL>& counter)
{
	int s = prime.size();
	counter.assign(s, 0);
	REP(i, 0, s)
	{
		while(n % prime[i] == 0)
		{
			counter[i]++;
			n /= prime[i];
		}
	}
	return n == 1;
}
bool is_not_legal(LL n)
{
	get_count(n, counter);
	REP(i, 0, prime.size())
		if(counter[i] != cnt_n[i] && counter[i] != 0) return true;
	return false;
}
int state(LL n)
{
	get_count(n, counter);
	int sta = 0;
	REP(i, 0, prime.size())
		if(counter[i]) sta |= (1 << i);
	return sta;
}
class EllysNumbers
{
public:
	long long getSubsets(long long n, vector <string> special)
	{
		nn = n;
		vector<LL> vec;
		string buffer = accumulate(special.begin(), special.end(), string(""));
		string_reader(buffer, vec);
		vec.erase(remove_if(vec.begin(), vec.end(), is_not_gcd), vec.end());

		prime.clear();
		FOREACH(vec, i) get_factor(*i);
		sort(prime.begin(), prime.end());
		prime.erase(unique(prime.begin(), prime.end()), prime.end());

		if(get_count(n, cnt_n) == false) return 0;
		vec.erase(remove_if(vec.begin(), vec.end(), is_not_legal), vec.end());
		CC(dp, 0);
		dp[0][0] = 1;
		int p = prime.size(), pre = 0, now = 1;	
		int als = (1 << p);
		FOREACH(vec, i)
		{
			int sta = state(*i);
			CC(dp[now], 0);
			for(int i = 0;i < als;i++)
			{
				dp[now][i] += dp[pre][i];
				if((i & sta) == 0)
					dp[now][i | sta] += dp[pre][i];
			}
			now ^= 1;
			pre ^= 1;
		}
		return dp[pre][als - 1];
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 12LL; string Arr1[] = {"4 2 5 6 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 42LL; string Arr1[] = {"1 2 3 4 5 6 7 13 14 21 42"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1337LL; string Arr1[] = {"1 13 42 666 2674"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1073741824LL; string Arr1[] = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
		"6384 32768 65536 131072 262144 524288 1048576 2097",
		"152 4194304 8388608 16777216 33554432 67108864 134",
		"217728 268435456 536870912"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 7420738134810LL; string Arr1[] = {"435 625199055 4199 33263 17 222870 284870433 72093",
		"2379 7 11 31 247110827 23 1771 81809 851968487 13 ",
		"476379795 1001 5 435274114 38264554 7429 239906525",
		" 3 227183706 887045414 606786670 3795 797605175 29",
		" 30 747186719 19 2 562347843 74 2294 588002688 743",
		"6429 703 591740547 36657492 37 444178205 1002001 2",
		"17626404"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 110LL; verify_case(4, Arg2, getSubsets(Arg0, Arg1)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	EllysNumbers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE

