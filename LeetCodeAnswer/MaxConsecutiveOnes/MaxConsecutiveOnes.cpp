#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int res = 0;
		int tRes = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 1) { tRes += 1; }
			else { tRes = 0; }

			if (res < tRes) { res = tRes; }
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> nums;

	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);

	cout << sol.findMaxConsecutiveOnes(nums) << endl;

	system("pause");
}