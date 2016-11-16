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
	 int maxDepth(TreeNode* root) {
		 if (root == NULL)
		 {
			 return 0;
		 }
		 else if (root->left == NULL)
		 {
			 return 1;
		 }
		 else
		 {
			 return (maxDepth(root->left) + 1);
		 }
	 }
 };

 void main()
 {
	 Solution sol;

	 TreeNode tn3(3);
	 TreeNode tn2(2);
	 tn2.left = &tn3;
	 TreeNode tn1(1);
	 tn1.left = &tn2;
	 TreeNode tn0(0);
	 tn0.left = &tn1;

	 cout << sol.maxDepth(&tn0) << endl;

	 system("pause");
 }