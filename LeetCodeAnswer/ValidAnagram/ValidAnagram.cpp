#include <iostream>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int n = s.length();
		int m = t.length();

		if (n != m)
		{
			return false;
		}

		int ascii[26] = { 0 };

		for (int i = 0; i < n; ++i)
		{
			ascii[s[i] - 'a'] += 1;
			ascii[t[i] - 'a'] -= 1;
		}

		for (int i = 0; i < 26; ++i)
		{
			if (ascii[i] != 0)
			{
				return false;
			}
		}

		return true;
	}
};

void main()
{
	Solution sol;

	string s = "anagram";
	string t = "nagaram";

	cout << sol.isAnagram(s, t) << endl;

	system("pause");
}