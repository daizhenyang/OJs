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
	int maxHeight(TreeNode *root) {
		if(root == NULL) return 0;
		return max(maxHeight(root->left), maxHeight(root->right)) + 1;
	}
};
int main() {
	return 0;
}
