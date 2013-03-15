#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canJump(int A[], int n) {
		int maxn = 0;
		for(int i = 0;i < n && i <= maxn;i++) {
			maxn = max(maxn, A[i] + i);
		}
		return maxn >= n - 1;
	}
};
int main() {
	return 0;
}
