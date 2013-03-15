#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res(1 << n);
		for(int i = 1;i < (1 << n);i++) {
			res[i] = i ^ (i >> 1);
		}
		return res;
	}
};
int main() {
	return 0;
}
