/*
  ID   : 900831f1
  PROG : sprime
  LANG : C++
*/
#include <cstring>
#include <cstdio>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "sprime.in";
const char * oFileName = "sprime.out";
typedef long long LL;
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
const int prime_list[] = {2, 3, 5, 7};
const int N = sizeof(prime_list) / sizeof(prime_list[0]);
bool isPrime(LL num) {
	if(num == 1) return false;
	for(LL i = 2;i * i <= num;i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}

void dfs(int val, int curDepth, int maxDepth) {
	if(curDepth == maxDepth) {
		fprintf(fout, "%d\n", val);
		return;
	}
	for(int i = 1;i < 10;i++) {
		int newVal = val * 10 + i;
		if(isPrime(newVal)) dfs(newVal, curDepth + 1, maxDepth);
	}
}
int main() {
	int n;
	fscanf(fin, "%d", &n);
	dfs(0, 0, n);
	return 0;
}
