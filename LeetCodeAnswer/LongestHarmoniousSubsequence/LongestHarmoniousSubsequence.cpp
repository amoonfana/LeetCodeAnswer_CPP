#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLHS(vector<int>& nums) {
		int max = -1;
		sort(nums.begin(), nums.end());

		for (int s = 0, e = 0; (e < nums.size() && s < nums.size()); (nums[e] - nums[s] > 1 ? ++s : ++e)) {
			if (nums[e] - nums[s] == 1) {
				int len = e - s;
				if (max < len) { max = len; }
			}
		}

		return max + 1;
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 1,3,2,2,5,2,3,7 };

	cout << sol.findLHS(nums) << endl;

	system("pause");
}