
#include <vector>
#include <cstring>
#include <queue>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
		for(int i = 1;i < res.size();i += 2) {
			reverse(res[i].begin(), res[i].end());
		}
		return res;
	}
};
int main() {
	return 0;
}
