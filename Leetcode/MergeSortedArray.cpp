#include <cstdlib>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		for(int pos = m + n - 1;pos >= 0;pos--) {
			if(n == 0 || m != 0 && A[m - 1] > B[n - 1]) {
				A[pos] = A[--m];
			} else {
				A[pos] = B[--n];
			}
		}
	}

};

int main() {
	return 0;
}
