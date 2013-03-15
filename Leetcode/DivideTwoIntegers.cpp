#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		int neg = 0, res = 0;
		neg ^= (divisor  < 0);
		neg ^= (dividend < 0);
		unsigned int end = dividend < 0 ? -dividend : dividend;
		unsigned int sor = divisor  < 0 ? -divisor  : divisor;
		unsigned int mod = 0;
		for(int i = 31;i >= 0;i--) {
			res <<= 1;
			mod = (mod << 1) + ((end & (1u << i)) >> i);
			if(mod >= sor) {
				res |= 1;
				mod -= sor;
			}
		}
		return neg ? -res : res;
	}
};
int main() {
	return 0;
}
