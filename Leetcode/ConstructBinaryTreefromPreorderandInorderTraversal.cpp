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
	TreeNode * build(vector<int>& preorder, int& p, vector<int>& inorder, int l, int r) {
		if(l >= r) {
			return NULL;
		}
		int val = preorder[p];
		int pos = find(inorder.begin() + l, inorder.begin() + r, val) - inorder.begin();
		TreeNode * root = new TreeNode(val);
		if(l < pos) root->left  = build(preorder, ++p, inorder, l, pos);
		if(pos + 1 < r) root->right = build(preorder, ++p, inorder, pos + 1, r);
		return root;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int n = inorder.size(), p = 0;
		return build(preorder, p, inorder, 0, n);
	}
};

int main() {
	return 0;
}
