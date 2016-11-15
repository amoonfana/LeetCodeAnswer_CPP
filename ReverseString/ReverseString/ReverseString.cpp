#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
		{
			swap(s[i], s[j]);
		}

		return s;
	}
};

void main()
{
	Solution sol;
	string res = sol.reverseString("abc");

	cout << res << endl;

	system("pause");
}