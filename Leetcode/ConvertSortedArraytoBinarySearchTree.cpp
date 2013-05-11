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
