#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		for (int i = 2; i < cost.size(); ++i) { cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]); }
		return min(cost[cost.size() - 1], cost[cost.size() - 2]);
	}
};

void main()
{
	Solution sol;

	vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };

	cout << sol.minCostClimbingStairs(cost) << endl;

	system("pause");
}