#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int v = max(a.size(), b.size());
		a.insert(0, v - a.size(), '0');
		b.insert(0, v - b.size(), '0');
		string res(v, '0');
		int c = 0;
		for(int i = v - 1;i >= 0;i--) {
			int v = a[i] - '0' + b[i] - '0' + c;
			c = v / 2;
			res[i] += v % 2;
		}
		if(c) {
			res.insert(0, 1, '1');
		}
		return res;
	}
};
int main() {
	return 0;
}
