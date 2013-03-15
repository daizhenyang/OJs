/*
  ID   : 900831f1
  PROG : money
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
const char * iFileName = "money.in";
const char * oFileName = "money.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
const int LEN = 11000;
LL dp[LEN] = {1, 0,};

int main() {
	int v, n, coin;
	fin >> v >> n;
	for(int i = 0;i < v;i++) {
		fin >> coin;
		for(int j = coin;j <= n;j++) {
			dp[j] += dp[j - coin];
		}
	}
	fout << dp[n] << endl;
	return 0;
}
