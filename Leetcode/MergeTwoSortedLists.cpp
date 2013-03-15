#include <cstdlib>
#include <vector>
#include <cassert>
#include <cstdio>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode * head =  NULL;
		ListNode **tail = &head;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val < l2->val) {
				*tail = l1;
				tail  = &(l1->next);
				l1    = l1->next;
			} else {
				*tail = l2;
				tail  = &(l2->next);
				l2    = l2->next;
			}
		}
		*tail = l1 == NULL ? l2 : l1;
		return head;
	}
};

int main() {
	return 0;
}
