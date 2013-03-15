#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int n = s.size(), res = 0, pre = -1;
		for(int i = 0;i < n;i++) {
			if(s[i] == '(') {
				stk.push(i);
			} else if(stk.size() != 0) {
				stk.pop();
				res = max(res, stk.empty() ? i - pre : i - stk.top());
			} else {
				pre = i;
			}
		}
		return res;
	}
};
int main() {
	return 0;
}
