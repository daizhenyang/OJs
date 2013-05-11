class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == 1) {
            return reverse(head, n - m + 1);
        } else {
            ListNode ** prev = &head;
            for(int i = 1;i < m;i++) {
                prev = &(*prev)->next;
            }
            *prev = reverse(*prev, n - m + 1);
            return head;
        }
    }
private:
    ListNode *reverse(ListNode* l, int length) {
        ListNode * head = l, * next;
        for(int i = 0;i < length;i++) {
            head = head->next;
        }
        for(int i = 0;i < length;i++) {
            next = l->next;
            l->next = head;
            head = l;
            l = next;
        }
        return head;
    }
};
