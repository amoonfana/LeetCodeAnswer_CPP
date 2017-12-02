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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1) { return t2; }
		if (!t2) { return t1; }

		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		t1->val += t2->val;
		return t1;
	}
};

void main()
{
	Solution sol;

	TreeNode t14(5);
	TreeNode t12(3);
	t12.left = &t14;
	TreeNode t13(2);
	TreeNode t11(1);
	t11.left = &t12;
	t11.right = &t13;

	TreeNode t24(4);
	TreeNode t25(7);
	TreeNode t22(1);
	t22.right = &t24;
	TreeNode t23(3);
	t23.right = &t25;
	TreeNode t21(2);
	t21.left = &t22;
	t21.right = &t23;

	sol.mergeTrees(&t11, &t21);

	system("pause");
}