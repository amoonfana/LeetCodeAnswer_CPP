#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		////xor solution - slower
		//int xr = 0, i = 0;

		//for (; i < nums.size(); ++i) {
		//	xr = xr ^ i ^ nums[i];
		//}

		//return xr ^ i;

		//sum solution - faster
		int len = nums.size();
		int sum = (0 + len)*(len + 1)*0.5;

		for (int i = 0; i < len; i++)
		{
			sum -= nums[i];
		}

		return sum;
	}
};

void main()
{
	Solution sol;

	vector<int> nums;

	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(3);

	cout << sol.missingNumber(nums) << endl;

	system("pause");
}