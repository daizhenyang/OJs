#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int n = s1.size(), m = s2.size(), len = s3.size();
		if(s1.size() + s2.size() != s3.size()) return false;
		vector<vector<bool> > dp(n + 1, vector<bool>(m + 1));
		dp[0][0] = true;
		for(int i = 0;i < len;i++) {
			for(int j = max(0, i - m);j <= i && j <= n;j++) {
				int k = i - j;
				if(dp[j][k] == false) continue;
				if(j < n && s3[i] == s1[j]) dp[j + 1][k] = true;
				if(k < m && s3[i] == s2[k]) dp[j][k + 1] = true;
			}
		}
		return dp[n][m];
	}
};
int main() {
	return 0;
}
