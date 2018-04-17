#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> t(numRows);

		for (int i = 0; i < numRows; ++i) {
			t[i] = vector<int>(i + 1);
			t[i][0] = t[i][i] = 1;

			for (int j = 1; j < i; ++j) {
				t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
			}
		}

		return t;
	}
};

void main()
{
	Solution sol;

	vector<vector<int>> res;

	res = sol.generate(5);

	int n = res.size(), m;
	for (int i = 0; i < n; ++i) {
		m = res[i].size();
		for (int j = 0; j < m; ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
}