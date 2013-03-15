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
#include <queue>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
map<int, int> result;
const int INF = 1000000;
const int N = 5;
const int M = 25;
class PiecesMover {
	public:
	int starcnt;
	int get_mask(vector<string>& bd) {
		int res = 0, cnt = 0;
		REP(i, 0, N) REP(j, 0, N) {
			if(bd[i][j] == '*') {
			       	res |= 1 << cnt;
			}
			cnt++;
		}
		return res;
	}
	bool test(int mask, int bit) {
		return (mask & (1 << bit)) != 0;
	}
	int check(int x, int y, int& mask) {
		int bit = x * N + y;
		if(x < 0 || x >= N || y < 0 || y >= N || test(mask, bit) == 0)
			return 0;
		int res = 1;
		mask ^= (1 << bit);
		res += check(x - 1, y, mask);
		res += check(x, y - 1, mask);
		res += check(x + 1, y, mask);
		res += check(x, y + 1, mask);
		return res;
	}
	bool OK(int mask) {
		REP(i, 0, N) REP(j, 0, N) {
			if(mask & (1 << (i * N + j))) {
				int res = check(i, j, mask);
				printf("%d %d : %d\n", i, j, res);
				return res == starcnt;
			}
		}
		return true;
	}
#define CHECK(nxt) \
	if(result.find(nxt) == result.end()) { \
		result.insert(make_pair(nxt, step + 1)); \
		q.push(nxt);\
		if(OK(nxt)) { \
			return step + 1; \
		} \
	}
	int bfs(int mask) {
		result.insert(make_pair(mask, 0));
		queue<int> q;
		q.push(mask);
		while(q.empty() == false) {
			mask = q.front();q.pop();
			int step = result[mask];
			if(OK(mask)) {
				return step;
			}
			REP(i, 0, M) {
				if(test(mask, i) == 0) continue;
				if(i >= 5 && test(mask, i - 5) == 0) {
					int nxt = mask ^ (1 << i) ^ (1 << (i - 5));
					CHECK(nxt);
				}
				if(i < 20 && test(mask, i + 5) == 0) {
					int nxt = mask ^ (1 << i) ^ (1 << (i + 5));
					CHECK(nxt);
				}
				if(i % 5  && test(mask, i - 1) == 0) {
					int nxt = mask ^ (1 << i) ^ (1 << (i - 1));
					CHECK(nxt);
				}
				if(i % 5 != 4 && test(mask, i + 1) == 0) {
					int nxt = mask ^ (1 << i) ^ (1 << (i + 1));
					CHECK(nxt);
				}
			}
		}
		return 0;
	}
	int getMinimumMoves(vector <string> board) {
		starcnt = 0;
		REP(i, 0, 5) REP(j, 0, 5) starcnt += board[i][j] == '*';
		int mask = get_mask(board);
		result.clear();
		return bfs(mask);
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
		"..**.",
		".....",
		"...*.",
		"....."}
	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimumMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {".....", 
		"..**.", 
		"..**.", 
		".....", 
		"....."}	
	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimumMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"*...*",
		".....",
		".....",
		".....",
		"*...*"}
	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getMinimumMoves(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	PiecesMover ___test;
	___test.run_test(1);
	return 0;
}
// END CUT HERE
