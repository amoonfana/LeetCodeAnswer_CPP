#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int n = M.size() + 1, m = M[0].size() + 1;

		int num1, num2;
		if (n == 2 && m == 2) { return M; }
		else if (n == 2 || m == 2) {
			num1 = 3;
			num2 = 2;
		}
		else {
			num1 = 6;
			num2 = 4;
		}

		vector<vector<int>> T(n + 1);
		T[0] = vector<int>((m + 1), 0);
		for (int i = 1; i < n; ++i) {
			T[i] = vector<int>((m + 1), 0);
			for (int j = 1; j < m; ++j) { T[i][j] = M[i - 1][j - 1]; }
		}
		T[n] = vector<int>((m + 1), 0);

		vector<int> t(m + 1, 0);
		int num = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) { t[j] = T[i - 1][j] + T[i][j] + T[i + 1][j]; }
			for (int j = 1; j < m; ++j) {
				if ((i > 1 && i < (n - 1)) && (j > 1 && j < (m - 1))) { num = 9; }
				else if ((i > 1 && i < (n - 1)) || (j > 1 && j < (m - 1))) { num = num1; }
				else { num = num2; }

				M[i - 1][j - 1] = (t[j - 1] + t[j] + t[j + 1])/num;
			}
		}

		return M;
	}
};

void main()
{
	Solution sol;

	vector<vector<int>> M = { { 6, 7, 8 } };

	//vector<vector<int>> M = {{2, 3, 4},
	//						{5, 6, 7},
	//						{8, 9, 10},
	//						{11, 12, 13},
	//						{14, 15, 16}};

	vector<vector<int>> res = sol.imageSmoother(M);

	for (int i = 0; i < M.size(); ++i) {
		cout << "[";
		for (int j = 0; j < M[0].size(); ++j) {
			cout << " " << res[i][j] << " ";
		}
		cout << "]" << endl;
	}

	system("pause");
}