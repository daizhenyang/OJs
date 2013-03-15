#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, pre = 0, n = s.size();
		int used[26] = {0};
		for(int i = 0;i < n;i++) {
			while(used[s[i] - 'a']) {
				used[s[pre++] - 'a'] = false;
			}
			used[s[i] - 'a'] = true;
			res = max(res, i - pre + 1);
		}
		return res;
	}
};
int main() {
	return 0;
}
