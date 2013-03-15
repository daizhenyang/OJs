#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	void combin_n_k(vector<vector<int> >& res, vector<int>& num, int n, int k, int cur, int select) {
		if(select == k) {
			res.push_back(num);
			return;
		}
		if(cur == n) {
			return ;
		}
		combin_n_k(res, num, n, k, cur + 1, select);
		num.push_back(cur + 1);
		combin_n_k(res, num, n, k, cur + 1, select + 1);
		num.pop_back();
	}
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > res;
		vector<int> num;
		combin_n_k(res, num, n, k, 0, 0);
		return res;
	}
};
int main() {
	return 0;
}
