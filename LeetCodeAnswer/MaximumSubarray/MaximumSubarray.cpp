#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int localMax = nums[0], globalMax = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			localMax = max(localMax + nums[i], nums[i]);
			globalMax = max(globalMax, localMax);
		}

		return globalMax;
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

	cout << sol.maxSubArray(nums) << endl;

	system("pause");
}