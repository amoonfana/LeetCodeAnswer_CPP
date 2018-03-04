#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> vs;

	void findPaths(TreeNode* root, string s) {
		s.append(to_string(root->val));

		if (!root->left && !root->right) { vs.push_back(s); }
		else {
			s.append("->");

			if (root->left) { findPaths(root->left, s); }
			if (root->right) { findPaths(root->right, s); }
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) { return vs; }

		findPaths(root, "");

		return vs;
	}
};

void main()
{
	Solution sol;

	TreeNode t3(5);
	TreeNode t1(2);
	t1.right = &t3;
	TreeNode t2(3);
	TreeNode t0(1);
	t0.left = &t1;
	t0.right = &t2;

	vector<string> res = sol.binaryTreePaths(&t0);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].c_str() << endl;
	}

	system("pause");
}