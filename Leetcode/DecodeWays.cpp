#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int todigit(char ch0, char ch1) {
		return (ch0 - '0') * 10 + ch1 - '0';
	}
	int numDecodings(string s) {
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;
		for(int i = 1;i <= n;i++) {
			if(s[i - 1] != '0') {
				dp[i] += dp[i - 1];
			}
			if(i > 1 && '0' < s[i - 2] && todigit(s[i - 2], s[i - 1]) <= 26) {
				dp[i] += dp[i - 2];
			}
		}
		return n == 0 ? 0 : dp[n];
	}
};
int main() {
	return 0;
}
