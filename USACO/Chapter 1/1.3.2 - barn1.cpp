/*
  ID   : 900831f1
  PROG : barn1
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int maxBoard, StallNumber, cowsNumber;
	FILE * fin  = fopen("barn1.in",  "r");
	FILE * fout = fopen("barn1.out", "w");
	fscanf(fin, "%d %d %d", &maxBoard, &StallNumber, &cowsNumber);
	vector<int> cows(cowsNumber), leak;
	for(int i = 0;i < cowsNumber;i++) {
		fscanf(fin, "%d", &cows[i]);
	}
	sort(cows.begin(), cows.end());
	int result = cowsNumber, used = 1;
	for(int i = 1;i < cowsNumber;i++) {
		if(cows[i] - cows[i - 1] > 1) {
			leak.push_back(cows[i] - cows[i - 1] - 1);
			used++;
		}
	}
	sort(leak.begin(), leak.end());
	for(vector<int>::iterator i = leak.begin();i != leak.end() && used > maxBoard;++i) {
		result += *i;
		used--;
	}
	fprintf(fout, "%d\n", result);
	return 0;
}
