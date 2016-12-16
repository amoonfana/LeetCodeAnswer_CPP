#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int n = nums.size();
		unordered_set<int> us(n);


		for (int i = 0; i < n; ++i)
		{
			if (us.count(nums[i]) > 0)
			{
				return true;
			}

			us.insert(nums[i]);
		}

		return false;
	}
};

void main()
{
	Solution sol;

	vector<int> nums(5);

	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 3;
	nums[4] = 4;

	cout << sol.containsDuplicate(nums) << endl;

	system("pause");
}