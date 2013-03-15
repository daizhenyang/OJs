/*
  ID   : 900831f1
  PROG : prefix
  LANG : C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long LL;
const int NUM = 200;
const int LEN = 204800;
const char * iFileName = "prefix.in";
const char * oFileName = "prefix.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
string primitives[NUM];
char S[LEN];
bool dp[LEN];
int main() {
	string buffer;
	int n = 0, m = 0;
	while(fin >> buffer && buffer != ".") {
		primitives[n++] = buffer;
	}
	char * ptr = S;
	while(fin >> buffer) {
		strcpy(ptr, buffer.c_str());
		ptr += buffer.size();
		m   += buffer.size();
	}
	dp[0] = true;
	for(int i = 1;i <= m;i++) {
		for(int j = 0;j < n;j++) {
			int pos = i - int(primitives[j].size());
			if(pos >= 0 && strncmp(S + pos, primitives[j].c_str(), primitives[j].size()) == 0) {
				dp[i] |= dp[pos];
			}
		}
	}
	for(int i = m;i >= 0;i--) {
		if(dp[i]) {
			fout << i << endl;
			break;
		}
	}
	return 0;
}
