class Solution {
public:
    ListNode *deleteDuplicates(ListNode *list) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = NULL, * tail = NULL, * next;
        while(list) {
            next = list->next;
            while(next && list->val == next->val) {
                next = next->next;
            }
            if(list->next == next) {
                list->next = NULL;
                if(tail == NULL) {
                    head = tail = list;
                } else {
                    tail = tail->next = list;
                }
            }
            list = next;
        }
        return head;
    }
};
