#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	struct sum {
		int v;
		pair<int, int> p;
		bool operator < (const sum& oth) const {
			return v == oth.v ? p < oth.p : v < oth.v;
		}
		sum(int v = 0, int idx0 = 0, int idx1 = 0) {
			if(idx0 > idx1) swap(idx0, idx1);
			this->v = v;
			p = make_pair(idx0, idx1);
		}
	};
	bool compare(const pair<int, int>& p1, const pair<int, int>& p2) const {
		return p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second;
	}
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<sum> p;
		set<vector<int> > res;
		int n = num.size();
		for(int i = 0;i < n;i++) {
			for(int j = i + 1;j < n;j++) {
				p.push_back(sum(num[i] + num[j], i, j));
			}
		}
		int m = p.size();
		sort(p.begin(), p.end());
		for(int i = 0;i < m;i++) {
			int beg = lower_bound(p.begin(), p.end(), sum(target - p[i].v, 0, 0)) - p.begin();
			int end = lower_bound(p.begin(), p.end(), sum(target - p[i].v + 1, 0, 0)) - p.begin();
			for(int j = beg;j < end;j++) {
				if(compare(p[i].p, p[j].p)) {
					int v [] = {num[p[i].p.first], num[p[i].p.second], num[p[j].p.first], num[p[j].p.second]};
					sort(v, v + 4);
					res.insert(vector<int>(v, v + 4));
				}
			}
		}
		vector<vector<int> > ret;
		copy(res.begin(), res.end(), back_inserter<vector<vector<int> > >(ret));
		return ret;
	}
};
int main() {
	return 0;
}
