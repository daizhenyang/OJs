#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > sumres;
	void dfs(const vector<int>& candidates, vector<int> res, int dep, int rest) {
		if(rest == 0) {
			sumres.push_back(res);
			return;
		}
		if(dep == int(candidates.size())) {
			return;
		}
		dfs(candidates, res, dep + 1, rest);
		while(rest - candidates[dep] >= 0) {
			res.push_back(candidates[dep]);
			dfs(candidates, res, dep + 1, rest -= candidates[dep]);
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
		sumres.clear();
		dfs(candidates, vector<int>(), 0, target);
		return sumres;
	}
	set<vector<int> > sumset;
	void dfs2(const vector<int>& candidates, vector<int> res, int dep, int rest) {
		if(rest == 0) {
			sumset.insert(res);
			return;
		}
		if(dep == int(candidates.size())) {
			return;
		}
		dfs2(candidates, res, dep + 1, rest);
		if(rest >= candidates[dep]) {
			res.push_back(candidates[dep]);
			dfs2(candidates, res, dep + 1, rest - candidates[dep]);
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		sumres.clear();
		sumset.clear();
		dfs2(num, vector<int>(), 0, target);
		copy(sumset.begin(), sumset.end(), back_inserter<vector<vector<int> > >(sumres));
		return sumres;
	}};
int main() {
	return 0;
}
