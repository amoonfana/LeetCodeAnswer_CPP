#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
		{
			return true;
		}
		else if (p != NULL && q != NULL && p->val == q->val)
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}

		return false;
	}
};

void main()
{
	Solution sol;

	TreeNode tn3(3);
	TreeNode tn2(2);
	tn2.left = &tn3;
	TreeNode tn1(1);
	tn1.left = &tn2;
	TreeNode tn0(0);
	tn0.left = &tn1;

	cout << sol.isSameTree(&tn0, &tn0) << endl;

	system("pause");
}