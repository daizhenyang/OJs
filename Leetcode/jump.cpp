#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int jump(int A[], int n) {
		int res = 0;
		for(int i = 0, j = 1, pos;j < n;i = j, j = pos + 1){
			pos = j;
			for(int k = i;k < j;k++) {
				pos = max(pos, A[k] + k);
			}
			res++;
		}
		return res;
	}
};
int main() {
	return 0;
}
