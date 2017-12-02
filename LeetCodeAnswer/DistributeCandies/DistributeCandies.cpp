#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int n = candies.size();
		bitset<200001> bset;

		for (int i = 0; i < n; ++i) { bset[candies[i] + 100000] = 1; }

		return min(bset.count(), candies.size() >> 1);
	}
};

void main()
{
	Solution sol;

	vector<int> candies;
	candies.push_back(1);
	candies.push_back(1);
	candies.push_back(2);
	candies.push_back(3);

	cout << sol.distributeCandies(candies) << endl;

	system("pause");
}