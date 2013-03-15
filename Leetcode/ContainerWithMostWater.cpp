#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int> &height) {
		int n = height.size(), res = 0;
		int beg = 0, end = n - 1;
		while(beg < end) {
			res = max(res, min(height[beg], height[end]) * (end - beg));
			if(height[beg] < height[end]) {
				beg++;
			} else {
				end--;
			}
		}
		return res;
	}
};
int main() {
	return 0;
}
