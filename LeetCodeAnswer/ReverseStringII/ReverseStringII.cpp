#include <iostream>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		int n = s.size();
		int k2 = k + k;

		for (int i = 0; i < n; i += k2) {
			for (int l = i, h = (i + k < n) ? (i + k - 1) : (n - 1); l < h; ++l, --h) {
				swap(s[l], s[h]);
			}
		}

		return s;
	}
};

void main()
{
	Solution sol;

	string s = "abcdefg";

	cout << sol.reverseStr(s, 2).c_str() << endl;

	system("pause");
}