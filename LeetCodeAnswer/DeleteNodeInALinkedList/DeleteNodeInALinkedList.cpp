#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		*node = *node->next;
	}
};

void main()
{
	Solution sol;

	ListNode n1(1), n2(2), n3(3), n4(4);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	sol.deleteNode(&n3);

	system("pause");
}