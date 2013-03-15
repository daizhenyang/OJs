class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int res = -1;
		for(vector<int>::iterator i = num.begin();i != num.end();++i) {
			for(vector<int>::iterator j = i + 1;j != num.end();++j) {
				vector<int>::iterator k = lower_bound(j + 1, num.end(), target - *i - *j);
				if(k != num.end()) {
					int v = *i + *j + *k;
					if(res == -1 || abs(v - target) < res) {
						res = abs(v - target);
					}
				}
				if(k != num.begin() && k != j + 1) {
					k--;
					int v = *i + *j + *k;
					if(res == -1 || abs(v - target) < res) {
						res = abs(v - target);
					}
				}
			}
		}
		return abs(target - res);
	}
};

int main() {
	return 0;
}
