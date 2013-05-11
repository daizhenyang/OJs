class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * tail = head, *curr = head;
        while(curr) {
            if(curr->val != tail->val) {
                tail = tail->next = curr;
            }
            curr = curr->next;
        }
        if(tail != NULL) {
            tail->next = NULL;
        }
        return head;
    }
};
