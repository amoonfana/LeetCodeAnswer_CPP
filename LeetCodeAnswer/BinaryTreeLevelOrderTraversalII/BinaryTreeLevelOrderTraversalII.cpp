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
	void postOrder(TreeNode* root, vector<vector<int>> &res, int dp) {
		if (!root) { return; }

		if (res.size() < dp) { res.resize(dp); }
		res[dp - 1].push_back(root->val);

		postOrder(root->left, res, dp + 1);
		postOrder(root->right, res, dp + 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;

		postOrder(root, res, 1);
		reverse(res.begin(), res.end());

		return res;
	}
};

void main()
{
	Solution sol;

	TreeNode t3(15);
	TreeNode t4(7);
	TreeNode t1(9);
	TreeNode t2(20);
	t2.left = &t3;
	t2.right = &t4;
	TreeNode t0(3);
	t0.left = &t1;
	t0.right = &t2;

	vector<vector<int>> res = sol.levelOrderBottom(&t0);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << endl;
		}
	}

	system("pause");
}