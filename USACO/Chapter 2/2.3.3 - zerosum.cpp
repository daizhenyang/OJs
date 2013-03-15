/*
  ID   : 900831f1
  PROG : zerosum
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
const int LEN = 200;
const char * iFileName = "zerosum.in";
const char * oFileName = "zerosum.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
char buf[LEN];
int get_num(int& i, int length) {
	int result = 0;
	for(;i < length && buf[i] != '+' && buf[i] != '-';i++) {
		if(buf[i] != ' ') result = result * 10 + buf[i] - '0';
	}
	return result;
}
bool calculate(int n, int length) {
	int result = 0, i = 0;
	result = get_num(i, length);
	while(i < length) {
		if(buf[i] == '+') {
			result += get_num(++i, length);
		} else if(buf[i] == '-') {
			result -= get_num(++i, length);
		}
	}
	return result == 0;
}
vector<string> result;
void dfs(int depth, int maxdepth) {
	if(depth == maxdepth - 1) {
		if(calculate(maxdepth, maxdepth * 2 - 1)) {
			result.push_back(buf);
		}
		return ;
	}
	buf[(depth << 1) | 1] = ' ';
	dfs(depth + 1, maxdepth);
	buf[(depth << 1) | 1] = '+';
	dfs(depth + 1, maxdepth);
	buf[(depth << 1) | 1] = '-';
	dfs(depth + 1, maxdepth);
}
int main() {
	int n;
	fin >> n;
	for(int i = 0;i < n * 2 - 1;i++) {
		buf[i] = i / 2 + '0' + 1;
	}
	dfs(0, n);
	FOREACH(result, i) {
		fout << *i << endl;
	}
	return 0;
}
