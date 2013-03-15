#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	double pow(double x, int n) {
		bool is_neg = n < 0;
		double res = 1;
		unsigned int N = n < 0 ? (-n) : n;
		while(N != 0) {
			if(N & 1) res *= x;
			N >>= 1;
			x *=x;
		}
		return is_neg ? 1 / res : res;
	}
};
int main() {
	return 0;
}
