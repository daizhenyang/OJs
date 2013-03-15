/*
  ID   : 900831f1
  PROG : frac1
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "frac1.in";
const char * oFileName = "frac1.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
typedef long long LL;

class compare_pair_by_multiply : public binary_function<pair<int, int>, pair<int, int>, bool > {
public:
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.first * rhs.second < lhs.second * rhs.first;
	}
};
set<pair<int, int>, compare_pair_by_multiply> result;
int main() {
	int n;
	fscanf(fin, "%d", &n);
	result.insert(make_pair(0, 1));
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= i;j++) {
			int gcd = __gcd(i, j);
			int x = j / gcd;
			int y = i / gcd;
			result.insert(make_pair(x, y));
		}
	}
	for(set<pair<int, int> >::iterator i = result.begin();i != result.end();++i) {
		fprintf(fout, "%d/%d\n", i->first, i->second);
	}
	return 0;
}
