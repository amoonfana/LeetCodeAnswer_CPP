#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		int n = nums.size();
		map<int, int> pq;

		for (int i = 0; i < n; ++i)
		{
			pq[nums[i]] = i;
		}

		vector<string> res(n);
		int r = n;
		for (map<int, int>::iterator it = pq.begin(); it != pq.end(); ++it)
		{
			if (r > 3)
			{
				res[it->second] = to_string(r);
			}
			else if (r == 3)
			{
				res[it->second] = "Bronze Medal";
			}
			else if (r == 2)
			{
				res[it->second] = "Silver Medal";
			}
			else if (r == 1)
			{
				res[it->second] = "Gold Medal";
			}

			--r;
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> nums;

	nums.push_back(10);
	nums.push_back(3);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(4);

	vector<string> res;
	res = sol.findRelativeRanks(nums);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i].c_str() << endl;
	}

	system("pause");
}