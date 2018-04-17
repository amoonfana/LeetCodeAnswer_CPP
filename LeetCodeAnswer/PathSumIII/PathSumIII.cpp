#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int cal(TreeNode* root, int sum, unordered_map<int, int>& ht, int pre) {
		if (!root) return 0;

		root->val += pre;
		int res = (root->val == sum) + ht[root->val - sum];
		ht[root->val]+=1;

		res += cal(root->left, sum, ht, root->val) + cal(root->right, sum, ht, root->val);   
		ht[root->val]-=1;

		return res;
	}

	int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int> ht;
		return cal(root, sum, ht, 0);
	}
};


void main()
{
	Solution sol;

	TreeNode t6(3);
	TreeNode t7(-2);
	TreeNode t8(1);
	TreeNode t3(3);
	t3.left = &t6;
	t3.right = &t7;
	TreeNode t4(2);
	t4.right = &t8;
	TreeNode t5(11);
	TreeNode t1(5);
	t1.left = &t3;
	t1.right = &t4;
	TreeNode t2(-3);
	t2.right = &t5;
	TreeNode t0(10);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.pathSum(&t0, 8) << endl;

	system("pause");
}