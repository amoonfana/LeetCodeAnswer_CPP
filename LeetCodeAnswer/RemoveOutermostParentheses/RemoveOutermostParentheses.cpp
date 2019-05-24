#include <iostream>

using namespace std;

class Solution {
public:
	string removeOuterParentheses(string S) {
		int n = S.size(), c = -1;
		string r("");

		for (int i = 0; i < n; ++i) {
			if (S[i] == '(') {
				if ((++c) > 0) {
					r.push_back(S[i]);
				}
			}
			else if (S[i] == ')') {
				if ((c--) > 0) {
					r.push_back(S[i]);
				}
			}
		}

		return r;
	}
};

void main()
{
	Solution sol;

	cout << sol.removeOuterParentheses("(()())(())(()(()))").c_str() << endl;

	system("pause");
}