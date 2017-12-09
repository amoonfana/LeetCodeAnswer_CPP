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
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) { return root; }
		if (root->val < L) { return trimBST(root->right, L, R); }
		if (root->val > R) { return trimBST(root->left, L, R); }

		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);

		return root;
	}
};

void main()
{
	Solution sol;

	TreeNode t4(1);
	TreeNode t3(2);
	t3.left = &t4;
	TreeNode t1(0);
	t1.right = &t3;
	TreeNode t2(4);
	TreeNode t0(3);
	t0.left = &t1;
	t0.right = &t2;

	sol.trimBST(&t0, 1, 2);

	system("pause");
}