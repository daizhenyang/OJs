/*
  ID   : 900831f1
  PROG : crypt1
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const int N = 10;
int digit[N];
vector<int> two, three, four;

void dfs(int number, int depth, int maxdepth, int size) {
	if(depth == 2) two.push_back(number);
	if(depth == 3) three.push_back(number);
	if(depth == 4) four.push_back(number);
	if(depth == maxdepth) {
		return;
	}
	for(int i = 0;i < size;i++) {
		dfs(number * 10 + digit[i], depth + 1, maxdepth, size);
	}
}
int main() {
	FILE * fin  = fopen("crypt1.in",  "r");
	FILE * fout = fopen("crypt1.out", "w");
	int n;
	fscanf(fin, "%d", &n);
	for(int i = 0;i < n;i++) {
		fscanf(fin, "%d", digit + i);
	}
	dfs(0, 0, 4, n);
	sort(two.begin(), two.end());
	sort(three.begin(), three.end());
	sort(four.begin(), four.end());
	int result = 0;
	for(vector<int>::iterator lhs = three.begin();lhs != three.end();++lhs) {
		for(vector<int>::iterator rhs = two.begin();rhs != two.end();++rhs) {
			int one = *rhs % 10, ten = *rhs / 10;
			if(binary_search(three.begin(), three.end(), *lhs * one)
				&& binary_search(three.begin(), three.end(), *lhs * ten)
				&& binary_search(four.begin(), four.end(), *lhs * *rhs))
				result++;
		}
	}
	fprintf(fout, "%d\n", result);
	return 0;
}
