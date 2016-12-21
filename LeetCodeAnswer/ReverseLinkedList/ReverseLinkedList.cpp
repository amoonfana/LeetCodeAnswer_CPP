#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head, ListNode* pre = NULL) {
		if (head == NULL) { return pre; }

		ListNode* res = reverseList(head->next, head);
		head->next = pre;

		return res;
	}
};

void print(ListNode* head)
{
	if (head == NULL)
	{
		return;
	}

	cout << head->val << endl;
	print(head->next);
}

void main()
{
	Solution sol;

	ListNode ln4(4);
	ListNode ln3(3);
	ln3.next = &ln4;
	ListNode ln2(2);
	ln2.next = &ln3;
	ListNode ln1(1);
	ln1.next = &ln2;


	ListNode* res = sol.reverseList(&ln1);
	print(res);

	system("pause");
}