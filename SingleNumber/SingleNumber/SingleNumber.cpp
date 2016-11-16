#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		for (int i = 1; i < nums.size(); ++i)
		{
			nums[0] ^= nums[i];
		}

		return nums[0];
	}
};

void main()
{
	Solution sol;

	vector<int> nums(5);
	nums[0] = 2;
	nums[1] = 1;
	nums[2] = 1;
	nums[3] = 7;
	nums[4] = 2;

	cout << sol.singleNumber(nums) << endl;

	system("pause");
}