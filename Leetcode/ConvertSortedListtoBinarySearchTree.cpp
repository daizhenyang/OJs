class Solution {
public:
	int size(ListNode* head) {
		int res = 0;
		while(head) {
			res++;
			head = head->next;
		}
		return res;
	}
	TreeNode* build(ListNode *& head, int l, int r) {
		if(l > r) {
			return NULL;
		}
		int mid = (l + r) >> 1;
		TreeNode* root = new TreeNode(0);
		if(l <= mid) root->left  = build(head, l, mid - 1);
		root->val = head->val;
		head = head->next;
		if(mid <= r) root->right = build(head, mid + 1, r);
		return root;
	}
	TreeNode* sortedListToBST(ListNode *head) {
		return build(head, 0, size(head) - 1);
	}
};
