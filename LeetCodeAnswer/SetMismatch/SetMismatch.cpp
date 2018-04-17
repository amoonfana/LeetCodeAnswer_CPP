#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int n = nums.size() + 1;
		bool *ht = new bool[n]{false};
		ht[0] = true;
		vector<int> r(2);

		for (int i = 0; i < nums.size(); ++i) {
			if (ht[nums[i]] == false) { ht[nums[i]] = true; }
			else { r[0] = nums[i]; }
		}

		for (int i = 0; i < n; ++i) {
			if (ht[i] == false) {
				r[1] = i;
				break;
			}
		}

		return r;
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 1, 1 };

	vector<int> res = sol.findErrorNums(nums);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	system("pause");
}