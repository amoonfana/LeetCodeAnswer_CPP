#include <iostream>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int n = s.size();
		s[n] = ' ';
		string t(n, ' ');

		int l = 0;
		for (int i = 0; i <= n; ++i) {
			if (s[i] == ' ') {
				for (int j = i - l, k = i - 1; j < i; ++j, --k) { t[j] = s[k]; }

				l = 0;
			}
			else {
				l += 1;
			}
		}

		return t;
	}
};

void main()
{
	Solution sol;

	string s("ABC ABCDAB ABCDABCDABDE");

	cout << sol.reverseWords(s).c_str() << endl;

	system("pause");
}