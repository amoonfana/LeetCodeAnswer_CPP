#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) { return 0; }
		int min = prices[0], res = 0;

		for (int i = 1; i < prices.size(); ++i) {
			int t = prices[i] - min;
			if (res < t) { res = t; }
			if (prices[i] < min) { min = prices[i]; }
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> prices = { 7, 1, 5, 3, 6, 4 };

	cout << sol.maxProfit(prices) << endl;

	system("pause");
}