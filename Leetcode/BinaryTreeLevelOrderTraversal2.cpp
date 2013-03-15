#include <queue>
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > res;
		vector<int> cur;
		if(root == NULL) return res;
		queue<TreeNode *> q;
		q.push(root);
		TreeNode* last = root;
		while(q.empty() == false) {
			TreeNode * root = q.front();
			q.pop();
			cur.push_back(root->val);
			if(root->left)  q.push(root->left);
			if(root->right) q.push(root->right);
			if(last == root) {
				if(q.size()) {
					last = q.back();
				}
				res.push_back(cur);
				cur = vector<int>();
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main() {
	return 0;
}
