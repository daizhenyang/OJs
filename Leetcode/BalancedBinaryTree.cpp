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
	int judge(TreeNode * root) {
		if(root == NULL) return 0;
		int lheight = judge(root->left);
		int rheight = judge(root->right);
		if(lheight == -1 || rheight == -1) return -1;
		if(rheight + 1 < lheight || lheight + 1 < rheight) return -1;
		return max(rheight, lheight) + 1;
	}
	bool isBalanced(TreeNode * root) {
		return judge(root) != -1;
	}
};
int main() {
	return 0;
}
