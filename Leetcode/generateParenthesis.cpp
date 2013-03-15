#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	void generate(int l, int r, int dep, char* buf, vector<string>& res) {
		if(l == 0 && r == 0) {
			buf[dep] = 0;
			res.push_back(buf);
			return;
		}
		if(l != 0) {
			buf[dep] = '(';
			generate(l - 1, r, dep + 1, buf, res);
		}
		if(l < r) {
			buf[dep] = ')';
			generate(l, r - 1, dep + 1, buf, res);
		}
	}
	vector<string> generateParenthesis(int n) {
		char* buf = new char[(n << 1) | 1];
		vector<string> res;
		generate(n, n, 0, buf, res);
		delete buf;
		return res;
	}
};
int main() {
	return 0;
}
