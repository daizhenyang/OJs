#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int sqrt(int x) {
		int low = 0, high = 65536, res = 0;
		while(low <= high) {
			int mid = (low + high) >> 1;
			if(1LL * mid * mid <= x) {
				res = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return res;
	}
};
int main() {
	return 0;
}
