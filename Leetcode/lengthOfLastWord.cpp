#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int res = -1, pre = 0;
		for(const char* str = s;*str;str++) {
			if(*str == ' ' && res != -1) {
				pre = res;
				res = -1;
			}
			if(isalpha(*str)) {
				res = (res == -1) ? 1 : res + 1;
			}
		}
		return res == -1 ? pre : res;
	}
};
int main() {
	return 0;
}
