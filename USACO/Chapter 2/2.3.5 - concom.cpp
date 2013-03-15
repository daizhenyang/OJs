/*
  ID   : 900831f1
  PROG : concom
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
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
using namespace std;
typedef long long LL;
const char * iFileName = "concom.in";
const char * oFileName = "concom.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
const int LEN = 11000;
const int N = 100;
int cent[N][N], dp[N][N];
void solve(int N) {
	int changed = 0;
	do {
		changed = 0;
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < N;j++) {
				int percent = 0;
				for(int k = 0;k < N;k++) {
					if(dp[i][k]) percent += cent[k][j];
				}
				if(percent > 50 && dp[i][j] == 0) {
					dp[i][j] = 1;
					changed  = 1;
				}
			}
		}
	} while(changed);
}
int main() {
	int i, j, p, n;
	fin >> n;
	memset(dp, 0, sizeof(dp));
	for(i = 0;i < N;i++) dp[i][i] = 1;
	for(int v = 0;v < n;v++) {
		fin >> i >> j >> p;
		cent[--i][--j] = p;
		if(p > 50) dp[i][j] = 1;
	}
	solve(N);
	for(i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			if(i != j && dp[i][j])
				fout << i + 1 << " " << j + 1 << endl;
		}
	}
	return 0;
}
