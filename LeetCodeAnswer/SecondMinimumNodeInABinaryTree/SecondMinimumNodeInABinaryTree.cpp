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
	int min1 = INT_MAX;
	int min2 = INT_MAX;

	int findSecondMinimumValue(TreeNode* root) {
		if (!root) { return 0; }

		findSecondMinimumValue(root->left);

		if (root->val < min2 && root->val != min1) { min2 = root->val; }
		if (min2 < min1) {
			int t = min1;
			min1 = min2;
			min2 = t;
		}

		findSecondMinimumValue(root->right);

		return (min2 < INT_MAX) ? min2 : -1;
	}
};

void main()
{
	Solution sol;

	TreeNode t3(5);
	TreeNode t4(7);
	TreeNode t1(2);
	TreeNode t2(5);
	t2.left = &t3;
	t2.right = &t4;
	TreeNode t0(2);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.findSecondMinimumValue(&t0) << endl;

	system("pause");
}