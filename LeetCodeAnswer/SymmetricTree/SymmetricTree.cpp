#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool check(TreeNode* l, TreeNode* r) {
		if (!l && !r) { return true; }

		if (l && r) { return (l->val == r->val) && check(l->left, r->right) && check(l->right, r->left); }

		return false;
	}

	bool isSymmetric(TreeNode* root) {
		if (!root) { return true; }

		return check(root->left, root->right);
	}
};

void main()
{
	Solution sol;

	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(4);
	TreeNode t6(3);
	TreeNode t1(2);
	t1.left = &t3;
	t1.right = &t4;
	TreeNode t2(3);
	t2.left = &t5;
	t2.right = &t6;
	TreeNode t0(1);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.isSymmetric(&t0) << endl;

	system("pause");
}