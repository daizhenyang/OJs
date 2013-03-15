#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		vector<int> res(n + 1);
		res[0] = 1;
		for(int i = 1;i <= n;i++) {
			res[i] += res[i - 1];
			if(i >= 2) res[i] += res[i - 2];
		}
		return res[n];
	}
};
int main() {
	return 0;
}
