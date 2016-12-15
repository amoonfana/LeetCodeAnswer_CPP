#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major, counts = 0, n = nums.size();

		for (int i = 0; i < n; ++i)
		{
			if (counts == 0)
			{
				major = nums[i];
				counts = 1;
			}
			else
			{
				counts += (nums[i] == major) ? 1 : -1;
			}
		}

		return major;
	}
};

void main()
{
	Solution sol;

	vector<int> nums(5);

	nums[0] = 3;
	nums[1] = 1;
	nums[2] = 3;
	nums[3] = 1;
	nums[4] = 3;

	cout << sol.majorityElement(nums) << endl;

	system("pause");
}