#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int lo = 0, hi = numbers.size() - 1;

		while (numbers[lo] + numbers[hi] != target)
		{
			if (numbers[lo] + numbers[hi] < target)
			{
				lo++;
			}
			else
			{
				hi--;
			}
		}
		return vector<int>({ lo + 1,hi + 1 });
	}
};

void main()
{
	Solution sol;

	int target = 0;
	vector<int> nums;

	nums.push_back(-3);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(90);

	vector<int> res;
	res = sol.twoSum(nums, target);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
}