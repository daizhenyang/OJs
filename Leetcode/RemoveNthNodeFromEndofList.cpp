class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode ** prev = &head, next = &head;
        int step = 1;
        while(*next != NULL) {
            if(step > n) prev = &(*prev)->next;
            next = &(*next)->next;
            step++;
        }
        ListNode * p = *prev;
        *prev = (*prev)->next;
        delete p;
        return head;
    }
};

