#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	stack<TreeNode*> s;
	bool forward;

public:
	BSTIterator(TreeNode* root, bool forward) {
		this->forward = forward;
		while (root != NULL) {
			s.push(root);
			root = forward ? root->left : root->right;
		}
	}

	TreeNode* next() {
		if (s.empty()) return NULL;
		TreeNode* top = s.top();
		s.pop();
		TreeNode* tmp = forward ? top->right : top->left;
		while (tmp != NULL) {
			s.push(tmp);
			tmp = forward ? tmp->left : tmp->right;
		}
		return top;
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		BSTIterator forward(root, true);
		BSTIterator backward(root, false);
		TreeNode* fn = forward.next();
		TreeNode* bn = backward.next();
		while (fn != bn) {
			int sum = fn->val + bn->val;
			if (sum == k) {
				return true;
			}
			else if (sum < k) {
				fn = forward.next();
			}
			else {
				bn = backward.next();
			}
		}
		return false;
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

	cout << sol.findTarget(&t0, 29) << endl;

	system("pause");
}