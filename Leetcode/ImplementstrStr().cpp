#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		int m = strlen(needle);
		if(m == 0) return haystack;
		vector<int> next(m);
		int k = -1, q = -1;
		next[0] = -1;
		for(int i = 1;i < m;i++) {
			while(k != -1 && needle[k + 1] != needle[i]) k = next[k];
			if(needle[k + 1] == needle[i]) k++;
			next[i] = k;
		}
		for(char * str = haystack;*str;str++) {
			while(q > -1 && *str != needle[q + 1]) q = next[q];
			if(needle[q + 1] == *str) q++;
			if(q == m - 1) return str - m + 1;
		}
		return NULL;
	}
};
int main() {
	return 0;
}
