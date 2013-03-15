#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		map<string, int> count;
		int n = strs.size();
		for(int i = 0;i < n;i++) {
			string s = strs[i];
			sort(s.begin(), s.end());
			count[s]++;
		}
		vector<string> res;
		for(int i = 0;i < n;i++) {
			string s = strs[i];
			sort(s.begin(), s.end());
			if(count[s] > 1) res.push_back(strs[i]);
		}
		return res;
	}
};
int main() {
	return 0;
}
