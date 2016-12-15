#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		////If char has no limitation
		//int n = s.length();
		//unordered_map<char, int> um;

		//for (int i = 0; i < n; ++i)
		//{
		//	++um[s[i]];
		//}

		//for (int i = 0; i < n; i++)
		//{
		//	if (um[s[i]] == 1)
		//	{
		//		return i;
		//	}
		//}

		//return -1;

		//If char is from 'a' to 'z'
		int n = s.length();
		int ht[26] = {0};

		for (int i = 0; i < n; i++)
		{
			ht[s[i] - 'a'] += 1;
		}

		for (int i = 0; i < n; i++)
		{
			if (ht[s[i] - 'a'] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};

void main()
{
	Solution sol;

	string s = "loveleetcode";

	cout << sol.firstUniqChar(s) << endl;

	system("pause");
}