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
	void average(TreeNode* root, int l, vector<double>& sum, vector<int>& num) {
		if (!root) { return; }

		if (sum.size() == l) {
			sum.push_back(root->val);
			num.push_back(1);
		}
		else {
			sum[l] += root->val;
			num[l] += 1;
		}

		l += 1;
		average(root->left, l, sum, num);
		average(root->right, l, sum, num);
	}

	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> sum;
		vector<int> num;

		average(root, 0, sum, num);

		for (int i = 0; i < sum.size(); i++) { sum[i] /= num[i]; }

		return sum;
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

	vector<double> res = sol.averageOfLevels(&t0);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	system("pause");
}