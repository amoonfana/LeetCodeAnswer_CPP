#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int n = nums.size();
		int res = 0;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i += 2) { res += nums[i]; }

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);

	cout << sol.arrayPairSum(nums) << endl;

	system("pause");
}