#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode * build(vector<int>& num, int l, int r) {
		if(l > r) return NULL;
		int pos = (l + r) >> 1;
		TreeNode * root = new TreeNode(num[pos]);
		root->left  = build(num, l, pos - 1);
		root->right = build(num, pos + 1, r);
		return root;
	}
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return build(num, 0, num.size() - 1);
	}
};
int main() {
	int num[] = {3, 5, 8};
	vector<int> res(num, num + 3);
	Solution one;
	one.sortedArrayToBST(res);
	return 0;
}
