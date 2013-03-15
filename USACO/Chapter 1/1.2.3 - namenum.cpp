/*
  ID   : 900831f1
  PROG : namenum
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1025;
const int M = 3;
char buf[N], ans[N];
vector<string> dict, res;
const char* letters[] = {
	"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"
};
inline char get_char(char ch, int i) {
	return letters[ch - '0'][i];
}	

void dfs(int cur, int n) {
	if(cur == n) {
		if(binary_search(dict.begin(), dict.end(), string(ans))) {
			res.push_back(ans);
		}
		return;
	}
	for(int i = 0;i < M;i++) {
		ans[cur] = get_char(buf[cur], i);
		dfs(cur + 1, n);
	}
}
int main() {
	int n;
	FILE * fin  = fopen("namenum.in", "r");
	FILE * dic  = fopen("dict.txt", "r");
	FILE * fout = fopen("namenum.out", "w");
	while(fscanf(dic, "%s", buf) != EOF) {
		dict.push_back(buf);
	}
	sort(dict.begin(), dict.end());
	fscanf(fin, "%s", buf);
	n = strlen(buf);
	dfs(0, n);
	sort(res.begin(), res.end());
	if(res.size() == 0) {
		fprintf(fout, "NONE\n");
	}
	for(vector<string>::iterator i = res.begin();i != res.end();++i) {
		fprintf(fout, "%s\n", i->c_str());
	}
	return 0;
}
