/*
  ID   : 900831f1
  PROG : packrec
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cctype>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const char * iFileName = "packrec.in";
const char * oFileName = "packrec.out";
const int N 	 = 4;
const int MAXLEN = 200;
int width[N], length[N];

pair<int, int> area1() {
	return make_pair(accumulate(width, width + N, 0), 
			*max_element(length, length + N));
}
pair<int, int> area2() {
	return make_pair(max(width[0], accumulate(width + 1, width + N, 0)), 
			length[0] + *max_element(length + 1, length + N));
}
pair<int, int> area3() {
	return make_pair(width[1] + max(width[0], width[2] + width[3]), 
			max(length[1], length[0] + max(length[2], length[3])));
}
pair<int, int> area4() {
	return make_pair(width[0] + max(width[1], width[2]) + width[3], 
			max(length[0], max(length[1] + length[2], length[3])));
}
pair<int, int> area5() {
	return make_pair(max(width[0], width[1]) + width[2] + width[3], 
			max(max(length[0] + length[1], length[2]), length[3]));
}
pair<int, int> area6() {
	int len = max(length[0] + length[1], length[2] + length[3]);
	int wid;
	if(length[0] + length[1] <= length[2]) {
		wid = max(max(width[0], width[1]) + width[2], width[3]);
	} else if(length[0] + length[1] > length[2] && length[1] < length[2]) {
		wid = max(width[0] + max(width[2], width[3]), width[1] + width[2]);
	} else if(length[1] >= length[2] && length[1] < length[2] + length[3]) {
		wid = max(width[0] + width[3], width[1] + max(width[2], width[3]));
	} else {
		wid = max(width[0], width[1] + max(width[2], width[3]));
	}
	return make_pair(len, wid);
}
int main() {
	FILE * fin  = fopen(iFileName, "r");
	FILE * fout = fopen(oFileName, "w");
	int area = MAXLEN * MAXLEN;
	for(int i = 0;i < N;i++) {
		fscanf(fin, "%d %d", width + i, length + i);
	}
	int arrangement[N] = {0, 1, 2, 3};
	int tempWidth[N], tempLength[N];
	vector<pair<int, int> > outputVector;
	memcpy(tempWidth, width, sizeof(width));
	memcpy(tempLength, length, sizeof(length));
	do {
		for(int mask = 0;mask < (1 << N);mask++) {
			for(int i = 0;i < N;i++) {
				if(mask & (1 << i)) {
					width[i]  = tempWidth[arrangement[i]];
					length[i] = tempLength[arrangement[i]];
				} else {
					width[i]  = tempLength[arrangement[i]];
					length[i] = tempWidth[arrangement[i]];
				}
			}
			pair<int, int> result[6] = {area1(), area2(), area3(), area4(), area5(), area6()};
			for(int i = 0;i < 6;i++) {
				if(result[i].first > result[i].second) swap(result[i].first, result[i].second);
				if(checkmin(area, result[i].first * result[i].second)) {
					outputVector.clear();
					outputVector.push_back(result[i]);
				} else if(area == result[i].first * result[i].second) {
					outputVector.push_back(result[i]);
				}
			}
		}
	} while(next_permutation(arrangement, arrangement + N));
	fprintf(fout, "%d\n", area);
	sort(outputVector.begin(), outputVector.end());
	outputVector.erase(unique(outputVector.begin(), outputVector.end()), outputVector.end());
	for(vector<pair<int,int> >::iterator i = outputVector.begin();i != outputVector.end();++i) {
		fprintf(fout, "%d %d\n", i->first, i->second);
	}
	return 0;
}
