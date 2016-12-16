#include <iostream>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int n = s.length();
		int ht[58] = { 0 };
		int res = 0;

		int idx;
		for (int i = 0; i < n; ++i)
		{
			idx = s[i] - 'A';

			if (ht[idx] == 0)
			{
				ht[idx] += 1;
			}
			else
			{
				res += 2;
				ht[idx] -= 1;
			}
		}

		if (res < n)
		{
			res += 1;
		}

		return res;
	}
};

void main()
{
	Solution sol;

	string s = "ABCDBCDA";

	cout << sol.longestPalindrome(s) << endl;

	system("pause");
}