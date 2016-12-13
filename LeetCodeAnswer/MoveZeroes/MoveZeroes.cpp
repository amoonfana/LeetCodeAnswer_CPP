#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		int n = nums.size();

		for (int i = 0; i < n; ++i)
		{
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}

		for (; j < n; ++j)
		{
			nums[j] = 0;
		}
	}
};

void main()
{
	Solution sol;

	vector<int> nums(5);

	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 0;
	nums[3] = 3;
	nums[4] = 12;

	sol.moveZeroes(nums);

	system("pause");
}