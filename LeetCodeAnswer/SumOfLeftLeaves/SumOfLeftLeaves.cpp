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
	int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
		if (root == NULL)
		{
			return 0;
		}

		if (!root->left && !root->right)
		{
			return isleft ? root->val : 0;
		}

		return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}
};

void main()
{
	Solution sol;

	TreeNode tn15(15);
	TreeNode tn7(7);

	TreeNode tn9(9);
	TreeNode tn20(20);
	tn20.left = &tn15;
	tn20.right = &tn7;

	TreeNode tn3(3);
	tn3.left = &tn9;
	tn3.right = &tn20;

	cout << sol.sumOfLeftLeaves(&tn3) << endl;

	system("pause");
}