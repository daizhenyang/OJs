/*
  ID   : 900831f1
  PROG : ariprog
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
const char * iFileName = "ariprog.in";
const char * oFileName = "ariprog.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
int n, m;
const int N = 1024000;
bool mem[N];

int main() {
	fscanf(fin, "%d %d", &n, &m);
	vector<int> bisquares;
	memset(mem, 0, sizeof(mem));
	for(int q = 0;q <= m;q++) {
		for(int p = 0;p <= m;p++) {
			int v  = p * p + q * q;
			mem[v] = true;
			bisquares.push_back(v);
		}
	}
	sort(bisquares.begin(), bisquares.end());
	bisquares.erase(unique(bisquares.begin(), bisquares.end()), bisquares.end());
	int maxBisquare = *bisquares.rbegin();
	vector<pair<int, int> > result;
	//Arithmetic progression is defined as a + i * b(0 <= i <= n), first is b, second is a
	for(vector<int>::iterator a = bisquares.begin();a != bisquares.end();++a) {
		for(vector<int>::iterator b = a + 1;b != bisquares.end();++b) {
			int v = *a, d = *b - *a, i = 2;
			int maxValue = v + (n - 1) * d;
			if(maxValue > maxBisquare) break;
			for(i = 2;i < n;i++) {
				if(mem[v + i * d] == false) break;
			}
			if(i == n) result.push_back(make_pair(d, v));
		}
	}
	if(result.size() == 0) {
		fprintf(fout, "NONE\n");
	} else {
		sort(result.begin(), result.end());
		for(vector<pair<int, int> >::iterator i = result.begin();i != result.end();++i) {
			fprintf(fout, "%d %d\n", i->second, i->first);
		}
	}
	return 0;
}
