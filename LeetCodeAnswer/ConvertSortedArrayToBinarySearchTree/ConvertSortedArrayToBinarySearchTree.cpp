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
	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (end <= start) { return NULL; }

		int mid = (end + start) / 2;

		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, start, mid);
		root->right = sortedArrayToBST(nums, mid + 1, end);

		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size());
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	sol.sortedArrayToBST(nums);

	system("pause");
}