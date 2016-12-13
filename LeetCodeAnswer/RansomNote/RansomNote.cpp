#include <iostream>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int ht[26] = { 0 };

		int n = ransomNote.size();
		for (int i = 0; i < n; ++i)
		{
			ht[ransomNote[i] - 97] -= 1;
		}

		int m = magazine.size();
		for (int i = 0; i < m; ++i)
		{
			ht[magazine[i] - 97] += 1;
		}

		for (int i = 0; i < 26; ++i)
		{
			if (ht[i] < 0)
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

	cout << sol.canConstruct("aa", "aab") << endl;

	system("pause");
}