#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

////My own solution
//class Solution {
//public:
//	int getMinimumDifference(TreeNode* root)
//	{
//		if (!root) { return INT_MAX; }
//
//		int lRes = getMinimumDifference(root->left);
//		int rRes = getMinimumDifference(root->right);
//
//		TreeNode *left = root->left;
//		TreeNode *right = root->right;
//
//		while (left && left->right) { left = left->right; }
//		while (right && right->left) { right = right->left; }
//
//		int res;
//		if (!left && !right) { res = INT_MAX; }
//		else if (!left) { res = right->val - root->val; }
//		else if (!right) { res = root->val - left->val; }
//		else { res = min(root->val - left->val, right->val - root->val); }
//
//		return min(res, min(lRes, rRes));
//	}
//};

class Solution {
public:
	int min_dif = INT_MAX, val = -1;

	int getMinimumDifference(TreeNode* root) {
		if (root->left) { getMinimumDifference(root->left); }

		if (val >= 0) { min_dif = min(min_dif, root->val - val); }
		val = root->val;

		if (root->right) { getMinimumDifference(root->right); }

		return min_dif;
	}
};

void main()
{
	Solution sol;

	TreeNode tn2(2);
	TreeNode tn1(3);
	tn1.left = &tn2;
	TreeNode tn0(1);
	tn0.right = &tn1;

	cout << sol.getMinimumDifference(&tn0) << endl;

	system("pause");
}