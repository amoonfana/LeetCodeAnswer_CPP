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
	bool isMatched(TreeNode* s, TreeNode* t) {
		if (!t && !s) { return true; }
		else if (!t || !s) { return false; }

		bool im = false;
		
		if (s->val == t->val) { im = isMatched(s->left, t->left) && isMatched(s->right, t->right); }

		return im;
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s || !t) { return false; }

		bool im = false;

		if (s->val == t->val) { im = isMatched(s, t); }

		if (!im) { im = isSubtree(s->left, t); }
		if (!im) { im = isSubtree(s->right, t); }

		return im;
	}
};

void main()
{
	Solution sol;

	TreeNode s3(1);
	TreeNode s4(2);
	TreeNode s1(4);
	TreeNode s2(5);
	s1.left = &s3;
	s1.right = &s4;
	TreeNode s0(3);
	s0.left = &s1;
	s0.right = &s2;

	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t0(4);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.isSubtree(&s0, &t0) << endl;

	system("pause");
}