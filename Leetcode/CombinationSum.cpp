#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > res;
	void generate(const vector<int>& candidates, vector<int>& cur, int depth, int target) {
		if(depth == candidates.size()) {
			if(target == 0) res.push_back(cur);
			return;
		}
		generate(candidates, cur, depth + 1, target);
		for(int i = 1;i * candidates[depth] <= target;i++) {
			cur.push_back(candidates[depth]);
			generate(candidates, cur, depth + 1, target - i * candidates[depth]);
		}
		for(int i = 1;i * candidates[depth] <= target;i++) {
			cur.pop_back();
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		res.clear();
		vector<int> cur;
		sort(candidates.begin(), candidates.end());
		generate(candidates, cur, 0, target);
		return res;
	}
};
int main() {
	return 0;
}
