class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode * head =  NULL;
		ListNode **tail = &head;
		while(l1 != NULL && l2 != NULL) {
            ListNode ** ptr = l1->val < l2->val ? &l1 : &l2;
            *tail = *ptr;
            tail  = &((*ptr)->next);
            *ptr  = (*ptr)->next;
		}
		*tail = l1 == NULL ? l2 : l1;
		return head;
	}
};

