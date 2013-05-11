#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode * lower_head = NULL, * lower_tail = NULL;
		ListNode * upper_head = NULL, * upper_tail = NULL;
		while(head) {
            ListNode * next = head->next;
            head->next = NULL;
			if(head->val < x) {
                if(lower_tail == NULL) {
                    lower_head = lower_tail = head;
                } else {
                    lower_tail = lower_tail->next = head;
                }
			} else {
                if(upper_tail == NULL) {
                    upper_head = upper_tail = head;
                } else {
                    upper_tail = upper_tail->next = head;
                }
			}
			head = next;
		}
		if(lower_head == NULL) return upper_head;
		lower_tail->next = upper_head;
		return lower_head;
	}
};
