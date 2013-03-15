#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') return *s == '\0';
		if (*(p+1) != '*') {
			return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
		} else {
			while ((*p == *s) || (*p == '.' && *s != '\0')) {
				if (isMatch(s, p+2)) return true;
				s++;
			}
			return isMatch(s, p+2);
		}
	}
};
int main() {
	return 0;
}
