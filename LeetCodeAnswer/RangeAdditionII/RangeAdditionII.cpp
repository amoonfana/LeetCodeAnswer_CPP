#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		for (int i = 0; i < ops.size(); ++i) {
			m = min(m, ops[i][0]);
			n = min(n, ops[i][1]);
		}

		return m*n;
	}
};

void main()
{
	Solution sol;

	vector<vector<int>> ops = {{2, 2}, {3, 3}};

	cout << sol.maxCount(2, 2, ops) << endl;

	system("pause");
}