#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) { return NULL; }
		if (!head->next) { return head; }

		if (head->val == head->next->val) {
			head->next = head->next->next;
			deleteDuplicates(head);
		}
		else { deleteDuplicates(head->next); }

		return head;
	}
};

void main()
{
	Solution sol;

	ListNode* ln1 = new ListNode(1);
	ListNode* ln2 = new ListNode(1);
	ListNode* ln3 = new ListNode(2);
	ListNode* ln4 = new ListNode(3);
	ListNode* ln5 = new ListNode(3);
	ln1->next = ln2;
	ln2->next = ln3;
	ln3->next = ln4;
	ln4->next = ln5;

	sol.deleteDuplicates(ln1);

	for (ListNode* p = ln1; p; p = p->next) {
		cout << p->val << endl;
	}

	system("pause");
}