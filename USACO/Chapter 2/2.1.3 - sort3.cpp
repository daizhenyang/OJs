/*
  ID   : 900831f1
  PROG : sort3
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "sort3.in";
const char * oFileName = "sort3.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef long long LL;
const int N = 1000;
int a[N], b[N];
int main() {
	int n, result = 0, cnt[4] = {};
	fscanf(fin, "%d", &n);
	for(int i = 0;i < n;i++) fscanf(fin, "%d", a + i);
	for(int i = 0;i < n;i++) cnt[a[i]]++;
	for(int i = 1, j = 0;i <= 3;i++) {
		for(int k = 0;k < cnt[i];k++) {
			b[j++] = i;
		}
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n && (a[i] != b[i]);j++) {
			if(a[i] == b[j] && b[i] == a[j]) {
				swap(a[i], a[j]);
				result++;
				break;
			}
		}
	}
	for(int i = 0;i < n;i++) {
		if(b[i] == 1 && a[i] != 1) result += 2;
	}
	fprintf(fout, "%d\n", result);
	return 0;
}
