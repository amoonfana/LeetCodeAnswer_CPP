#include <iostream>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int ascii = 0;
		int n = s.size();

		for (int i = 0; i < n; ++i)
		{
			ascii += t[i] - s[i];
		}

		ascii += t.back();
		
		return ascii;
	}
};

void main()
{
	Solution sol;

	cout << sol.findTheDifference("", "y") << endl;

	system("pause");
}