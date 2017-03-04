#include <iostream>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word[0] < 91)
		{
			if (word[1] < 91)
			{
				for (int i = 2; i < word.size(); ++i)
				{
					if (word[i] > 90) { return false; }
				}
			}
			else
			{
				for (int i = 2; i < word.size(); ++i)
				{
					if (word[i] < 91) { return false; }
				}
			}
		}
		else
		{
			for (int i = 1; i < word.size(); ++i)
			{
				if (word[i] < 91) { return false; }
			}
		}

		return true;
	}
};

void main()
{
	Solution sol;

	string word = "FlaG";

	cout << sol.detectCapitalUse(word) << endl;

	system("pause");
}