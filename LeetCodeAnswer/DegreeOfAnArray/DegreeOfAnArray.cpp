#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		int result = INT_MAX, degree = INT_MIN;
		unordered_map<int, pair<int, int>> um;

		for (int i = 0; i < nums.size(); ++i) {
			pair<int, int>& j = um[nums[i]];

			if (j.second++ == 0) { j.first = i; }

			if (j.second > degree) {
				degree = j.second;
				result = i - j.first + 1;
			}
			else if (j.second == degree) {
				result = min(result, i - j.first + 1);
			}
		}

		return result;
	}
};

void main()
{
	Solution sol;

	vector<int> nums = {1, 2, 2, 3, 1, 4, 2};

	cout << sol.findShortestSubArray(nums) << endl;

	system("pause");
}