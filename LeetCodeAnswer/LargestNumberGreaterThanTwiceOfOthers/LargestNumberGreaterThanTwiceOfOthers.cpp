#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int max1 = INT_MIN, max2 = INT_MIN, i1 = -1;

		for (int i = 0; i < nums.size(); ++i) {
			if (max2 < nums[i]) { max2 = nums[i]; }

			if (max1 < max2) {
				int mt = max1;
				max1 = max2;
				max2 = mt;
				
				i1 = i;
			}
		}

		if (2 * max2 > max1) { return -1; }
		else { return i1; }
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 3, 6, 1, 0 };

	cout << sol.dominantIndex(nums) << endl;

	system("pause");
}