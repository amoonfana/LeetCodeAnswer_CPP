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
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (!root) { return 0; }
		else if (root->val < L) { return rangeSumBST(root->right, L, R); }
		else if (R < root->val) { return rangeSumBST(root->left, L, R); }

		return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
	}
};

void main()
{
	Solution sol;

	TreeNode t3(3);
	TreeNode t4(7);
	TreeNode t6(18);
	TreeNode t1(5);
	t1.left = &t3;
	t1.right = &t4;
	TreeNode t2(15);
	t2.right = &t6;
	TreeNode t0(10);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.rangeSumBST(&t0, 7, 15);

	system("pause");
}