/*
  ID   : 900831f1
  PROG : preface
  LANG : C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int N = 256;
const char * iFileName = "preface.in";
const char * oFileName = "preface.out";
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
const string digit[4][10] = { 
	{"","I","II","III","IV","V","VI","VII","VIII","IX"},
	{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
	{"","M","MM","MMM", }
};
const char letter[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int  value[7];
int main() {
	int n;
	fscanf(fin, "%d", &n);
	for(int v = 1;v <= n;v++) {
		string result = "";
		for(int i = 0, j = v;i < 4;i++) {
			result.insert(0, digit[i][j % 10]);
			j /= 10;

		}
		for(int i = 0;i < 7;i++) {
			value[i] += count(result.begin(), result.end(), letter[i]);
		}
	}
	for(int i = 0;i < 7;i++) {
		if(value[i] != 0) fprintf(fout, "%c %d\n", letter[i], value[i]);
	}
	return 0;
}
