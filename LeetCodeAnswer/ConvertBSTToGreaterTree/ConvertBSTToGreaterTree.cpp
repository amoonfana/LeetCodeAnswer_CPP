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
	int getSum(TreeNode* root, int parent) {
		if (!root) { return 0; }

		int sum = getSum(root->right, parent) + root->val;
		root->val = sum + parent;
		sum += getSum(root->left, root->val);

		return sum;
	}

	TreeNode* convertBST(TreeNode* root) {
		getSum(root, 0);

		return root;
	}
};

void main()
{
	Solution sol;

	TreeNode t1(2);
	TreeNode t2(13);
	TreeNode t0(5);
	t0.left = &t1;
	t0.right = &t2;

	sol.convertBST(&t0);

	system("pause");
}