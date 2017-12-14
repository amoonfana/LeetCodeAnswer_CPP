#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countBinarySubstrings(string s) {
		int prev = 0, cur = 1, sol = 0;

		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == s[i - 1]) { cur++; }
			else {
				prev = cur;
				cur = 1;
			}
			if (prev >= cur) { sol++; }
		}

		return sol;
	}
};

void main()
{
	Solution sol;

	string s = "00100";

	cout << sol.countBinarySubstrings(s) << endl;

	system("pause");
}