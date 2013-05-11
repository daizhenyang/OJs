class compare {
public:
	bool operator() (ListNode * lhs, ListNode * rhs) {
		return lhs->val > rhs->val;
	}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * head = NULL;
        ListNode** tail = &head;
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for(int i = 0;i < lists.size();i++) {
            if(lists[i] != NULL) pq.push(lists[i]);
        }
        while(pq.size()) {
            ListNode * lhead = pq.top();
            pq.pop();
            *tail = lhead;
            tail = &(lhead->next);
            lhead = lhead->next;
            if(lhead != NULL) pq.push(lhead);
        }
        return head;
    }
};
