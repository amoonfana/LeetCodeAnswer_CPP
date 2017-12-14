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
	void t2t(TreeNode* t, string& s) {
		s.append(to_string(t->val));

		if (t->left) {
			s.append("(");
			t2t(t->left, s);
			s.append(")");
		}

		if (t->right) {
			if (!t->left) { s.append("()"); }

			s.append("(");
			t2t(t->right, s);
			s.append(")");
		}
	}

	string tree2str(TreeNode* t) {
		if (!t) { return ""; }
		string s;
		t2t(t, s);
		return s;
	}
};

void main()
{
	Solution sol;

	TreeNode t3(2);
	TreeNode t4(4);
	TreeNode t5(7);
	TreeNode t1(3);
	TreeNode t2(6);
	t1.left = &t3;
	t1.right = &t4;
	t2.right = &t5;
	TreeNode t0(5);
	t0.left = &t1;
	t0.right = &t2;

	cout << sol.tree2str(&t0).c_str() << endl;

	system("pause");
}