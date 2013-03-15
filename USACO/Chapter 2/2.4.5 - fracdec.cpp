/*
  ID   : 900831f1
  PROG : fracdec
  LANG : C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
using namespace std;
typedef long long LL;
const char * iFileName = "fracdec.in";
const char * oFileName = "fracdec.out";
ifstream  fin(iFileName);
ofstream fout(oFileName);
const int N = 100010;
int position[N];
char buffer[N];
string solve(int n, int d) {
	ostringstream sout;
	sout << n / d << ".";
	if(n % d == 0) sout << "0";
	n %= d;
	memset(position, -1, sizeof(position));
	int length = 0;
	while(position[n] == -1 && n) {
		position[n] = length;
		buffer[length] = n * 10 / d + '0';
		n = n * 10 % d;
		length++;
	}
	for(int i = 0;i < length;i++) {
		if(i == position[n]) sout << "(";
		sout << buffer[i];
	}
	if(n) sout << ")";
	return sout.str();
}
const int LENGTH = 76;
int main() {
	int n, d;
	fin >> n >> d;
	string result = solve(n, d);
	for(int i = 0;i < int(result.size());i += LENGTH) {
		fout << result.substr(i, LENGTH) << endl;
	}	
	return 0;
}
