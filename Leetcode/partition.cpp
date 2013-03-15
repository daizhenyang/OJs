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
			if(head->val < x) {
				lower_tail = lower_head == NULL ?
					lower_head = new ListNode(head->val) : lower_tail->next = new ListNode(head->val);
			} else {
				upper_tail = upper_head == NULL ?
					upper_head = new ListNode(head->val) : upper_tail->next = new ListNode(head->val);
			}
			head = head->next;
		}
		if(lower_head == NULL) return upper_head;
		lower_tail->next = upper_head;
		return lower_head;
	}
};
int main() {
	return 0;
}
