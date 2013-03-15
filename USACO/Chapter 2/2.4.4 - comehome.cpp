/*
  ID   : 900831f1
  PROG : comehome
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
const char * iFileName = "comehome.in";
const char * oFileName = "comehome.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
const int INF = 1e8;
const int LEN = 52;
int cost[LEN][LEN];
int label(char ch) {
	return isupper(ch) ? ch - 'A' : ch - 'a' + 26;
}
int main() {
	for(int i = 0;i < LEN;i++) {
		for(int j = 0;j < LEN;j++) {
			cost[i][j] = INF;
		}
		cost[i][i] = 0;
	}
	int p, dis;
	fin >> p;
	for(int i = 0;i < p;i++) {
		char p1, p2;
		fin >> p1 >> p2 >> dis;
		int a = label(p1), b = label(p2);
		cost[b][a] = cost[a][b] = min(cost[a][b], dis);
	}
	for(int k = 0;k < LEN;k++) {
		for(int i = 0;i < LEN;i++) {
			for(int j = 0;j < LEN;j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	int res = INF, cow;
	for(int i = 0;i < 25;i++) {
		if(cost[i][25] < res) {
			res = cost[i][25];
			cow = i;
		}
	}
	fout << char(cow + 'A') << " " << res << endl; 
	return 0;
}
