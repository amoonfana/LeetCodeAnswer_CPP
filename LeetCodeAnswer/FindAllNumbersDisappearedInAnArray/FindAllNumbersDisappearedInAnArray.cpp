#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> res;

		int idx;
		for (int i = 0; i < n; ++i)
		{
			idx = abs(nums[i]) - 1;
			if (nums[idx] > 0)
			{
				nums[idx] = -nums[idx];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (nums[i] > 0)
			{
				res.push_back(i + 1);
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> nums(8);
	vector<int> res;

	nums[0] = 4;
	nums[1] = 3;
	nums[2] = 2;
	nums[3] = 7;
	nums[4] = 8;
	nums[5] = 2;
	nums[6] = 3;
	nums[7] = 1;

	res = sol.findDisappearedNumbers(nums);

	system("pause");
}