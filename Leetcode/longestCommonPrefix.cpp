#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int n = strs.size();
		if(n == 0) {
			return "";
		}
		vector<int> res(n);
		int pos = 0;
		for(int i = 1;i < n;i++) {
			if(strs[i].size() < strs[pos].size()) {
				pos = i;
			}
		}
		for(int i = 0;i < n;i++) {
			size_t j = 0;
			while(j < strs[pos].size() && j < strs[i].size() && strs[pos][j] == strs[i][j]) {
				j++;
			}
			res[i] = j;
		}
		int length = *min_element(res.begin(), res.end());
		return strs[pos].substr(0, length);
	}
};
int main() {
	return 0;
}
