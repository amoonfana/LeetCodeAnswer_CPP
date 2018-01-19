#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	////Sort
	//int findLHS(vector<int>& nums) {
	//	int max = -1;
	//	sort(nums.begin(), nums.end());

	//	for (int s = 0, e = 0; (e < nums.size() && s < nums.size()); (nums[e] - nums[s] > 1 ? ++s : ++e)) {
	//		if (nums[e] - nums[s] == 1) {
	//			int len = e - s;
	//			if (max < len) { max = len; }
	//		}
	//	}

	//	return max + 1;
	//}

	//HashMap
	int findLHS(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); ++i) { um[nums[i]] += 1; }
		
		for (pair<int, int> p : um) {
			if (um.count(p.first + 1)) {
				res = max(res, p.second + um[p.first + 1]);
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> nums = { 1,3,2,2,5,2,3,7 };

	cout << sol.findLHS(nums) << endl;

	system("pause");
}