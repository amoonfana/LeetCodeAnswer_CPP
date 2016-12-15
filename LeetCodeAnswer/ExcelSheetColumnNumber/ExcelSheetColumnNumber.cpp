#include <iostream>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int n = s.length();
		int res = 0;

		for (int i = 0; i < n; ++i)
		{
			res = res*26 + (s[i] - 64);
		}

		return res;
	}
};

void main()
{
	Solution sol;

	string s = "AAB";

	cout << sol.titleToNumber(s) << endl;

	system("pause");
}