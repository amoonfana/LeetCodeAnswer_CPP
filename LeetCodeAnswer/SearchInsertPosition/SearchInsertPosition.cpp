#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, h = nums.size();

		for (int i = (l + h) / 2; l < h; i = (l + h) / 2) {
			if (nums[i] >= target) { h = i; }
			else { l = i + 1; }
		}

		return l;
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 1, 3, 5, 6 };

	cout << sol.searchInsert(nums, 7) << endl;

	system("pause");
}
