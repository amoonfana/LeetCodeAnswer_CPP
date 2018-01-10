#include <algorithm>
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
	int deep(TreeNode* root, int& d) {
		if (!root) { return 0; }

		int dl = 0, dr = 0;
		int dml = deep(root->left, dl), dmr = deep(root->right, dr);
		d = 1 + max(dl, dr);

		return max(dl + dr, max(dml, dmr));
	}

	int diameterOfBinaryTree(TreeNode* root) {
		if (!root) { return 0; }

		int d;
		return deep(root, d);
	}
};

void main()
{
	Solution sol;

	TreeNode t3(4);
	TreeNode t4(5);
	TreeNode t1(2);
	t1.left = &t3;
	t1.right = &t4;
	TreeNode t2(3);
	TreeNode t0(1);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.diameterOfBinaryTree(&t0) << endl;

	system("pause");
}