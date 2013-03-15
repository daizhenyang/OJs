#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int l = newInterval.start, r = newInterval.end, n = intervals.size(), ins = 0;
		vector<Interval> res;
		for(int i = 0;i < n;i++) {
			if(intervals[i].end < l) {
				res.push_back(intervals[i]);
			} else if(intervals[i].start > r) {
				if(ins == 0) {
					res.push_back(Interval(l, r));
					ins++;
				}
				res.push_back(intervals[i]);
			} else {
				l = min(l, intervals[i].start);
				r = max(r, intervals[i].end);
			}
		}
		if(ins == 0) res.push_back(Interval(l, r));
		return res;
	}
};
int main() {
	return 0;
}
