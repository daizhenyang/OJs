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
	int get_value(ListNode * & l) {
		int v = 0;
		if(l != NULL) {
			v = l->val;
			l = l->next;
		}
		return v;
	}
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode * res = new ListNode(0);
		ListNode * ret = res;
		int c = 0;
		while(l1 != NULL || l2 != NULL) {
			int v = get_value(l1) + get_value(l2) + c;
			c = v / 10;
			res->next = new ListNode(v % 10);
			res = res->next;
		}
		if(c) {
			res->next = new ListNode(c);
		}
		return ret->next;
	}
};
int main() {
	return 0;
}
