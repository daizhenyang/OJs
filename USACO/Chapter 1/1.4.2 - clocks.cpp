/*
  ID   : 900831f1
  PROG : clocks
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cctype>
#include <map>
#include <cassert>
#include <queue>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "clocks.in";
const char * oFileName = "clocks.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
const int N   = 9;
const int MOD = 4;
int mem[1 << 20];
const char * allMoveStr[9] = {
	"ABDE",
	"ABC",
	"BCEF",
	"ADG",
	"BDEFH",
	"CFI",
	"DEGH",
	"GHI",
	"EFHI"
};

int test4bit(int mask, int bit) {
	return (mask >> (bit << 1)) & 3;
}
int plus4bit(int& mask, int bit, int add) {
	int value = test4bit(mask, bit);
	mask ^= (value << (bit << 1));
	value = (value + add) % 4;
	mask |= (value << (bit << 1));
	return mask;
}
void bfs(const int from) {
	mem[from] = 0;
	if(from  == 0) return;
	const int target = 0;
	queue<int> q;
	q.push(from);
	while(!q.empty()) {
		const int mask = q.front();
		const int move = mem[mask];
		q.pop();
		for(int i = 0;i < N;i++) {
			if(test4bit(move, i) == 3) continue;
			int nextMask = mask;
			int nextMove = move;
			plus4bit(nextMove, i, 1);
			for(const char * ptr = allMoveStr[i];*ptr;++ptr) {
				plus4bit(nextMask, *ptr - 'A', 1);
			}
			if(mem[nextMask] == -1) {
				mem[nextMask] = nextMove;
				q.push(nextMask);
			}
			if(nextMask == target) return;
		}
	}
}
int main() {
	memset(mem, -1, sizeof(mem));
	int mask = 0, clock;
	for(int i = 0;i < N;i++) {
		fscanf(fin, "%d", &clock);
		clock = clock % 12 / 3;
		plus4bit(mask, i, clock);
	}
	bfs(mask);
	const int state = 0;
	if(mem[state] == -1) {
		fprintf(fout, "NONE\n");
	} else {
		int move = mem[state], first = 1;
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < test4bit(move, i);j++) {
				if(first) {
					fprintf(fout, "%d", i + 1);
					first = 0;
				} else {
					fprintf(fout, " %d", i + 1);
				}
			}
		}
		fprintf(fout, "\n");
	}
	return 0;
}
