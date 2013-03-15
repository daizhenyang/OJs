#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int c = 1, n = digits.size();
		for(int i = n - 1;i >= 0;i--) {
			digits[i] = (c + digits[i]) % 10;
			c = (c + digits[i]) / 10;
		}
		vector<int> res;
		if(c) {
			res.push_back(c);
		}
		copy(digits.begin(), digits.end(), back_inserter<vector<int> >(res));
		return res;
	}
};
int main() {
	return 0;
}
