#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for(int i = 0;i < n;i++) {
			for(int j = i;j < n - i - 1;j++) {
				int value = matrix[i][j];
				for(int k = 0;k < 4;k++) {
					swap(i, j);
					j = n - 1 - j;
					swap(value, matrix[i][j]);
				}
			}
		}
	}
};
int main() {
	return 0;
}
