#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int n = 0;

		for (int i = 0; i < S.size(); ++i) {
			if (S[i] > '-') { n += 1; }
		}

		int fg = n % K;
		int m = n + (n - 1) / K;

		string res(m,' ');
		int i, j, c = 0;

		for (i = 0, j = 0; i < fg; ++j) {
			if (S[j] > '-') { res[i++] = toupper(S[j]); }
		}
		if (fg == 0) { c = 1; }

		K += 1;
		for (; i < m; ++j) {
			if (c == 0) {
				res[i++] = '-';
				c += 1;
			}
			if (S[j] > '-') {
				res[i++] = toupper(S[j]);
				c = (c + 1) % K;
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	string s = "5F3Z-2e-9-w";

	cout << sol.licenseKeyFormatting(s, 4).c_str() << endl;

	system("pause");
}