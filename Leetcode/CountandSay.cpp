#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string res = "1", tmp;
		for(int i = 1;i < n;i++) {
			ostringstream sout;
			int len = res.size();
			for(int i = 0, j;i < len;i = j) {
				for(j = i;j < len && res[i] == res[j];j++);
				sout << (j - i) << res[i];
			}
			res = sout.str();
		}
		return res;
	}
};
int main() {
	return 0;
}
