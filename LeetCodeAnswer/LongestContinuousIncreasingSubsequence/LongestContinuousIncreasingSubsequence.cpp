#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty()) { return 0; }
		int c = 1, res = INT_MIN;

		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] < nums[i]) { c += 1; }
			else {
				if (res < c) { res = c; }
				c = 1;
			}
		}

		return max(res, c);
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 1, 3, 5, 4, 7 };

	cout << sol.findLengthOfLCIS(nums) << endl;

	system("pause");
}