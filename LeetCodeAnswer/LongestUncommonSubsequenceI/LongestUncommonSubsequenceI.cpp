#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		return (a == b) ? -1 : max(a.length(), b.length());
	}
};

void main()
{
	Solution sol;

	string a = "aba", b = "cdc";

	cout << sol.findLUSlength(a, b) << endl;

	system("pause");
}