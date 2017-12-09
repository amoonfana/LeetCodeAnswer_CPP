#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int n = nums.size(), m = nums[0].size();
		int size = n * m;

		if (size != r * c) { return nums; }

		vector<vector<int>> res(r, vector<int>(c));
		for (int i = 0; i < size; i++) {
			res[i/c][i%c] = nums[i/m][i%m];
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<vector<int>> nums(2);
	nums[0].push_back(1);
	nums[0].push_back(2);
	nums[1].push_back(3);
	nums[1].push_back(4);

	nums = sol.matrixReshape(nums, 1, 4);

	cout << "[";
	for (int i = 0; i < nums.size(); ++i) {
		cout << "[";
		for (int j = 0; j < nums[i].size(); ++j) {
			cout << nums[i][j] << " ";
		}
		cout << "]";
	}
	cout << "]";

	system("pause");
}