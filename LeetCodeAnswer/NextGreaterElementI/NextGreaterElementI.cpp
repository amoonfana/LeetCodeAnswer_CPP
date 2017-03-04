#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> res(findNums.size());
		if (findNums.empty() || nums.empty())
		{
			return res;
		}

		//Build hash table
		unordered_map<int, int> tbl;
		stack<int> stk;

		stk.push(nums[0]);
		for (int i = 1; i< nums.size(); ++i)
		{
			while (!stk.empty() && stk.top() < nums[i])
			{
				tbl[stk.top()] = nums[i];
				stk.pop();
			}

			stk.push(nums[i]);
		}

		//Get result
		for (int i = 0; i < findNums.size(); ++i)
		{
			res[i] = tbl.count(findNums[i]) ? tbl[findNums[i]] : -1;
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> findNums, nums;

	findNums.push_back(2);
	findNums.push_back(4);
	//findNums.push_back(2);

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	vector<int> res = sol.nextGreaterElement(findNums, nums);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
}