#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int sum = 0;
		int min = INT_MAX;
		int n = nums.size();

		for (int i = 0; i < n; i++)
		{
			if (min > nums[i])
			{
				sum += (min - nums[i]) * i;
				min = nums[i];
			}
			else
			{
				sum += nums[i] - min;
			}
		}
		return sum;
	}
};

void main()
{
	Solution sol;

	vector<int> nums(3);

	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;

	cout << sol.minMoves(nums) << endl;

	system("pause");
}