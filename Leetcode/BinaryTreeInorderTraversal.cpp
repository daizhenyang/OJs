#include <vector>
#include <cstring>
#include <stack>
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
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode *> stk;
		vector<int> res;
		TreeNode * tmp = root;
		while(tmp != NULL || stk.empty() == false) {
			while(tmp != NULL) {
				stk.push(tmp);
				tmp = tmp->left;
			}
			tmp = stk.top();
			stk.pop();
			res.push_back(tmp->val);
			tmp = tmp->right;
		}
		return res;
	}
};
int main() {
	return 0;
}
