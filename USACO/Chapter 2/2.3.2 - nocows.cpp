/*
  ID   : 900831f1
  PROG : nocows
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
const int NUM = 210;
const int MOD = 9901;
const char * iFileName = "nocows.in";
const char * oFileName = "nocows.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
int dp[NUM][NUM], sum[NUM][NUM];
void debug(int i, int j) {
	printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
}
bool judge(int lt, int rt) {
	return (lt != 0 && rt != 0) || (lt == 0 && rt == 0);
}
int solve(int num, int height) {
	memset(dp,  0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	dp[0][0]  = sum[0][0] = 1;
	for(int i = 1;i <= num;i++) {
		for(int j = 1;j <= i && j <= height;j++) {
			//left | right child is j - 1
			for(int l = 0;l < i;l++) {
				if(j >= 2 && judge(l, i - l - 1)) {
					dp[i][j] += (2 * dp[l][j - 1] * sum[i - l - 1][j - 2]) % MOD;
					dp[i][j] %= MOD;
				}
			}
			//left & right children i j - 1
			for(int l = 0;l < i;l++) {
				if(judge(l, i - l - 1)) {
					dp[i][j] += (dp[l][j - 1] * dp[i - l - 1][j - 1]) % MOD;
					dp[i][j] %= MOD;
				}
			}
		}
		sum[i][0] = dp[i][0];
		for(int j = 1;j <= height;j++) {
			sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
		}
	}
	return dp[num][height];
}
int main() {
	int num, height;
	fin >> num >> height;
	fout << solve(num, height) << endl;
	return 0;
}
