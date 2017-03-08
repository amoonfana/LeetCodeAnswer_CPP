#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;

		for (int i = 0; (i + 1) < prices.size(); ++i)
		{
			if (prices[i + 1] > prices[i])
			{
				res += prices[i + 1] - prices[i];
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> prices;
	
	//prices.push_back(0);
	//prices.push_back(1);
	//prices.push_back(3);

	cout << sol.maxProfit(prices) << endl;

	system("pause");
}