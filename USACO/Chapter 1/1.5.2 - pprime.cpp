/*
  ID   : 900831f1
  PROG : pprime
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cctype>
#include <map>
#include <cassert>
#include <queue>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "pprime.in";
const char * oFileName = "pprime.out";
typedef long long LL;
FILE * fin  = fopen(iFileName, "r");
FILE * fout = fopen(oFileName, "w");
const LL MINVALUE = 5;
const LL MAXVALUE = 10000000;

bool isPrime(LL num) {
	if(num == 1) return false;
	for(LL i = 2;i * i <= num;i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}
LL generateOdd(LL num) {
	LL result = num / 10;
	while(num != 0) {
		result *= 10;
		result += num % 10;
		num /= 10;
	}
	return result;
}
LL generateEven(LL num) {
	LL result = num;
	while(num != 0) {
		result *= 10;
		result += num % 10;
		num /= 10;
	}
	return result;
}

vector<LL> pprime;
void generatePPrime() {
	LL seed = 1, value;
	do {
		value = generateEven(seed++);
		if(value >= MINVALUE && isPrime(value)) pprime.push_back(value);
	} while(value <= MAXVALUE);
	seed = 1;
	do {
		value = generateOdd(seed++);
		if(value >= MINVALUE && isPrime(value)) pprime.push_back(value);
	} while(value <= MAXVALUE);
}
int main() {
	generatePPrime();
	sort(pprime.begin(), pprime.end());
	pprime.erase(unique(pprime.begin(), pprime.end()), pprime.end());
	int low, high;
	fscanf(fin, "%d %d", &low, &high);
	int from = lower_bound(pprime.begin(), pprime.end(), low)  - pprime.begin();
	int to   = upper_bound(pprime.begin(), pprime.end(), high) - pprime.begin();
	for(int i = from;i < to;i++) {
		fprintf(fout, "%lld\n", pprime[i]);
	}
	return 0;
}
