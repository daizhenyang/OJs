/*
  ID   : 900831f1
  PROG : milk
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int milk, sellerNumber, result = 0;
	FILE * fin  = fopen("milk.in",  "r");
	FILE * fout = fopen("milk.out", "w");
	fscanf(fin, "%d %d", &milk, &sellerNumber);
	vector<pair<int, int> > seller(sellerNumber);
	for(int i = 0;i < sellerNumber;i++) {
		fscanf(fin, "%d %d", &seller[i].first, & seller[i].second);
	}
	sort(seller.begin(), seller.end());
	for(int i = 0;i < sellerNumber && milk;i++) {
		int buy = min(milk, seller[i].second);
		milk -= buy;
		result += buy * seller[i].first;
	}
	fprintf(fout, "%d\n", result);
	return 0;
}
