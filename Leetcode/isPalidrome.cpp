#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0) return false;
		int div = 1;
		while(x / div >= 10) {
			div *= 10;
		}
		while(x) {
			int l = x / div;
			int r = x % 10;
			if(l != r) return false;
			x = (x % div) / 10;
			div /= 100;
		}
	}
};
