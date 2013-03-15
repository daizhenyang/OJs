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
	TreeNode * build(vector<int>& inorder, int l, int r, vector<int>& postorder, int& p) {
		if(l >= r) {
			p++;
			return NULL;
		}
		int val = postorder[p];
		int pos = find(inorder.begin() + l, inorder.begin() + r, val) - inorder.begin();
		TreeNode * root = new TreeNode(val);
		root->right = build(inorder, pos + 1, r, postorder, --p);
		root->left  = build(inorder, l, pos, postorder, --p);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int n = inorder.size(), p = postorder.size() - 1;
		return build(inorder, 0, n, postorder, p);
	}
};
int main() {
	return 0;
}
