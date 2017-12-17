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
	int tilt(TreeNode* root, vector<int>& s) {
		if (!root) { return 0; }

		int left = tilt(root->left, s);
		int right = tilt(root->right, s);
		int sum = root->val + left + right;

		root->val = abs(left - right);
		s.push_back(root->val);

		return sum;
	}

	int findTilt(TreeNode* root) {
		vector<int> s;
		tilt(root, s);

		int sum = 0;
		for (int i = 0; i < s.size(); ++i) {
			sum += s[i];
		}

		return sum;
	}
};

void main()
{
	Solution sol;

	TreeNode t1(2);
	TreeNode t2(3);
	TreeNode t0(1);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.findTilt(&t0) << endl;

	system("pause");
}