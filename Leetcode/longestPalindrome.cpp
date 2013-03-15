#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		int  max_length = 0, idx = 0;
		for(int i = 0, j;i < n;i++) {
			for(j = 0;i - j >= 0 && i + j < n && s[i - j] == s[i + j];j++);
			j--;
			if(max_length < j * 2 + 1) {
				max_length = j * 2 + 1;
				idx = i - j;
			}
		}
		for(int i = 0, j;i < n;i++) {
			for(j = 1;i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j];j++);
			j--;
			if(max_length < j * 2) {
				max_length = j * 2;
				idx = i - j + 1;
			}
		}
		return s.substr(idx, max_length);
	}
};
int main() {
	return 0;
}
