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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}

		TreeNode* ttn = root->left;
		root->left = root->right;
		root->right = ttn;
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};

void main()
{
	Solution sol;

	TreeNode tn1(1);
	TreeNode tn3(3);
	TreeNode tn2(2);
	tn2.left = &tn1;
	tn2.right = &tn3;

	TreeNode tn6(6);
	TreeNode tn9(9);
	TreeNode tn7(7);
	tn7.left = &tn6;
	tn7.right = &tn9;

	TreeNode tn4(4);
	tn4.left = &tn2;
	tn4.right = &tn7;

	sol.invertTree(&tn4);

	system("pause");
}